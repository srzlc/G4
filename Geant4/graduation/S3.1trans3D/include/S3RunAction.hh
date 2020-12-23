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
    virtual G4int AddNofPositron0(G4int nof){fNof0 = nof;return fNof0; }
    virtual G4int AddNofPositron1(G4int nof){fNof1 = nof;return fNof1; }
    virtual G4int AddNofPositron2(G4int nof){fNof2 = nof;return fNof2; }
    virtual G4int AddNofPositron3(G4int nof){fNof3 = nof;return fNof3; }
    virtual G4int AddNofPositron4(G4int nof){fNof4 = nof;return fNof4; }
    virtual G4int AddNofPositron5(G4int nof){fNof5 = nof;return fNof5; }
    virtual G4int AddNofPositron6(G4int nof){fNof6 = nof;return fNof6; }
  private:
//  const S3TrackerSD*  fTrackerSD;
//  const S3TrackerHit* fTrackerHit;
          G4int         fNof0;
          G4int         fNof1;
          G4int         fNof2;
	  G4int         fNof3;
 	  G4int         fNof4;
	  G4int         fNof5;
	  G4int         fNof6;
//        G4double      fEDeposit; 
};
#endif
