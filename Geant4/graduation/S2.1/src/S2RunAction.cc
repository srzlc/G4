#include "S2RunAction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "HistoManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include <iomanip>
////////////
S2RunAction::S2RunAction() : G4UserRunAction(),fHistoManager(0)
{ 
fHistoManager = new HistoManager();
//G4RunManager::GetRunManager()->SetPrintProgress(1); 
// Create analysis manager
//auto analysisManager = G4AnalysisManager::Instance();
//create directories
//analysisManager->SetVerboseLevel(1);
//  analysisManager->SetNtupleMerging(true);

//Book histogram
//
//create histograms
//analysisManager->CreateH1("PElectron","kinenergy of Primary Electron",500,0.,3//00*MeV);
//analysisManager->CreateH1("Gamma","kinenergy of Gamma",500,0.,300*MeV);
//analysisManager->CreateH1("SElectron","kinenergy of Secondary Electron",500,0.//,300*MeV);
//analysisManager->CreateH1("Positron","kinenergy of Positron",500,0.,100*MeV);
}
///////////
S2RunAction::~S2RunAction()
{ 
//delete G4AnalysisManager::Instance();
delete fHistoManager;
}
void S2RunAction::BeginOfRunAction(const G4Run*)
{
//get analysis manager
G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
//open an output file
///G4String fileName = "S2.root";
//if(analysisManager->IsActive())
analysisManager->OpenFile();
}
void S2RunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
// if(analysisManager->IsActive()){ 
  analysisManager->Write();
  analysisManager->CloseFile();
//}
}
