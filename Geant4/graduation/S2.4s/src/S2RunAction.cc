#include "S2RunAction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
////////////
S2RunAction::S2RunAction() : G4UserRunAction()
{}
///////////
S2RunAction::~S2RunAction()
{}
/////////////
void S2RunAction::BeginOfRunAction(const G4Run*)
{
}
void S2RunAction::EndOfRunAction(const G4Run*)
{
}
