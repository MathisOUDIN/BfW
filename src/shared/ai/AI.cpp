#include "AI.h"
#include "RandomAI.h"
#include "engine/MoveCommand.h"
#include "engine/AttackCommand.h"
#include "engine/SpawnCommand.h"
#include "engine/EndTurnCommand.h"


#include <iostream>
namespace ai {

    void AI::listCommandsMovement(const state::State& state, state::TeamId teamId, std::vector<engine::Command*>& commands) {
        std::vector<state::Unit*> units = state.getBoard().findUnitsByTeam(teamId);
        std::vector<state::Direction> directions;
        
        commands.clear();
        
        for (auto u : units) {
            directions = state.getBoard().directionAvailable(u->getId());

            for(state::Direction d : directions) {
                commands.push_back(new engine::MoveCommand(u->getId(), d));
            }
        }
    }
    
    void AI::listCommandsSpawn(const state::State& state, state::TeamId teamId, std::vector<engine::Command*>& commands) {
        std::vector<state::Unit*> units = state.getBoard().findUnitsByTeam(teamId);
        
        commands.clear();
    
        for (auto u : units) { 
            if(u->getTypeId() == state::UnitTypeId::LEADER) {
                if(state.getBoard().findTeam(u->getTeam())->verifyGold(state::UnitTypeId::SWORDMAN) && 
                        state.getBoard().findTerrainOnPosition(u->getPositionX(), u->getPositionY())->getTypeId() == state::TerrainTypeId::CASTLE) {
                    commands.push_back(new engine::SpawnCommand(u->getPositionX(), u->getPositionY(), state::UnitTypeId::SWORDMAN));
                }

                if(state.getBoard().findTeam(u->getTeam())->verifyGold(state::UnitTypeId::BOWMAN) && 
                        state.getBoard().findTerrainOnPosition(u->getPositionX(), u->getPositionY())->getTypeId() == state::TerrainTypeId::CASTLE) {
                    commands.push_back(new engine::SpawnCommand(u->getPositionX(), u->getPositionY(), state::UnitTypeId::BOWMAN));
                }
                
                break;
            }
        }
    }
    
    void AI::listCommandsAttack(const state::State& state, state::TeamId teamId, std::vector<engine::Command*>& commands) {
//        std::vector<state::Unit*> units = state.getBoard().findUnitsByTeam(teamId);
//        std::vector<state::Unit*> unitsAround;
//        
//        commands.clear();
//        
//        for (auto u : units) {
//            unitsAround = state.getBoard().findUnitsAround(u->getId());
//
//            for(auto uAround : unitsAround) {
//                if(uAround)->getTeam() != u->getTeam()) {
//                    for(auto& w : u->getWeapons()) {
//                        commands.push_back(new engine::AttackCommand(u->getId(), uAround, w.second.get()->getTypeId()));
//                    }
//                }
//            }
//        }
    }

    void AI::listCommands(const state::State& state, std::vector<engine::Command*>& commands) {
        std::vector<state::Direction> directions;
        std::vector<int> unitsAround;
        
        commands.clear();
                
        for(auto& u : state.getBoard().getUnits()) {
            if(u.second->getTeam() == state.getCurrentTeam()) {
                directions = state.getBoard().directionAvailable(u.second->getId());
                
                for(state::Direction d : directions) {
                    commands.push_back(new engine::MoveCommand(u.second->getId(), d));
                }
                
                unitsAround = state.getBoard().findIdUnitsAround(u.second->getId());
                
                for(auto& uAround : unitsAround) {
                    if(state.getBoard().findUnit(uAround)->getTeam() != u.second->getTeam()) {
                        for(auto& w : u.second->getWeapons()) {
                            commands.push_back(new engine::AttackCommand(u.second->getId(), uAround, w.second.get()->getTypeId()));
                        }
                    }
                }
                
                if(u.second->getTypeId() == state::UnitTypeId::LEADER) {
                    if(state.getBoard().findTeam(u.second->getTeam())->verifyGold(state::UnitTypeId::SWORDMAN) && state.getBoard().findTerrainOnPosition(u.second->getPositionX(), u.second->getPositionY())->getTypeId() == state::TerrainTypeId::CASTLE) {
                        commands.push_back(new engine::SpawnCommand(u.second->getPositionX(), u.second->getPositionY(), state::UnitTypeId::SWORDMAN));
                    }
                    
                    if(state.getBoard().findTeam(u.second->getTeam())->verifyGold(state::UnitTypeId::BOWMAN) && state.getBoard().findTerrainOnPosition(u.second->getPositionX(), u.second->getPositionY())->getTypeId() == state::TerrainTypeId::CASTLE) {
                        commands.push_back(new engine::SpawnCommand(u.second->getPositionX(), u.second->getPositionY(), state::UnitTypeId::BOWMAN));
                    }
                }
            }
        }
    }    
    
    AI::~AI() {

    }

}
