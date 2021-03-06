#include "SpawnCommand.h"
#include "SpawnAction.h"
#include "json/json.h"

namespace engine {

    SpawnCommand::SpawnCommand(int x, int y, state::UnitTypeId unitTypeId): x(x), y(y), unitTypeId(unitTypeId) {

    }
   
    void SpawnCommand::spawnUnit(state::State& state, int x, int y, state::UnitTypeId unitTypeId, std::stack<std::shared_ptr<Action>>& actions ) {
        if(state.getBoard().findUnitOnPosition(x, y)->getTeam() == state.getCurrentTeam()) {
            if(state.getBoard().findTeam(state.getBoard().findUnitOnPosition(x, y)->getTeam())->verifyGold(unitTypeId) && unitTypeId != state::UnitTypeId::LEADER) {
                if (state.getBoard().findTerrainOnPosition(x, y)->getTypeId() == state::TerrainTypeId::CASTLE &&
                        state.getBoard().findUnitOnPosition(x, y)->getTypeId() == state::UnitTypeId::LEADER) {
                    if (!state.getBoard().isUnitOnPosition(x - 1, y - 1)) {
                        std::shared_ptr<Action> action(new SpawnAction(x - 1, y - 1, unitTypeId, state.getBoard().findUnitOnPosition(x, y)->getTeam()));
                        actions.push(action);
                        action->apply(state);
                        
                    } else if (!state.getBoard().isUnitOnPosition(x, y - 2)) {
                        std::shared_ptr<Action> action(new SpawnAction(x, y - 2, unitTypeId, state.getBoard().findUnitOnPosition(x, y)->getTeam()));
                        actions.push(action);
                        action->apply(state);
                        
                    } else if (!state.getBoard().isUnitOnPosition(x + 1, y - 1)) {
                        std::shared_ptr<Action> action(new SpawnAction(x + 1, y - 1, unitTypeId, state.getBoard().findUnitOnPosition(x, y)->getTeam()));
                        actions.push(action);
                        action->apply(state);
                    }
                }
            }
        }
    }

    void SpawnCommand::execute(state::State& state, std::stack<std::shared_ptr<Action>>& actions) {
        spawnUnit(state, x, y, unitTypeId, actions);
    }

    CommandTypeId SpawnCommand::getTypeId() const {
        return CommandTypeId::SPAWN;
    }

    state::UnitTypeId SpawnCommand::getUnitTypeId() const {
        return unitTypeId;
    }

    int SpawnCommand::getX() const {
        return x;
    }

    int SpawnCommand::getY() const {
        return y;
    }

    Command* SpawnCommand::clone() const {
        return new SpawnCommand(*this);
    }

    void SpawnCommand::serialize(Json::Value& out) const {
        Json::Value jsonCommand;

        jsonCommand["Type"] = "SpawnCommand";
        jsonCommand["x"] = x;
        jsonCommand["y"] = y;
        
        switch (unitTypeId) {
            case state::UnitTypeId::INVALID_UNIT:
                jsonCommand["UnitTypeId"] = "INVALID_UNIT";
                break;
            case state::UnitTypeId::LEADER:
                jsonCommand["UnitTypeId"] = "LEADER";
                break;
            case state::UnitTypeId::SWORDMAN:
                jsonCommand["UnitTypeId"] = "SWORDMAN";
                break;
            case state::UnitTypeId::BOWMAN:
                jsonCommand["UnitTypeId"] = "BOWMAN";
                break;
        }        
        
        out["Commands"].append(jsonCommand);
    }

    SpawnCommand* SpawnCommand::deserialize(const Json::Value& in) {
        int x;
        int y;
        state::UnitTypeId unitTypeId;
        
        x = in["x"].asInt();
        y = in["y"].asInt();
        
        if(in["UnitTypeId"].asString() == "LEADER") {
            unitTypeId = state::UnitTypeId::LEADER;
        } else if(in["UnitTypeId"].asString() == "SWORDMAN") {
            unitTypeId = state::UnitTypeId::SWORDMAN;
        } else if(in["UnitTypeId"].asString() == "BOWMAN") {
            unitTypeId = state::UnitTypeId::BOWMAN;
        } else {
            unitTypeId = state::UnitTypeId::INVALID_UNIT;
        }        
        
        return new SpawnCommand(x, y, unitTypeId);
    }

}
