#include "S3RunAction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "S3Analysis.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
//#include "S3TrackerSD.hh"
//#include "S3TrackerHit.hh"
#include "G4Track.hh"
#include <iostream>
#include <stdio.h>
using namespace std;
////////////
S3RunAction::S3RunAction() : G4UserRunAction(),fNof(0.)
{ 
//set printing event number per each 100 events
//G4RunManager::GetRunManager()->SetPrintProgress(1000);
// Create analysis manager
  auto analysisManager = G4AnalysisManager::Instance();
  G4cout<<"Using "<<analysisManager->GetType()<<G4endl;
//create directories
  analysisManager->SetActivation(true);
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true);
//Book histograms, ntuple
//
//create histograms
  analysisManager->CreateH1("Positron","Edep of Positron",300,0.,100.*MeV);
  analysisManager->CreateH1("Gamma","Edep of Gamma",1000,0.,100.*MeV);
  analysisManager->CreateH1("Electron","Edep of Electron",100,0.,100.*MeV);
//create ntuple
  analysisManager->CreateNtuple("S3","Positron,Gamma,Electron");
  analysisManager->CreateNtupleDColumn("EP");
  analysisManager->CreateNtupleDColumn("EG");
  analysisManager->CreateNtupleDColumn("EE");
  analysisManager->FinishNtuple();	
}
///////////
S3RunAction::~S3RunAction()
{ 
  delete G4AnalysisManager::Instance();
}
void S3RunAction::BeginOfRunAction(const G4Run*)
{
//get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();
//  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
//open an output file
  G4String fileName = "S3";
  analysisManager->OpenFile(fileName);
}
void S3RunAction::EndOfRunAction(const G4Run*)
{
  auto analysisManager = G4AnalysisManager::Instance();
G4cout<<G4endl
        <<"===================================================="<<G4endl;
  G4cout<<"The result of simulation "<<G4endl
        <<"The total number of Positron Detector : "<<fNof<<G4endl
        <<G4endl;
  if(analysisManager->GetH1(0))
  {  
    G4cout<<"mean = "
          <<G4BestUnit(analysisManager->GetH1(0)->mean(),"Energy")<<G4endl
          <<"rms = "
          <<G4BestUnit(analysisManager->GetH1(0)->rms(),"Energy")<<G4endl
          <<G4endl;
  } 
  analysisManager->Write();
  analysisManager->CloseFile();
}
