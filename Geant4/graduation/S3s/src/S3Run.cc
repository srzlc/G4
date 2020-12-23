#include "S3Run.hh"
#include "G4Event.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
//////////////
S3Run::S3Run():G4Run()
{
  G4SDManager* SDMan = G4SDManager::GetSDMpointer();
  nOfPositronID = SDMan->GetCollectionID("Shape2LV/NofPositron");
}
S3Run::~S3Run()
{;}
void S3Run::RecordEvent(const G4Event* evt)
{
 G4HCofThisEvent* HCE = evt->GetHCofThisEvent();
 if(!HCE) return;
 numberOfEvent++;
 G4THitsMap<G4double>* evtMap
   =(G4THitsMap<G4double>*)(HCE->GetHC(nOfPositronID));
 nOfPositron+=*evtMap; 
}
void S3Run::Merge(const G4Run* aRun)
{
  const S3Run* localRun = static_cast<const S3Run*>(aRun);
  nOfPositron+=localRun->nOfPositron;
  G4Run::Merge(aRun);
}
G4double S3Run::GetTotal(const G4THitsMap<G4double> &map) const
{
  G4double tot = 0.;
  if(map.GetSize()==0)return tot;
  std::map<G4int,G4double*>::iterator itr = map.GetMap()->begin();
  for(;itr!=map.GetMap()->end();itr++)
  {tot += *(itr->second);}
  return tot;
}
