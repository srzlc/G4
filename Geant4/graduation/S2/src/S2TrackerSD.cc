#include "S2TrackerSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
/////
S2TrackerSD::S2TrackerSD(
                       const G4String& name,
                       const G4String& hitsCollectionName)
: G4VSensitiveDetector(name),fHitsCollection(nullptr)
{
  collectionName.insert(hitsCollectionName);
}
/////////
S2TrackerSD::~S2TrackerSD()
{}
//////////
void S2TrackerSD::Initialize(G4HCofThisEvent* hce)
{
  //create hit collection
  fHitsCollection
    = new S2TrackerHitsCollection(SensitiveDetectorName,collectionName[0]);
  //add this collection in hce
  auto hcID
    = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
  hce->AddHitsCollection(hcID,fHitsCollection);
  //create hits
  for (G4int i=0;i<2;i++){
  fHitsCollection->insert(new S2TrackerHit());
}
}
G4bool S2TrackerSD::ProcessHits(G4Step* step,G4TouchableHistory*)
{
//energy deposit
auto edep = step->GetTotalEnergyDeposit();
//step length
G4double stepLength = 0.;
if(step->GetTrack()->GetDefinition()->GetPDGCharge() !=0.){
stepLength = step->GetStepLength();
}
if ( edep==0. && stepLength == 0. ) return false; 
auto touchable = (step->GetPreStepPoint()->GetTouchable());
    
  // Get calorimeter cell id 
  auto layerNumber = touchable->GetReplicaNumber(1);
  
  // Get hit accounting data for this cell
  auto hit = (*fHitsCollection)[layerNumber];
  if ( ! hit ) {
    G4ExceptionDescription msg;
    msg << "Cannot access hit " << layerNumber; 
    G4Exception("S2TrackerSD::ProcessHits()",
      "MyCode0004", FatalException, msg);
  }         

  // Get hit for total accounting
  auto hitTotal 
    = (*fHitsCollection)[fHitsCollection->entries()-1];
  
  // Add values
  hit->Add(edep, stepLength);
  hitTotal->Add(edep, stepLength); 
      
  return true;
}
void S2TrackerSD::EndOfEvent(G4HCofThisEvent*)
{
  if ( verboseLevel>1 ) { 
     auto nofHits = fHitsCollection->entries();
  }
}

