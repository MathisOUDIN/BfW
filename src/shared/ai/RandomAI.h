// Generated by dia2code
#ifndef AI__RANDOMAI__H
#define AI__RANDOMAI__H

#include <random>

namespace engine {
  class Command;
  class Engine;
};
namespace ai {
  class AI;
}

#include "AI.h"

namespace ai {

  /// class RandomAI - 
  class RandomAI : public ai::AI {
    // Attributes
  protected:
    std::mt19937 randgen;
    // Operations
  public:
    RandomAI (int randomSeed);
    engine::Command* run (engine::Engine& engine);
    // Setters and Getters
    const std::mt19937& getRandgen() const;
    void setRandgen(const std::mt19937& randgen);
  };

};

#endif
