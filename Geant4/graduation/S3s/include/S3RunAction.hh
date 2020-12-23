#ifndef S3RunAction_h
#define S3RunAction_h 1

#include "G4UserRunAction.hh"
//#include "G4Accumulable.hh"
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
    virtual void  BeginOfRunAction(const G4Run* );
    virtual void  EndOfRunAction(const G4Run* );
    G4Run* GenerateRun();  
    virtual G4int AddNofPositron(G4int nof){fNof = nof;return fNof;}
  private:
    G4int fNof;
};
#endif
