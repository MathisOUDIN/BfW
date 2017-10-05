// Generated by dia2code
#ifndef STATE__WALL__H
#define STATE__WALL__H


namespace state {
  class Terrain;
}

#include "Orientation.h"
#include "Terrain.h"

namespace state {

  /// class Wall - 
  class Wall : public state::Terrain {
    // Associations
    // Attributes
  private:
    /// 					
    Orientation orientation     = Orientation::LEFT;
    // Operations
  public:
    Wall (int id, int positionX = 0, int positionY = 0);
    void setOrientation (Orientation orientation);
    Orientation getOrientation () const;
    Terrain* clone () const;
    // Setters and Getters
  };

};

#endif
