// Generated by dia2code
#ifndef STATE__EVENT__H
#define STATE__EVENT__H


#include "EventTypeId.h"

namespace state {

  /// class Event - 
  class Event {
    // Operations
  public:
    virtual ~Event ();
    virtual EventTypeId getEventType () const = 0;
    // Setters and Getters
  };

};

#endif
