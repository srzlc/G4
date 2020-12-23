#include "S3EventAction.hh"
#include "S3RunAction.hh"
#include "S3Analysis.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4Trajectory.hh"
#include "G4TrajectoryContainer.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4ios.hh"
#include <iomanip>
#include <iostream>
//////////////
S3EventAction::S3EventAction(S3RunAction* runAction) 
: G4UserEventAction()
{}
///////////
S3EventAction::~S3EventAction()
{}
/////////////
void S3EventAction::BeginOfEventAction(const G4Event*)
{}
////////////
void S3EventAction::EndOfEventAction(const G4Event* event)
{
}
