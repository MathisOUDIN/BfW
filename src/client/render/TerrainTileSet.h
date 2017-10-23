// Generated by dia2code
#ifndef RENDER__TERRAINTILESET__H
#define RENDER__TERRAINTILESET__H

#include <map>
#include <string>

namespace render {
  class Tile;
};
namespace state {
  class Terrain;
};
namespace render {
  class TileSet;
}

#include "TileSet.h"
#include "TerrainType.h"

namespace render {

  /// class TerrainTileSet - 
  class TerrainTileSet : public render::TileSet {
    // Associations
    // Attributes
  private:
    std::map<TerrainType,Tile> terrains;
    // Operations
  public:
    TerrainTileSet ();
    /// 			
    int getCellWidth () const;
    int getCellHeight () const;
    const std::string getImageFile () const;
    const Tile& getTile (const state::Terrain& terrain) const;
    // Setters and Getters
  };

};

#endif
