#include "S2SteppingAction.hh"
#include "S2Analysis.hh"
#include "S2EventAction.hh"
#include "S2DetectorConstruction.hh"
#include "G4ParticleTypes.hh"
#include "G4Step.hh"
#include "G4RunManager.hh"
#include <iostream>
#include "G4SystemOfUnits.hh"
//////////////
S2SteppingAction::S2SteppingAction(
                     const S2DetectorConstruction* detectorConstruction,
                     S2EventAction* )
  : G4UserSteppingAction(),
   fDetConstruction(detectorConstruction)
//   fEventAction(eventAction)
{}
//////////////
S2SteppingAction::~S2SteppingAction()
{}
/////////////
void S2SteppingAction::UserSteppingAction(const G4Step* step)
{
auto analysisManager = G4AnalysisManager::Instance();
const G4StepPoint* preStepPoint = step->GetPreStepPoint();
const G4StepPoint* postStepPoint = step->GetPostStepPoint();
// get volume of the current step
auto volume = postStepPoint->GetTouchableHandle()->GetVolume();
//if(volume!=fDetConstruction->GetPV()) return;
//energy deposit
//auto edep=step->GetTotalEnergyDeposit();
const G4Track* track=step->GetTrack();
//const G4int StepNo = track->GetCurrentStepNumber();
//const G4bool off = step->IsFirstStepInVolume();
if (volume == fDetConstruction->GetPV()&&(preStepPoint->GetStepStatus() == fGeomBoundary))
{
 const G4String& name = volume->GetName();
 const G4ThreeVector& preStepPosition = preStepPoint->GetPosition();
 const G4ParticleDefinition* particle = track->GetParticleDefinition();
 const G4String& pname = particle->GetParticleName();
 const G4double Kenergy = track->GetKineticEnergy();
 G4double Px= preStepPosition.x();
 std::cout<<"=========>>>>>"<<pname<<"of"<<Kenergy/MeV<<"  "<<Px/cm<<"at"<<name<<std::endl;
if(particle==G4Electron::Electron()) {
// const G4double EKenergy = preStepPoint->GetKineticEnergy();
analysisManager->FillH1(1,Kenergy);
}
else if(particle==G4Positron::Positron()) {
//const G4double PKenergy = preStepPoint->GetKineticEnergy();
analysisManager->FillH1(2,Kenergy);}
else if(particle==G4Gamma::Gamma()&&Kenergy>10.*MeV) {
//const G4double GKenergy = preStepPoint->GetKineticEnergy();
analysisManager->FillH1(0,Kenergy);
 }


}

}
