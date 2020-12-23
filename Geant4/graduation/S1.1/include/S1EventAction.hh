#ifndef S1EventAction_h
#define S1EventAction_h 1
#include "G4UserEventAction.hh"
#include "globals.hh"

class S1EventAction : public G4UserEventAction
{
public:
   S1EventAction();
   virtual ~S1EventAction();
   virtual void BeginOfEventAction(const G4Event*);
   virtual void EndOfEventAction(const G4Event*);
};
#endif
