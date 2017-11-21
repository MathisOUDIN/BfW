// Generated by dia2code
#ifndef AI__AI__H
#define AI__AI__H

#include <vector>

namespace engine {
  class Engine;
};
namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "engine/Engine.h"
#include "engine/Command.h"
#include "state/State.h"

namespace ai {

  /// class AI - 
  class AI {
    // Operations
  public:
    virtual ~AI ();
    virtual void run (engine::Engine& engine) = 0;
  protected:
    std::vector<engine::Command*> listCommands (const state::State& state);
    // Setters and Getters
  };

};

#endif
