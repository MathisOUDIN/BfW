// Generated by dia2code
#ifndef CLIENT__NETWORKCLIENT__H
#define CLIENT__NETWORKCLIENT__H

#include <string>
#include <memory>
#include <json/json.h>

namespace engine {
  class Engine;
};
namespace ai {
  class AI;
};
namespace render {
  class Scene;
}

#include "state/TeamId.h"
#include "engine/Engine.h"
#include "ai/AI.h"
#include "render/Scene.h"

namespace client {

  /// class NetworkClient - 
  class NetworkClient {
    // Associations
    // Attributes
  private:
    std::string url;
    int port;
    std::string player;
    state::TeamId teamId;
    engine::Engine engine;
    std::unique_ptr<ai::AI> player_ai;
    int idPlayer;
    // Operations
  public:
    NetworkClient (const std::string& url, int port, std::string player);
    std::string getGameStatus ();
    bool getServerCommands (Json::Value& out, int epoch);
    void putServerCommand (engine::Command* command);
    void endConnection ();
    void run ();
    // Setters and Getters
  };

};

#endif
