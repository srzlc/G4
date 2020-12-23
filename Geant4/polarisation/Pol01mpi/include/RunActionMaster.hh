#ifndef RunActionMaster_h
#define RunActionMaster_h 1
#include "G4UserRunAction.hh"

class RunActionMaster : public G4UserRunAction
{
  public:
            RunActionMaster();
   virtual ~RunActionMaster();
   virtual void BeginOfRunAction(const G4Run*);
   virtual void EndOfRunAction(const G4Run*);
};
#endif
