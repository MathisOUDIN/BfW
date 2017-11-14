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
  class Observable;
}

#include "UnitTypeId.h"
#include "TeamId.h"
#include "Direction.h"
#include "Observable.h"
#include "Team.h"
#include "Terrain.h"
#include "RaceTypeId.h"
#include "Unit.h"

namespace state {

  /// class Board - 
  class Board : public state::Observable {
    // Associations
    // Attributes
  private:
    /// 	
    int width;
    int height;
    std::map<TeamId, std::unique_ptr<Team>> teams;
    std::map<int, std::unique_ptr<Terrain>> terrains;
    std::map<int, std::unique_ptr<Unit>> units;
    static int idTerrain;
    static int idUnit;
    // Operations
  public:
    Board (int width = 10, int height = 10);
    Board (const Board& other);
    Board& operator= (const Board& other);
    ~Board ();
    void addUnit (Unit* unit);
    void createNewUnit (UnitTypeId unitTypeId, TeamId team, int x, int y);
    /// 	
    /// @param team		(???) 
    void addTeam (Team* team);
    /// 		
    /// @param terrain		(???) 
    void addTerrain (Terrain* terrain);
    void deleteUnit (int id);
    bool isUnitAround (int idAttacker, int idDefender);
    bool isUnitOnPosition (int x, int y) const;
    Unit* findUnit (int id) const;
    Team* findTeam (TeamId id) const;
    /// 		
    /// @param id		(???) 
    Terrain* findTerrain (int id) const;
    std::vector<int> findIdUnitAround (int id) const;
    Unit* findUnitOnPosition (int positionX, int positionY) const;
    std::vector<int> findIdTerrainAround (int id) const;
    std::vector<Terrain*> findTerrainAround (int id) const;
    Terrain* findTerrainOnPosition (int positionX, int positionY) const;
    std::vector<Direction> directionAvailable (int unitId) const;
    void moveUnit (int id, Direction direction);
    int getHeight () const;
    int getWidth () const;
    const std::map<TeamId, std::unique_ptr<Team> >& getTeams () const;
    const std::map<int, std::unique_ptr<Terrain> >& getTerrains () const;
    const std::map<int, std::unique_ptr<Unit> >& getUnits () const;
    void loadTerrainsFromFile (std::string path);
    // Setters and Getters
  };

};

#endif
