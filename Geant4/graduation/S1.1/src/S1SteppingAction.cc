#include "S1SteppingAction.hh"
#include "S1EventAction.hh"
#include "S1DetectorConstruction.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "analysis.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
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
  //////////
  G4LogicalVolume* volume = preStepPoint->GetTouchableHandle()
  ->GetVolume()->GetLogicalVolume();
  if (volume!=fScoringVolume) return; 
   /////////
  const G4double eDeposit=astep->GetTotalEnergyDeposit();
  const G4double sLength =astep->GetStepLength();
  const G4Track* track=astep->GetTrack();
  const G4ThreeVector& momentum =track->GetMomentum();
  const G4double kinEnergy =track->GetKineticEnergy();
  const G4double globalTime =track->GetGlobalTime();
  /////////
  //G4cout<<"momentum="<<momentum<<G4endl;
  //G4cout<<"eDeposit="<<eDeposit/MeV<<G4endl;
  //G4cout<<"sLength="<<sLength<<G4endl;
  //G4cout<<"kinEnergy="<<kinEnergy<<G4endl;
  //G4cout<<"globalTime="<<globalTime<<G4endl;
  Analysis->RecordValue(kinEnergy,"Ekin=");
 // Analysis->RecordValue(eDeposit,"eD=");
 // Analysis->RecordValue(sLength,"sL=");
}
