// Generated by dia2code
#ifndef STATE__BOWMAN__H
#define STATE__BOWMAN__H


namespace state {
  class Unit;
}

#include "Unit.h"

namespace state {

  /// class Bowman - 
  class Bowman : public state::Unit {
    // Operations
  public:
    Bowman (int id, int team, int positionX = 0, int positionY = 0);
    Unit* clone () const;
    // Setters and Getters
  };

};

#endif