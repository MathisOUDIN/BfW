// Generated by dia2code
#ifndef STATE__BOARD__H
#define STATE__BOARD__H

#include <map>
#include <memory>
#include <vector>
#include <string>

namespace state {
  class Board;
  class Unit;
  class Team;
  class Terrain;
}

#include "Unit.h"
#include "Team.h"
#include "Terrain.h"

namespace state {

  /// class Board - 
  class Board {
    // Associations
    // Attributes
  private:
    /// 	
    int width;
    int height;
    std::map<int, std::unique_ptr<Team>> teams;
    std::map<int, std::unique_ptr<Terrain>> terrains;
    std::map<int, std::unique_ptr<Unit>> units;
    // Operations
  public:
    Board (int width = 10, int height = 10);
    Board (const Board& other);
    Board& operator= (const Board& other);
    ~Board ();
    void addUnit (Unit* unit);
    /// 	
    /// @param team		(???) 
    void addTeam (Team* team);
    /// 		
    /// @param terrain		(???) 
    void addTerrain (Terrain* terrain);
    Unit* findUnit (int id) const;
    Team* findTeam (int id) const;
    /// 		
    /// @param id		(???) 
    Terrain* findTerrain (int id) const;
    std::vector<Unit*> findUnitAround (int positionX, int positionY);
    Unit* findUnitOnPosition (int positionX, int positionY) const;
    Terrain* findTerrainOnPosition (int positionX, int positionY) const;
    int getHeight () const;
    int getWidth () const;
    const std::map<int, std::unique_ptr<Team> >& getTeams () const;
    const std::map<int, std::unique_ptr<Terrain> >& getTerrains () const;
    const std::map<int, std::unique_ptr<Unit> >& getUnits () const;
    void loadTerrainsFromFile (std::string path) const;
    // Setters and Getters
  };

};

#endif