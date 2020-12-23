#include "S2EventAction.hh"
#include "S2TrackerSD.hh"
#include "S2TrackerHit.hh"
#include "S2Analysis.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4UnitsTable.hh"
#include "Randomize.hh"
#include <iomanip>
//////////////
S2EventAction::S2EventAction() 
: G4UserEventAction(),
  fHCID(-1)
{}
///////////
S2EventAction::~S2EventAction()
{}
/////////////
S2TrackerHitsCollection* 
S2EventAction::GetHitsCollection(G4int hcID,
                                  const G4Event* event) const
{
  auto hitsCollection 
    = static_cast<S2TrackerHitsCollection*>(
        event->GetHCofThisEvent()->GetHC(hcID));
  
  if ( ! hitsCollection ) {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID; 
    G4Exception("B4cEventAction::GetHitsCollection()",
      "MyCode0003", FatalException, msg);
  }         

  return hitsCollection;
}    
////////////
void S2EventAction::BeginOfEventAction(const G4Event*)
{}
////////////
void S2EventAction::EndOfEventAction(const G4Event* event)
{
//Get hits collections IDs
  if(fHCID==-1)
  {
  fHCID=G4SDManager::GetSDMpointer()->GetCollectionID("PositiveHitCollection");
  }
 //Get hits collections
 auto fHC = GetHitsCollection(fHCID, event);
 //Get hit with total values
  auto PHit = (*fHC)[fHC->entries()-1];

//fill histograms,ntuple
//
//get analysis manager
auto analysisManager = G4AnalysisManager::Instance();
//fill histograms
analysisManager->FillH1(0,PHit->GetEdep());
analysisManager->FillH1(1,PHit->GetTrackLength());
//fill ntuple
analysisManager->FillNtupleDColumn(0,PHit->GetEdep());
analysisManager->FillNtupleDColumn(1,PHit->GetTrackLength());
analysisManager->AddNtupleRow();
}
