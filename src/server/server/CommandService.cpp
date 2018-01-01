#include "CommandService.h"

#include "ServiceException.h"
#include "engine/HandleWinCommand.h"
#include "engine/MoveCommand.h"
#include "engine/AttackCommand.h"
#include "engine/SpawnCommand.h"
#include "engine/LoadCommand.h"
#include "engine/EndTurnCommand.h"

namespace server {

    CommandService::CommandService(engine::Engine& engine) : AbstractService("/command"), engine(engine) {

    }

    HttpStatus CommandService::get(Json::Value& out, int id) const {
        if(id <= engine.getState().getEpoch()) {
            Json::Value jsonCommands;
            Json::Value commandHistory = engine.getCommandHistory();

            if(!commandHistory.empty()) {        
                for(unsigned int i = 0; i < commandHistory["Commands"].size(); i++) {
                    jsonCommands = commandHistory["Commands"][i];

                    if(jsonCommands["epoch"].isInt() && jsonCommands["epoch"].asInt() == id) {
                        out["Commands"].append(jsonCommands);
                    } else if(jsonCommands["epoch"].asInt() > id) {
                        break;
                    }
                }
            }
            
            return HttpStatus::OK;
            
        } else {
            throw ServiceException(HttpStatus::NOT_FOUND, "Not found");
                
            return HttpStatus::NOT_FOUND;            
        }
    }

    HttpStatus CommandService::post(Json::Value& out, const Json::Value& in) {
        Json::Value jsonCommands;
        
        if(!in.empty()) {    
            for(unsigned int i = 0; i < in["Commands"].size(); i++) {
            jsonCommands = in["Commands"][i];

                if(jsonCommands.isMember("Type") && jsonCommands.isMember("priority")) {
                    if(jsonCommands["Type"].isString() && jsonCommands["priority"].isInt()) {
                        if(jsonCommands["Type"] == "HandleWinCommand") {
                            engine.addCommand(jsonCommands["priority"].asInt(), engine::HandleWinCommand::deserialize(jsonCommands));
                        } else if(jsonCommands["Type"] == "EndTurnCommand") {
                            engine.addCommand(jsonCommands["priority"].asInt(), engine::EndTurnCommand::deserialize(jsonCommands));
                        } else if(jsonCommands["Type"] == "MoveCommand") {
                            engine.addCommand(jsonCommands["priority"].asInt(), engine::MoveCommand::deserialize(jsonCommands));
                        } else if(jsonCommands["Type"] == "AttackCommand") {
                            engine.addCommand(jsonCommands["priority"].asInt(), engine::AttackCommand::deserialize(jsonCommands));
                        } else if(jsonCommands["Type"] == "SpawnCommand") {
                            engine.addCommand(jsonCommands["priority"].asInt(), engine::SpawnCommand::deserialize(jsonCommands));
                        } else if(jsonCommands["Type"] == "LoadCommand") {
                            engine.addCommand(jsonCommands["priority"].asInt(), engine::LoadCommand::deserialize(jsonCommands));
                        }
                    }
                }
            }
        }

        out["epoch"] = engine.getState().getEpoch();
        
        return HttpStatus::CREATED;
    }

}

