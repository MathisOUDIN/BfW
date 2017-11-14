// Generated by dia2code
#ifndef STATE__LEADER__H
#define STATE__LEADER__H


namespace state {
  class Unit;
}

#include "TeamId.h"
#include "RaceTypeId.h"
#include "Unit.h"

namespace state {

  /// class Leader - 
  class Leader : public state::Unit {
    // Operations
  public:
    Leader (TeamId team, int positionX = 0, int positionY = 0, RaceTypeId race = RaceTypeId::HUMAN);
    Unit* clone () const;
    // Setters and Getters
  };

};

#endif
