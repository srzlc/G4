#include "S1ActionInitialization.hh"
#include "S1PrimaryGeneratorAction.hh"
#include "S1RunAction.hh"
#include "S1EventAction.hh"
#include "S1SteppingAction.hh"
#include "analysis.hh" 
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
analysis* A_analy = new analysis();
S1RunAction* runAction = new S1RunAction(A_analy);
SetUserAction(runAction);
}
///////////
void S1ActionInitialization::Build() const
{
  SetUserAction(new S1PrimaryGeneratorAction);
  analysis* A_analy=new analysis();
  S1RunAction* runAction=new S1RunAction(A_analy);
  SetUserAction(runAction);
  S1EventAction* eventAction=new S1EventAction;
  SetUserAction(eventAction);
  SetUserAction(new S1SteppingAction(eventAction,A_analy));
}
