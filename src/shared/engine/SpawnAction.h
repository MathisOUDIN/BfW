// Generated by dia2code
#ifndef ENGINE__SPAWNACTION__H
#define ENGINE__SPAWNACTION__H


namespace state {
  class State;
};
namespace engine {
  class Action;
}

#include "state/UnitTypeId.h"
#include "state/TeamId.h"
#include "Action.h"

namespace engine {

  /// class SpawnAction - 
  class SpawnAction : public engine::Action {
    // Attributes
  protected:
    int x;
    int y;
    int idUnit;
    state::UnitTypeId unitTypeId;
    state::TeamId teamId;
    int spawnUnitId;
    int teamGold;
    // Operations
  public:
    SpawnAction (int x, int y, state::UnitTypeId unitTypeId, state::TeamId teamId);
    void apply (state::State& state);
    void undo (state::State& state);
    // Setters and Getters
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getIdUnit() const;
    void setIdUnit(int idUnit);
    state::UnitTypeId getUnitTypeId() const;
    void setUnitTypeId(state::UnitTypeId unitTypeId);
    state::TeamId getTeamId() const;
    void setTeamId(state::TeamId teamId);
    int getSpawnUnitId() const;
    void setSpawnUnitId(int spawnUnitId);
    int getTeamGold() const;
    void setTeamGold(int teamGold);
  };

};

#endif
