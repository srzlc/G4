#include "S1ActionInitialization.hh"
#include "S1PrimaryGeneratorAction.hh"
//#include "S1RunAction.hh"
///////////////////
S1ActionInitialization::S1ActionInitialization()
 : G4VUserActionInitialization()
{}
////////////
S1ActionInitialization::~S1ActionInitialization()
{}
///////////
void S1ActionInitialization::BuildForMaster() const
{
//S1RunAction* runAction = new S1RunAction;
//SetUserAction(runAction);
}
///////////
void S1ActionInitialization::Build() const
{
SetUserAction(new S1PrimaryGeneratorAction);
//S1RunAction* runAction=new S1RunAction;
//SetUserAction(runAction);
}
