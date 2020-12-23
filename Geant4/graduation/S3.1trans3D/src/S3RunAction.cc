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
S3RunAction::S3RunAction() : G4UserRunAction()
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
  analysisManager->CreateH1("Positron0","Edep of Positron0",300,0.,30.*MeV);
  analysisManager->CreateH1("Positron1","Edep of Positron1",300,0.,30.*MeV);
  analysisManager->CreateH1("Positron2","Edep of Positron2",300,0.,30.*MeV);
  analysisManager->CreateH1("Positron3","Edep of Positron3",300,0.,30.*MeV);
  analysisManager->CreateH1("Positron4","Edep of Positron4",300,0.,30.*MeV);
  analysisManager->CreateH1("Positron5","Edep of Positron5",300,0.,30.*MeV);
  analysisManager->CreateH1("Positron6","Edep of Positron6",300,0.,30.*MeV);
//create ntuple
  analysisManager->CreateNtuple("S3","Positron");
  analysisManager->CreateNtupleDColumn("EP0");
  analysisManager->CreateNtupleDColumn("EP1");
  analysisManager->CreateNtupleDColumn("EP2");
  analysisManager->CreateNtupleDColumn("EP3");
  analysisManager->CreateNtupleDColumn("EP4");
  analysisManager->CreateNtupleDColumn("EP5");
  analysisManager->CreateNtupleDColumn("EP6");
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
        <<"The total number of Positron Detector0 : "<<fNof0<<G4endl
        <<"The total number of Positron Detector1 : "<<fNof1<<G4endl
        <<"The total number of Positron Detector2 : "<<fNof2<<G4endl
        <<"The total number of Positron Detector3 : "<<fNof3<<G4endl
        <<"The total number of Positron Detector4 : "<<fNof4<<G4endl
        <<"The total number of Positron Detector5 : "<<fNof5<<G4endl  
        <<"The total number of Positron Detector6 : "<<fNof6<<G4endl
        <<G4endl;
  if(analysisManager->GetH1(6))
  {  
    G4cout<<"mean = "
          <<G4BestUnit(analysisManager->GetH1(6)->mean(),"Energy")<<G4endl
          <<"rms = "
          <<G4BestUnit(analysisManager->GetH1(6)->rms(),"Energy")<<G4endl
          <<G4endl;
  } 
  analysisManager->Write();
  analysisManager->CloseFile();
}
