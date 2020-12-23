#include "S1RunAction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "analysis.hh"
////////////
S1RunAction::S1RunAction(analysis* A_analy) : G4UserRunAction(),Analysis(A_analy)
{ }
S1RunAction::~S1RunAction()
{ }
void S1RunAction::BeginOfRunAction(const G4Run*)
{
Analysis->Book();
}
void S1RunAction::EndOfRunAction(const G4Run*)
{
Analysis->Save();
}
