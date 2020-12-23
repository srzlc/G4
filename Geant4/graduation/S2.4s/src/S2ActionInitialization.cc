#include "S2ActionInitialization.hh"
#include "S2PrimaryGeneratorAction.hh"
#include "S2RunAction.hh"
#include "S2DetectorConstruction.hh"
///////////////////
S2ActionInitialization::S2ActionInitialization(S2DetectorConstruction* detConstruction)
 : G4VUserActionInitialization(),
  fDetConstruction(detConstruction)
{}
////////////
S2ActionInitialization::~S2ActionInitialization()
{}
///////////
void S2ActionInitialization::BuildForMaster() const
{
  SetUserAction(new S2RunAction());
}
///////////
void S2ActionInitialization::Build() const
{
  SetUserAction(new S2PrimaryGeneratorAction(fDetConstruction));
  auto runAction = new S2RunAction();
  SetUserAction(runAction);
}
