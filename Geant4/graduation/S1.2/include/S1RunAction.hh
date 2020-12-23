#ifndef S1RunAction_h
#define S1RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

///////////////
class G4Run;
class analysis;
class S1RunAction : public G4UserRunAction
{
public: 
S1RunAction(analysis* A_analy);
virtual ~S1RunAction();
virtual void BeginOfRunAction(const G4Run* run);
virtual void   EndOfRunAction(const G4Run* run);
private:
analysis* Analysis; 
};
#endif
