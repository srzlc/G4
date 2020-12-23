#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"

ActionInitialization::ActionInitialization(DetectorConstruction* det)
:G4VUserActionInitialization(),fDet(det)
{}
/////////////
ActionInitialization::~ActionInitialization()
{}
////////////
void ActionInitialization::BuildForMaster() const
{
  auto prim = new PrimaryGeneratorAction(fDet);
  RunAction* runAction = new RunAction(fDet,prim);
  SetUserAction(runAction);
}
void ActionInitialization::Build() const
{
  auto prim = new PrimaryGeneratorAction(fDet);
  SetUserAction(prim);
  RunAction* runAction = new RunAction(fDet,prim);
  SetUserAction(runAction);
  SetUserAction(new EventAction(runAction));
  SetUserAction(new SteppingAction(fDet,runAction));
}
