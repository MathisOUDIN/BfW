// Generated by dia2code
#ifndef ENGINE__HANDLEWINCOMMAND__H
#define ENGINE__HANDLEWINCOMMAND__H

#include <stack>
#include <memory>
#include <json/json.h>

namespace state {
  class State;
};
namespace engine {
  class Action;
  class Command;
  class HandleWinCommand;
}

#include "CommandTypeId.h"
#include "Action.h"
#include "Command.h"
#include "state/TeamId.h"

namespace engine {

  /// class HandleWinCommand - 
  class HandleWinCommand : public engine::Command {
    // Associations
    // Operations
  public:
    HandleWinCommand ();
    CommandTypeId getTypeId () const;
    void execute (state::State& state, std::stack<std::shared_ptr<Action>>& actions);
    Command* clone () const;
    void serialize (Json::Value& out) const;
    static HandleWinCommand* deserialize (const Json::Value& in);
    // Setters and Getters
  };

};

#endif
