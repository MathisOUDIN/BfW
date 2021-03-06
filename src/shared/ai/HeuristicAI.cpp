#include "HeuristicAI.h"
#include "state/House.h"
#include "Point.h"
#include "state/Unit.h"
#include "state/UnitTypeId.h"
#include "engine/AttackCommand.h"
#include "engine/MoveCommand.h"
#include "engine/EndTurnCommand.h"
#include "engine/HandleWinCommand.h"
#include "engine/SpawnCommand.h"

namespace ai {
    
    HeuristicAI::HeuristicAI() {

    }

    void HeuristicAI::initPathMaps(const state::Board& board) {
        const std::map<int, std::unique_ptr<state::Unit> >& units = board.getUnits();
        const std::map<int, std::shared_ptr<state::Terrain> >& terrains = board.getTerrains();

        unitTeam1PathMap.init(board);
        unitTeam2PathMap.init(board);
        houseTeam1PathMap.init(board);
        houseTeam2PathMap.init(board);
        castlePathMap.init(board);
        
        for (auto& u : units) {
            if (u.second->getTeam() == state::TeamId::TEAM_1) {
                unitTeam1PathMap.addWell(Point(u.second->getPositionX(), u.second->getPositionY()));
                unitTeam2PathMap.addWall(Point(u.second->getPositionX(), u.second->getPositionY()));
            } else if (u.second->getTeam() == state::TeamId::TEAM_2) {
                unitTeam2PathMap.addWell(Point(u.second->getPositionX(), u.second->getPositionY()));
                unitTeam1PathMap.addWall(Point(u.second->getPositionX(), u.second->getPositionY()));
            }
            houseTeam1PathMap.addWall(Point(u.second->getPositionX(), u.second->getPositionY()));
            houseTeam2PathMap.addWall(Point(u.second->getPositionX(), u.second->getPositionY()));
            castlePathMap.addWall(Point(u.second->getPositionX(), u.second->getPositionY()));
        }
        
        for (auto& t : terrains) {
            if (t.second->getTypeId() == state::TerrainTypeId::HOUSE) {
                switch (((state::House*)t.second.get())->getTeamId()) {
                    case state::TeamId::TEAM_1:
                        houseTeam1PathMap.addWell(Point(t.second->getPositionX(), t.second->getPositionY()));
                        break;
                    
                    case state::TeamId::TEAM_2:
                        houseTeam2PathMap.addWell(Point(t.second->getPositionX(), t.second->getPositionY()));
                        break;
                        
                    case state::TeamId::INVALID_TEAM:
                        houseTeam1PathMap.addWell(Point(t.second->getPositionX(), t.second->getPositionY()));
                        houseTeam2PathMap.addWell(Point(t.second->getPositionX(), t.second->getPositionY()));
                }
            } else if(t.second->getTypeId() == state::TerrainTypeId::CASTLE) {
                castlePathMap.addWell(Point(t.second->getPositionX(), t.second->getPositionY()));
            }
        }
        
        unitTeam1PathMap.update(board);
        unitTeam2PathMap.update(board);
        houseTeam1PathMap.update(board);
        houseTeam2PathMap.update(board);
        castlePathMap.update(board);
    }
    
    engine::Command* HeuristicAI::run(engine::Engine& engine, state::TeamId player) {
        if(engine.getState().getCurrentTeam() != player || player == state::TeamId::INVALID_TEAM) {
            return nullptr;
        }
        
        std::vector<engine::Command*> commandsAttack;
        std::vector<engine::Command*> commandsMovement;
        std::vector<engine::Command*> commandsSpawn;
        engine::Command* commandToReturn = nullptr;

        initPathMaps(engine.getState().getBoard());
        listCommandsAttack(engine.getState(), commandsAttack);
        listCommandsMovement(engine.getState(), commandsMovement);
        listCommandsSpawn(engine.getState(), commandsSpawn);

        switch (player) {
            case state::TeamId::TEAM_1:

                if (commandsSpawn.size() != 0) {
                    commandToReturn = commandsSpawn.front()->clone();
                    break;
                }
                
                if (commandsAttack.size() != 0) {
                    commandToReturn = commandsAttack.front()->clone();
                    break;
                }
                
                if (commandsMovement.size() != 0) {
                    state::Unit* unit = engine.getState().getBoard().findUnit(((engine::MoveCommand*)commandsMovement.front())->getIdUnit());
                    Point pointUnit(unit->getPositionX(), unit->getPositionY());
                    Point bestPoint;
                    unsigned int it;
                    
                    if(unitTeam2PathMap.getBestPoint(unit->getPositionX(), unit->getPositionY()).getWeight() <
                            houseTeam2PathMap.getBestPoint(unit->getPositionX(), unit->getPositionY()).getWeight()) {
                        bestPoint = unitTeam2PathMap.getBestPoint(unit->getPositionX(), unit->getPositionY());
                        
                    } else {
                        bestPoint = houseTeam2PathMap.getBestPoint(unit->getPositionX(), unit->getPositionY());
                    }

                    for (it = 0; it < commandsMovement.size(); it++) {
                        if (unit->getId() == ((engine::MoveCommand*)commandsMovement.at(it))->getIdUnit() && 
                                ((engine::MoveCommand*)commandsMovement.at(it))->getDirection() == bestPoint.transformToDirection(pointUnit)) {
                            commandToReturn = commandsMovement.at(it)->clone();
                            break;
                        }
                    }
                    
                    if (it == commandsMovement.size()) {
                        unit->setSpeed(0);
                    } else {
                        break;
                    }
                }

                commandToReturn = new engine::EndTurnCommand();
                break;
                
            case state::TeamId::TEAM_2:
                if (commandsSpawn.size() != 0) {
                    commandToReturn = commandsSpawn.front()->clone();
                    break;
                }
                if (commandsAttack.size() != 0) {
                    commandToReturn = commandsAttack.front()->clone();
                    break;
                }
                if (commandsMovement.size() != 0) {
                    state::Unit* unit = engine.getState().getBoard().findUnit(((engine::MoveCommand*)commandsMovement.front())->getIdUnit());
                    Point pointUnit(unit->getPositionX(), unit->getPositionY());
                    Point bestPoint;
                    unsigned int it;
                    
                    if(unitTeam1PathMap.getBestPoint(unit->getPositionX(), unit->getPositionY()).getWeight() <
                            houseTeam1PathMap.getBestPoint(unit->getPositionX(), unit->getPositionY()).getWeight()) {
                        bestPoint = unitTeam1PathMap.getBestPoint(unit->getPositionX(), unit->getPositionY());
                    } else {
                        bestPoint = houseTeam1PathMap.getBestPoint(unit->getPositionX(), unit->getPositionY());
                    }
                    
                    for (it = 0; it < commandsMovement.size(); it++) {
                        if (unit->getId() == ((engine::MoveCommand*)commandsMovement.at(it))->getIdUnit() && 
                                ((engine::MoveCommand*)commandsMovement.at(it))->getDirection() == bestPoint.transformToDirection(pointUnit)) {
                            commandToReturn = commandsMovement.at(it)->clone();
                            break;
                        }
                    }
                    if (it == commandsMovement.size()) {
                        unit->setSpeed(0);
                    }
                    
                    if (it == commandsMovement.size()) {
                        unit->setSpeed(0);
                    } else {
                        break;
                    }
                }

                commandToReturn = new engine::EndTurnCommand();
                break;
            
            case state::TeamId::INVALID_TEAM:
                break;
        }
        
        for(auto& c : commandsAttack) {
            delete  c;
        }
        
        for(auto& c : commandsMovement) {
            delete  c;
        }
        
        for(auto& c : commandsSpawn) {
            delete  c;
        }        
        
        return commandToReturn;
    }
    
    const PathMap& HeuristicAI::getHouseTeam1PathMap() const {
        return houseTeam1PathMap;
    }

    const PathMap& HeuristicAI::getHouseTeam2PathMap() const {
        return houseTeam2PathMap;
    }

    const PathMap& HeuristicAI::getUnitTeam1PathMap() const {
        return unitTeam1PathMap;
    }

    const PathMap& HeuristicAI::getUnitTeam2PathMap() const {
        return unitTeam2PathMap;
    }

    const PathMap& HeuristicAI::getCastlePathMap() const {
        return castlePathMap;
    }
    
}
