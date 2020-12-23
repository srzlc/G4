#include "S1EventAction.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4ios.hh"
//////////////
S1EventAction::S1EventAction() : G4UserEventAction()
{}
///////////
S1EventAction::~S1EventAction()
{}
/////////////
void S1EventAction::BeginOfEventAction(const G4Event*)
{}
////////////
void S1EventAction::EndOfEventAction(const G4Event*)
{}
