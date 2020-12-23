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
  runAction(runAction),fNofPositron(0)
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
    fEdepOfPositron
      =G4SDManager::GetSDMpointer()->GetCollectionID("Shape2LV/EdepOfPositron");
    fEdepOfGamma
      =G4SDManager::GetSDMpointer()->GetCollectionID("Shape2LV/EdepOfGamma");
    fEdepOfElectron
      =G4SDManager::GetSDMpointer()->GetCollectionID("Shape2LV/EdepOfElectron");
    fNofPositron
      =G4SDManager::GetSDMpointer()->GetCollectionID("Shape2LV/NofPositron");
//    G4cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>"<<fNofPositron<<G4endl
//          <<"Positron energy = "<<fEdepOfPositron<<G4endl;
//Get sum values from hits collections
  auto PositronEdep = GetSum(GetHitsCollection(fEdepOfPositron,event));
  auto GammaEdep    = GetSum(GetHitsCollection(fEdepOfGamma,event));
  auto ElectronEdep = GetSum(GetHitsCollection(fEdepOfElectron,event));

  auto NofPositron  = GetSum(GetHitsCollection(fNofPositron,event));
//  G4cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<NofPositron<<G4endl;
//        <<"event Positron energy = "<<PositronEdep;
  fNofP             = AddNof(NofPositron);
//  G4cout<<"==========================="<<fNofP<<G4endl;
  runAction->AddNofPositron(fNofP);
//fill histograms,ntuple
//
//get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();
//fill histograms

  analysisManager->FillH1(0,PositronEdep);
  analysisManager->FillH1(1,GammaEdep);
  analysisManager->FillH1(2,ElectronEdep);
//fill ntuple
  analysisManager->FillNtupleDColumn(0,PositronEdep);
  analysisManager->FillNtupleDColumn(1,GammaEdep);
  analysisManager->FillNtupleDColumn(2,ElectronEdep);
  analysisManager->AddNtupleRow();


/*  G4TrajectoryContainer* trajectoryContainer = event->GetTrajectoryContainer();
  G4int n_trajectories = 0;
  if(trajectoryContainer) n_trajectories = trajectoryContainer->entries();*/
}
