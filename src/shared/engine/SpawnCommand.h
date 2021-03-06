// Generated by dia2code
#ifndef ENGINE__SPAWNCOMMAND__H
#define ENGINE__SPAWNCOMMAND__H

#include <stack>
#include <memory>
#include <json/json.h>

namespace state {
  class State;
};
namespace engine {
  class Action;
  class Command;
  class SpawnCommand;
}

#include "state/UnitTypeId.h"
#include "Action.h"
#include "CommandTypeId.h"
#include "Command.h"
#include "state/TerrainTypeId.h"

namespace engine {

  /// class SpawnCommand - 
  class SpawnCommand : public engine::Command {
    // Associations
    // Attributes
  protected:
    int x;
    int y;
    state::UnitTypeId unitTypeId;
    // Operations
  public:
    SpawnCommand (int x, int y, state::UnitTypeId unitTypeId);
    void spawnUnit (state::State& state, int x, int y, state::UnitTypeId unitTypeId, std::stack<std::shared_ptr<Action>>& acions);
    CommandTypeId getTypeId () const;
    void execute (state::State& state, std::stack<std::shared_ptr<Action>>& actions);
    Command* clone () const;
    void serialize (Json::Value& out) const;
    static SpawnCommand* deserialize (const Json::Value& in);
    // Setters and Getters
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    state::UnitTypeId getUnitTypeId() const;
    void setUnitTypeId(state::UnitTypeId unitTypeId);
  };

};

#endif
