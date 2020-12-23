#ifndef S2SteppingAction_h
#define S2SteppingAction_h 1
#include "G4UserSteppingAction.hh"
#include "globals.hh"
#include <map>
class S2EventAction;
class S2RunAction;
class S2DetectorConstruction;
class G4LogicalVolume;
/////////////////
class S2SteppingAction : public G4UserSteppingAction
{
  public:
    S2SteppingAction();
    ~S2SteppingAction();
  //method from the base class
    virtual void UserSteppingAction(const G4Step*);
  private:
//   std::map<G4ParticleDefinition*,G4int> fParticleFlag;       
    G4LogicalVolume* fScoringVolume; 
};
 
#endif
