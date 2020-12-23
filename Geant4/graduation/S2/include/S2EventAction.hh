#ifndef S2EventAction_h
#define S2EventAction_h 1
#include "G4UserEventAction.hh"
#include "globals.hh"
#include "S2TrackerHit.hh"
class S2EventAction : public G4UserEventAction
{
public:
   S2EventAction();
   virtual ~S2EventAction();
   virtual void BeginOfEventAction(const G4Event*);
   virtual void EndOfEventAction(const G4Event*);
private:
   //methods
   S2TrackerHitsCollection* GetHitsCollection(G4int hcID,
                                             const G4Event* event) const;
   void PrintEventStatistics(G4double Edep,G4double TrackLength) const;
   //data members
   G4int fHCID;
};
#endif
