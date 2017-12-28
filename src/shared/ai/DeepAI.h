// Generated by dia2code
#ifndef AI__DEEPAI__H
#define AI__DEEPAI__H

#include <random>
#include <vector>

namespace ai {
  class PathMap;
};
namespace engine {
  class Engine;
  class Command;
};
namespace state {
  class State;
  class Board;
};
namespace ai {
  class AI;
}

#include "PathMap.h"
#include "AI.h"

namespace ai {

  /// class DeepAI - 
  class DeepAI : public ai::AI {
    // Associations
    // Attributes
  protected:
    PathMap team1PathMap;
    PathMap team2PathMap;
    int maxDepth     = 6;
    int maxLeaves     = 6;
    std::mt19937 randgen;
    // Operations
  public:
    DeepAI (int randomSeed);
    int minimax_rec_min (engine::Engine& engine, int depth);
    int minimax_rec_max (engine::Engine& engine, int depth);
    void minimax_max_init (engine::Engine& engine, int depth, std::vector<engine::Command*>& bestCommands);
    int getHeuristic (const state::State& state);
    int uniform (int min, int max);
    void initPathMaps (const state::Board& board);
    engine::Command* run (engine::Engine& engine);
    // Setters and Getters
    const PathMap& getTeam1PathMap() const;
    void setTeam1PathMap(const PathMap& team1PathMap);
    const PathMap& getTeam2PathMap() const;
    void setTeam2PathMap(const PathMap& team2PathMap);
    int getMaxDepth() const;
    void setMaxDepth(int maxDepth);
    int getMaxLeaves() const;
    void setMaxLeaves(int maxLeaves);
    const std::mt19937& getRandgen() const;
    void setRandgen(const std::mt19937& randgen);
  };

};

#endif
