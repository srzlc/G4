#include "S2RunAction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "S2Analysis.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
////////////
S2RunAction::S2RunAction() : G4UserRunAction()
{ 
// Create analysis manager
auto analysisManager = G4AnalysisManager::Instance();
//create directories
analysisManager->SetVerboseLevel(1);
analysisManager->SetNtupleMerging(true);
//Book histograms, ntuple
//
//create histograms
analysisManager->CreateH1("ESD","Edep in SD",500,0.,600*MeV);
analysisManager->CreateH1("LSD","trackL in SD",500,0.,1*m);
//create ntuple
analysisManager->CreateNtuple("S2","Edep and TrackL");
analysisManager->CreateNtupleDColumn("ESD");
analysisManager->CreateNtupleDColumn("LSD");
analysisManager->FinishNtuple();	
}
///////////
S2RunAction::~S2RunAction()
{ 
delete G4AnalysisManager::Instance();
}
void S2RunAction::BeginOfRunAction(const G4Run*)
{
//get analysis manager
auto analysisManager = G4AnalysisManager::Instance();
//open an output file
G4String fileName = "S2";
analysisManager->OpenFile(fileName);
}
void S2RunAction::EndOfRunAction(const G4Run*)
{
  auto analysisManager = G4AnalysisManager::Instance();
   analysisManager->Write();
  analysisManager->CloseFile();
}
