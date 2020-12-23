#include "S3EventAction.hh"
//#include "S3TrackerSD.hh"
//#include "S3TrackerHit.hh"
#include "S3RunAction.hh"
#include "S3Analysis.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4Trajectory.hh"
#include "G4TrajectoryContainer.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4ios.hh"
#include <iomanip>
#include <iostream>
//////////////
S3EventAction::S3EventAction(S3RunAction* runAction) 
: G4UserEventAction(),
  runAction(runAction),fEdepOfPositron0(-1),fNofPositron0(0),fNofP0(0)
{}
///////////
S3EventAction::~S3EventAction()
{}
/////////////
G4THitsMap<G4double>* 
S3EventAction::GetHitsCollection(G4int hcID,
                                  const G4Event* event) const
{
  auto hitsCollection 
    = static_cast<G4THitsMap<G4double>*>(event->GetHCofThisEvent()->GetHC(hcID));
  
  if ( ! hitsCollection ) 
  {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID; 
    G4Exception("B4cEventAction::GetHitsCollection()",
      "MyCode0003", FatalException, msg);
  }         

  return hitsCollection;
}    
////////////
void S3EventAction::BeginOfEventAction(const G4Event*)
{}
////////////
G4double S3EventAction::GetSum(G4THitsMap<G4double>* hitsMap) const
{
  G4double sumValue = 0.;
  for (auto it : *hitsMap->GetMap())
  {
    sumValue += *(it.second);
  }
  return sumValue;
}
void S3EventAction::EndOfEventAction(const G4Event* event)
{
//get number of stored trajectories
  if(fEdepOfPositron0 == -1) 
  {
  //edepofpositron
    fEdepOfPositron0
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical0/EdepOfPositron");
    fEdepOfPositron1
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical1/EdepOfPositron");
    fEdepOfPositron2
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical2/EdepOfPositron");
    fEdepOfPositron3
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical3/EdepOfPositron");
    fEdepOfPositron4
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical4/EdepOfPositron");
    fEdepOfPositron5
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical5/EdepOfPositron");
    fEdepOfPositron6
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical6/EdepOfPositron");
 /* //edepofgamma 
    fEdepOfGamma0
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical0/EdepOfGamma");
    fEdepOfGamma1
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical1/EdepOfGamma");
    fEdepOfGamma2
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical2/EdepOfGamma");
    fEdepOfGamma3
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical3/EdepOfGamma");
    fEdepOfGamma4
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical4/EdepOfGamma");
    fEdepOfGamma5
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical5/EdepOfGamma");
    fEdepOfGamma6
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical6/EdepOfGamma");
  //edepofelectron 
    fEdepOfElectron0
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical0/EdepOfElectron");
    fEdepOfElectron1
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical1/EdepOfElectron");
    fEdepOfElectron2
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical2/EdepOfElectron");
    fEdepOfElectron3
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical3/EdepOfElectron");
    fEdepOfElectron4
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical4/EdepOfElectron");
    fEdepOfElectron5
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical5/EdepOfElectron");
    fEdepOfElectron6
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical6/EdepOfElectron");*/
  //nofpositron 
    fNofPositron0
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical0/NofPositron");
    fNofPositron1
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical1/NofPositron");
    fNofPositron2
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical2/NofPositron");
    fNofPositron3
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical3/NofPositron");
    fNofPositron4
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical4/NofPositron");
    fNofPositron5
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical5/NofPositron");
    fNofPositron6
      =G4SDManager::GetSDMpointer()->GetCollectionID("DetectorLogical6/NofPositron");
  }
  
//Get sum values from hits collections
//positronedep
  auto PositronEdep0 = GetSum(GetHitsCollection(fEdepOfPositron0,event));
  auto PositronEdep1 = GetSum(GetHitsCollection(fEdepOfPositron1,event));
  auto PositronEdep2 = GetSum(GetHitsCollection(fEdepOfPositron2,event));
  auto PositronEdep3 = GetSum(GetHitsCollection(fEdepOfPositron3,event));
  auto PositronEdep4 = GetSum(GetHitsCollection(fEdepOfPositron4,event));
  auto PositronEdep5 = GetSum(GetHitsCollection(fEdepOfPositron5,event));
  auto PositronEdep6 = GetSum(GetHitsCollection(fEdepOfPositron6,event));
  G4cout<<"=========================================="<<PositronEdep6/MeV<<G4endl;
/*//gammaedep
  auto GammaEdep0    = GetSum(GetHitsCollection(fEdepOfGamma0,event));
  auto GammaEdep1    = GetSum(GetHitsCollection(fEdepOfGamma1,event));
  auto GammaEdep2    = GetSum(GetHitsCollection(fEdepOfGamma2,event));
  auto GammaEdep3    = GetSum(GetHitsCollection(fEdepOfGamma3,event));
  auto GammaEdep4    = GetSum(GetHitsCollection(fEdepOfGamma4,event));
  auto GammaEdep5    = GetSum(GetHitsCollection(fEdepOfGamma5,event));
  auto GammaEdep6    = GetSum(GetHitsCollection(fEdepOfGamma6,event));
//electronedep
  auto ElectronEdep0 = GetSum(GetHitsCollection(fEdepOfElectron0,event));
  auto ElectronEdep1 = GetSum(GetHitsCollection(fEdepOfElectron1,event));
  auto ElectronEdep2 = GetSum(GetHitsCollection(fEdepOfElectron2,event));
  auto ElectronEdep3 = GetSum(GetHitsCollection(fEdepOfElectron3,event));
  auto ElectronEdep4 = GetSum(GetHitsCollection(fEdepOfElectron4,event));
  auto ElectronEdep5 = GetSum(GetHitsCollection(fEdepOfElectron5,event));
  auto ElectronEdep6 = GetSum(GetHitsCollection(fEdepOfElectron6,event));
*/
//nofpositron
  auto NofPositron0  = GetSum(GetHitsCollection(fNofPositron0,event));
  auto NofPositron1  = GetSum(GetHitsCollection(fNofPositron1,event));
  auto NofPositron2  = GetSum(GetHitsCollection(fNofPositron2,event));
  auto NofPositron3  = GetSum(GetHitsCollection(fNofPositron3,event));
  auto NofPositron4  = GetSum(GetHitsCollection(fNofPositron4,event));
  auto NofPositron5  = GetSum(GetHitsCollection(fNofPositron5,event));
  auto NofPositron6  = GetSum(GetHitsCollection(fNofPositron6,event));
  fNofP0             = AddNof0(NofPositron0);
  fNofP1             = AddNof1(NofPositron1);
  fNofP2             = AddNof2(NofPositron2);
  fNofP3             = AddNof3(NofPositron3);
  fNofP4             = AddNof4(NofPositron4);
  fNofP5             = AddNof5(NofPositron5);
  fNofP6             = AddNof6(NofPositron6);
  runAction->AddNofPositron0(fNofP0);
  runAction->AddNofPositron1(fNofP1);
  runAction->AddNofPositron2(fNofP2);
  runAction->AddNofPositron3(fNofP3);
  runAction->AddNofPositron4(fNofP4);
  runAction->AddNofPositron5(fNofP5);
  runAction->AddNofPositron6(fNofP6);  
//fill histograms,ntuple
//
//get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();
//fill histograms
  if(PositronEdep0>0)
  {
    analysisManager->FillH1(0,PositronEdep0);
  }
  if(PositronEdep1>0)
  {
    analysisManager->FillH1(1,PositronEdep1);
  }
  if(PositronEdep2>0)
  {
    analysisManager->FillH1(2,PositronEdep2);
  }
  if(PositronEdep3>0)
  {
    analysisManager->FillH1(3,PositronEdep3);
  }
  if(PositronEdep4>0)
  {
    analysisManager->FillH1(4,PositronEdep4);
  }
  if(PositronEdep5>0)
  {
    analysisManager->FillH1(5,PositronEdep5);
  }
  if(PositronEdep6>0)
  {
    analysisManager->FillH1(6,PositronEdep6);
  }
//fill ntuple
  analysisManager->FillNtupleDColumn(0,PositronEdep0);
  analysisManager->FillNtupleDColumn(1,PositronEdep1);
  analysisManager->FillNtupleDColumn(2,PositronEdep2);
  analysisManager->FillNtupleDColumn(3,PositronEdep3);
  analysisManager->FillNtupleDColumn(4,PositronEdep4);
  analysisManager->FillNtupleDColumn(5,PositronEdep5);
  analysisManager->FillNtupleDColumn(6,PositronEdep6);
  analysisManager->AddNtupleRow();


/*  G4TrajectoryContainer* trajectoryContainer = event->GetTrajectoryContainer();
  G4int n_trajectories = 0;
  if(trajectoryContainer) n_trajectories = trajectoryContainer->entries();*/
}
