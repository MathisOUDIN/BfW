// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H


namespace state {
  class Board;
}

#include "Board.h"

namespace state {

  /// class State - 
  class State {
    // Associations
    // Attributes
  private:
    Board board;
  protected:
    int turn;
    // Operations
  public:
    State ();
    Board& getBoard ();
    // Setters and Getters
    int getTurn() const;
    void setTurn(int turn);
  };

};

#endif