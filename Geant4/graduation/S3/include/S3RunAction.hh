#ifndef S3RunAction_h
#define S3RunAction_h 1

#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"
#include "globals.hh"
///////////////
class G4Run;
//class S3TrackerSD;
//class S3TrackerHit;

class S3RunAction : public G4UserRunAction
{
  public: 
             S3RunAction();
    virtual ~S3RunAction();
    virtual void  BeginOfRunAction(const G4Run* run);
    virtual void  EndOfRunAction(const G4Run* run);
    virtual G4int AddNofPositron(G4int nof){fNof = nof;return fNof; }
  private:
//  const S3TrackerSD*  fTrackerSD;
//  const S3TrackerHit* fTrackerHit;
          G4int         fNof;
//        G4double      fEDeposit; 
};
#endif
