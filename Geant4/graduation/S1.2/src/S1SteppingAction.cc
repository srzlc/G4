#include "S1SteppingAction.hh"
#include "S1RunAction.hh"
#include "Randomize.hh"
#include "S1EventAction.hh"
#include "S1DetectorConstruction.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "analysis.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4ParticleTypes.hh"
///////////
S1SteppingAction::S1SteppingAction(S1EventAction*,analysis* A_analy) : G4UserSteppingAction(),
  fEventAction(0),
  fScoringVolume(0),
 Analysis(A_analy)
{}
S1SteppingAction::~S1SteppingAction()
{}
////////
void S1SteppingAction::UserSteppingAction(const G4Step* astep)
{
  if (!fScoringVolume) { 
    const S1DetectorConstruction* detectorConstruction
      = static_cast<const S1DetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetScoringVolume();}   
  //////////  
  const G4StepPoint* preStepPoint = astep->GetPreStepPoint();
  const G4StepPoint* postStepPoint =astep->GetPostStepPoint();
  //////////
  G4LogicalVolume* volume = preStepPoint->GetTouchableHandle()
  ->GetVolume()->GetLogicalVolume();
// const G4bool off = astep->IsFirstStepInVolume();
//  if (volume!=fScoringVolume) return; 
   /////////
  const G4Track* track=astep->GetTrack();
// const G4int StepNo = track->GetCurrentStepNumber();
//if(off&&StepNo<=2){
if ( volume==fScoringVolume&&preStepPoint->GetStepStatus() == fGeomBoundary){
 const G4ParticleDefinition* particle = track->GetParticleDefinition();
if(particle==G4Gamma::Gamma()){
  const G4double kinEnergy =preStepPoint->GetKineticEnergy();
  Analysis->Add(1);
// auto energy=kinEnergy*G4UniformRand();
  /////////
  Analysis->RecordValue(kinEnergy/MeV,"energy=");}
//}
}
}
