#ifndef S3EventAction_h
#define S3EventAction_h 1
#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4THitsMap.hh"
class S3RunAction;
class S3EventAction : public G4UserEventAction
{
  public:
             S3EventAction(S3RunAction* runAction);
    virtual ~S3EventAction();
    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);
};
#endif
