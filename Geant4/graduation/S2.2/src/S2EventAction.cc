#include "S2EventAction.hh"
#include "S2Analysis.hh"
#include "S2RunAction.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "Randomize.hh"
#include <iomanip>
//////////////
S2EventAction::S2EventAction() 
: G4UserEventAction(),
  fGenergy(0.),
  fEenergy(0.),
  fPenergy(0.)
{}
///////////
S2EventAction::~S2EventAction()
{}
/////////////
void S2EventAction::BeginOfEventAction(const G4Event*)
{
 // initialisation per event
 fGenergy=0.;
 fEenergy=0.;
 fPenergy=0.;
}
////////////
void S2EventAction::EndOfEventAction(const G4Event* event)
{
//accumulate ststistics
//
//get analysis manager
auto analysisManager = G4AnalysisManager::Instance();
//fill histograms
analysisManager->FillH1(0,fGenergy);
analysisManager->FillH1(1,fEenergy);
analysisManager->FillH1(2,fPenergy);
//fill ntuple
analysisManager->FillNtupleDColumn(0,fGenergy);
analysisManager->FillNtupleDColumn(1,fEenergy);
analysisManager->FillNtupleDColumn(2,fPenergy);
analysisManager->AddNtupleRow();
}
