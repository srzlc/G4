#ifndef S1SteppingAction_h
#define S1SteppingAction_h 1
#include "G4UserSteppingAction.hh"
#include "globals.hh"
class S1EventAction;
class analysis;
class G4LogicalVolume;
/////////////////
class S1SteppingAction : public G4UserSteppingAction 
{
  public:
    S1SteppingAction(S1EventAction* eventAction,analysis* A_analy);
    virtual ~S1SteppingAction();
    virtual void UserSteppingAction(const G4Step*);
  private:
    S1EventAction* fEventAction;
    G4LogicalVolume* fScoringVolume;
    analysis* Analysis;
};
#endif
