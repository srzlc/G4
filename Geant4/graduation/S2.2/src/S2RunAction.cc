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
analysisManager->CreateH1("Gamma","Edep of Gamma",500,0.,300*MeV);
analysisManager->CreateH1("Electron","Edep of Electron",500,0.,300*MeV);
analysisManager->CreateH1("Positron","Edep of Positron",500,0.,300*MeV);
//create ntuple
analysisManager->CreateNtuple("S2","Edep of three kinds of particle");
analysisManager->CreateNtupleDColumn("Gamma");
analysisManager->CreateNtupleDColumn("Electron");
analysisManager->CreateNtupleDColumn("Position");
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
