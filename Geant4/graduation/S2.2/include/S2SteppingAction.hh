#ifndef S2SteppingAction_h
#define S2SteppingAction_h 1
#include "G4UserSteppingAction.hh"
class S2DetectorConstruction;
class S2EventAction;
class S2SteppingAction : public G4UserSteppingAction
{
public:
  S2SteppingAction(const S2DetectorConstruction* detectorConstruction,
                   S2EventAction* eventAction);
  virtual ~S2SteppingAction();
  virtual void UserSteppingAction(const G4Step* step);
private:
  const S2DetectorConstruction* fDetConstruction;
  S2EventAction* fEventAction;
};
#endif
