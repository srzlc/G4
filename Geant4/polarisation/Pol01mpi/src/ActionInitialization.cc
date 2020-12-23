#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "RunActionMaster.hh"
#include "G4Threading.hh"
ActionInitialization::ActionInitialization(DetectorConstruction* det)
:G4VUserActionInitialization(),fDet(det)
{}
/////////////
ActionInitialization::~ActionInitialization()
{}
////////////
void ActionInitialization::BuildForMaster() const
{
  RunActionMaster* runActionMaster = new RunActionMaster();
  SetUserAction(runActionMaster);
}
void ActionInitialization::Build() const
{
  auto prim = new PrimaryGeneratorAction(fDet);
  SetUserAction(prim);
  if (G4Threading::IsMultithreadedApplication())
  {
    RunAction* runAction = new RunAction();
    SetUserAction(runAction);
  }
  else
  {
    RunActionMaster* runActionMaster = new RunActionMaster();
    SetUserAction(runActionMaster);
  }
  SetUserAction(new EventAction);
  SetUserAction(new SteppingAction(fDet));
}
