// Generated by dia2code
#ifndef STATE__TEAM__H
#define STATE__TEAM__H


namespace state {
  class Team;
}

#include "RaceTypeId.h"
#include "UnitTypeId.h"

namespace state {

  /// class Team - 
  class Team {
    // Attributes
  private:
    int id     = 0;
    int gold     = 50;
    int nbHouses     = 0;
    RaceTypeId race     = RaceTypeId::HUMAN;
    // Operations
  public:
    Team ();
    int getId () const;
    int getGold () const;
    const RaceTypeId& getRace () const;
    void setId (int id);
    bool verifyGold (UnitTypeId unitTypeId) const;
    void generateGold ();
    void addHouse ();
    void removeHouse ();
    Team* clone () const;
    // Setters and Getters
  };

};

#endif
