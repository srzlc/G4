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
    G4int   AddNof0(G4int nof)
           {
             fNofP0 += nof;
             return fNofP0;   
           } 
    G4int   AddNof1(G4int nof)
           {
             fNofP1 += nof;
             return fNofP1;
           }
    G4int   AddNof2(G4int nof)
           {
             fNofP2 += nof;
             return fNofP2;
           }
    G4int   AddNof3(G4int nof)
           {
             fNofP3 += nof;
             return fNofP3;
           }
    G4int   AddNof4(G4int nof)
           {
             fNofP4 += nof;
             return fNofP4;
           }
    G4int   AddNof5(G4int nof)
           {
             fNofP5 += nof;
             return fNofP5;
           }
    G4int   AddNof6(G4int nof)
           {
             fNofP6 += nof;
             return fNofP6;
           }

  private:
  //methods
    G4THitsMap<G4double>* GetHitsCollection(G4int hcID,
                                             const G4Event* event) const;
    G4double GetSum(G4THitsMap<G4double>* hitsMap) const; 
    S3RunAction*      runAction;
    G4double          fEdepOfPositron0;
    G4double          fEdepOfPositron1;
    G4double          fEdepOfPositron2;
    G4double          fEdepOfPositron3;
    G4double          fEdepOfPositron4;
    G4double          fEdepOfPositron5;
    G4double          fEdepOfPositron6;
/*  G4double          fEdepOfGamma0;
    G4double          fEdepOfGamma1;
    G4double          fEdepOfGamma2;
    G4double          fEdepOfGamma3;
    G4double          fEdepOfGamma4;
    G4double          fEdepOfGamma5;
    G4double          fEdepOfGamma6;
    G4double          fEdepOfElectron0;
    G4double          fEdepOfElectron1;
    G4double          fEdepOfElectron2;
    G4double          fEdepOfElectron3;
    G4double          fEdepOfElectron4;
    G4double          fEdepOfElectron5;
    G4double          fEdepOfElectron6;*/
    G4int             fNofPositron0;
    G4int             fNofPositron1;
    G4int             fNofPositron2;
    G4int             fNofPositron3;
    G4int             fNofPositron4;
    G4int             fNofPositron5;
    G4int             fNofPositron6;
    G4int             fNofP0;
    G4int             fNofP1;
    G4int             fNofP2;
    G4int             fNofP3;
    G4int             fNofP4;
    G4int             fNofP5;
    G4int             fNofP6;
};
#endif
