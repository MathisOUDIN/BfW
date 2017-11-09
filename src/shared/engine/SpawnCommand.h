// Generated by dia2code
#ifndef ENGINE__SPAWNCOMMAND__H
#define ENGINE__SPAWNCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "state/UnitTypeId.h"
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
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
  private:
    void spawnUnit (state::State& state, int x, int y, state::UnitTypeId unitTypeId);
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