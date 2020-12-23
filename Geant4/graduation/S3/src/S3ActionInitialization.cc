#include "S3ActionInitialization.hh"
#include "S3PrimaryGeneratorAction.hh"
#include "S3RunAction.hh"
#include "S3EventAction.hh" 
///////////////////
S3ActionInitialization::S3ActionInitialization(S3DetectorConstruction*)
 : G4VUserActionInitialization()
{}
////////////
S3ActionInitialization::~S3ActionInitialization()
{}
///////////
void S3ActionInitialization::BuildForMaster() const
{
  SetUserAction(new S3RunAction);
}
///////////
void S3ActionInitialization::Build() const
{
  SetUserAction(new S3PrimaryGeneratorAction(det));
  auto runAction             = new S3RunAction();
  SetUserAction(runAction);
  S3EventAction* eventAction = new S3EventAction(runAction); 
  SetUserAction(eventAction);
}
