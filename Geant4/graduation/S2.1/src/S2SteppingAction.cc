#include "S2SteppingAction.hh"
//#include "S2EventAction.hh"
#include "S2DetectorConstruction.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4ParticleTypes.hh"
#include "HistoManager.hh"
#include "G4UnitsTable.hh"
#include <iomanip>
#include <iostream>
/////////
S2SteppingAction::S2SteppingAction() : G4UserSteppingAction(),fScoringVolume(0)
{}
////////
S2SteppingAction::~S2SteppingAction()
{}
/////
void S2SteppingAction::UserSteppingAction(const G4Step* step)
{
if (!fScoringVolume) { 
    const S2DetectorConstruction* detectorConstruction
      = static_cast<const S2DetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetScoringVolume();   
    }
//
const G4StepPoint* preStepPoint = step->GetPreStepPoint();
//
G4LogicalVolume* volume = preStepPoint->GetTouchableHandle()
  ->GetVolume()->GetLogicalVolume();
// if (volume!=fScoringVolume) return;
  const G4Track* track = step->GetTrack();
const G4ParticleDefinition* particle = track->GetParticleDefinition();
//primary particle
G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
//G4int ih = 1;
G4bool off = step->IsFirstStepInVolume();
G4int StepNo = track->GetCurrentStepNumber();
//if (step->GetTrack()->GetTrackID() == 1) {
//   if(off&&StepNo<1){if(volume!=fScoringVolume) {G4double energy = preStepPoin//t->GetKineticEnergy();      
//    G4ThreeVector position=step->GetPreStepPoint()->GetPosition();
//    analysisManager->FillH1(ih,energy);
//    std::cout<<"PEenergy = "<<energy<<"      "<<position<<std::endl;}}
 //   }
//secondaries
//const std::vector<const G4Track*>* secondary 
//                                    = step->GetSecondaryInCurrentStep();  
//for (size_t lp=0; lp<(*secondary).size(); lp++) {
if(off){if(volume!=fScoringVolume) {   
 
   
//  ih=0
if(particle==G4Gamma::Gamma())  {G4ThreeVector position=step->GetPreStepPoint()->GetPosition();
G4double energy = preStepPoint->GetKineticEnergy();
  
//else if(particle==G4Electron::Electron()) ih=3; 
//else if(particle==G4Positron::Positron())  ih=4;
//if(ih=2)// analysisManager->FillH1(ih,energy);
std::cout<<"Gammaenergy = "<<energy<<std::endl;}
//fParticleFlag[particle]++;
}}
//} 
  
// kill event after first interaction
  //
//  G4RunManager::GetRunManager()->AbortEvent();  
}
