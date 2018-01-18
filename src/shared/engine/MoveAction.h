// Generated by dia2code
#ifndef ENGINE__MOVEACTION__H
#define ENGINE__MOVEACTION__H


namespace state {
  class State;
};
namespace engine {
  class Action;
}

#include "state/Direction.h"
#include "state/TeamId.h"
#include "Action.h"

namespace engine {

  /// class MoveAction - 
  class MoveAction : public engine::Action {
    // Associations
    // Attributes
  protected:
    int idUnit;
    int speed;
    state::Direction direction;
    state::TeamId houseTeamId     = state::TeamId::INVALID_TEAM;
    // Operations
  public:
    MoveAction (int idUnit, state::Direction direction, int speed);
    void apply (state::State& state);
    void undo (state::State& state);
    // Setters and Getters
    int getIdUnit() const;
    void setIdUnit(int idUnit);
    int getSpeed() const;
    void setSpeed(int speed);
    state::Direction getDirection() const;
    void setDirection(state::Direction direction);
    state::TeamId getHouseTeamId() const;
    void setHouseTeamId(state::TeamId houseTeamId);
  };

};

#endif
