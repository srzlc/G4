#include "S2ActionInitialization.hh"
#include "S2PrimaryGeneratorAction.hh"
#include "S2RunAction.hh"
//#include "S2EventAction.hh" 
#include "S2SteppingAction.hh"
///////////////////
S2ActionInitialization::S2ActionInitialization()
 : G4VUserActionInitialization()
{}
////////////
S2ActionInitialization::~S2ActionInitialization()
{}
///////////
void S2ActionInitialization::BuildForMaster() const
{
  SetUserAction(new S2RunAction);
}
///////////
void S2ActionInitialization::Build() const
{
  SetUserAction(new S2PrimaryGeneratorAction);
  SetUserAction(new S2RunAction);
//  SetUserAction(new S2EventAction);
 S2SteppingAction* steppingAction = new S2SteppingAction();
  SetUserAction(steppingAction);
}
