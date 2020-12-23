#ifndef S2RunAction_h
#define S2RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include <map>
///////////////
class G4Run;
class HistoManager;
class S2RunAction : public G4UserRunAction
{
public: 
S2RunAction();
virtual ~S2RunAction();
virtual void BeginOfRunAction(const G4Run* );
virtual void   EndOfRunAction(const G4Run* );
private:
HistoManager*              fHistoManager;

};
#endif