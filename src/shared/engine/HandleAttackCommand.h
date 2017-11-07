// Generated by dia2code
#ifndef ENGINE__HANDLEATTACKCOMMAND__H
#define ENGINE__HANDLEATTACKCOMMAND__H

#include <vector>

namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class HandleAttackCommand - 
  class HandleAttackCommand : public engine::Command {
    // Operations
  public:
    std::vector<int> listUnitCanBeAttacked (state::State& state, int idUnit);
    /// 		
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
  private:
    void attackUnit (state::State& state, int idUnitAttacker, int idUnitDefender);
    /// 	
    /// @param state		(???) 
    /// @param idUnit		(???) 
    void killUnit (state::State& state, int idUnit);
    // Setters and Getters
  };

};

#endif
