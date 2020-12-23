#ifndef S3EventAction_h
#define S3EventAction_h 1
#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4THitsMap.hh"
class S3RunAction;
class S3EventAction : public G4UserEventAction
{
  public:
             S3EventAction(S3RunAction* runAction);
    virtual ~S3EventAction();
    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);
    G4int   AddNof(G4int nof)
           {
             fNofP += nof;
             return fNofP;   
           } 
  private:
  //methods
    G4THitsMap<G4double>* GetHitsCollection(G4int hcID,
                                             const G4Event* event) const;
    G4double GetSum(G4THitsMap<G4double>* hitsMap) const; 
    S3RunAction*      runAction;
    G4int             fNofPositron;
    G4double          fEdepOfPositron;
    G4double          fEdepOfGamma;
    G4double          fEdepOfElectron;
    G4int             fNofP;
};
#endif
