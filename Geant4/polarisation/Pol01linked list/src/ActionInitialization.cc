#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "SInput.hh"
ActionInitialization::ActionInitialization(DetectorConstruction* det)
:G4VUserActionInitialization(),fDet(det)
{}
/////////////
ActionInitialization::~ActionInitialization()
{}
////////////
void ActionInitialization::BuildForMaster() const
{
  SInput* inp = new SInput;
  auto prim = new PrimaryGeneratorAction(fDet,inp);
  RunAction* runAction = new RunAction(fDet,prim,inp);
  SetUserAction(runAction);
}
void ActionInitialization::Build() const
{ SInput* inp = new SInput;
  auto prim = new PrimaryGeneratorAction(fDet,inp);
  SetUserAction(prim);
  RunAction* runAction = new RunAction(fDet,prim,inp);
  SetUserAction(runAction);
  SetUserAction(new EventAction(runAction));
  SetUserAction(new SteppingAction(fDet,runAction));
}
