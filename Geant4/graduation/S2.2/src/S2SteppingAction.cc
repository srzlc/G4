#include "S2SteppingAction.hh"
#include "S2EventAction.hh"
#include "S2DetectorConstruction.hh"
#include "G4ParticleTypes.hh"
#include "G4Step.hh"
#include "G4RunManager.hh"
//////////////
S2SteppingAction::S2SteppingAction(
                     const S2DetectorConstruction* detectorConstruction,
                     S2EventAction* eventAction)
  : G4UserSteppingAction(),
   fDetConstruction(detectorConstruction),
   fEventAction(eventAction)
{}
//////////////
S2SteppingAction::~S2SteppingAction()
{}
/////////////
void S2SteppingAction::UserSteppingAction(const G4Step* step)
{
// get volume of the current step
auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
//energy deposit
auto edep=step->GetTotalEnergyDeposit();
if (volume == fDetConstruction->GetPV())
{
 const G4Track* track = step->GetTrack();
const G4ParticleDefinition* particle = track->GetParticleDefinition();
if(particle==G4Gamma::Gamma())  {fEventAction->AddGamma(edep);}
else if(particle==G4Electron::Electron()) {fEventAction->AddElectron(edep);}
else if(particle==G4Positron::Positron()) {fEventAction->AddPositron(edep);}
}
}
