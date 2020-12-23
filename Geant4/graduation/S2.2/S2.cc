#include "S2DetectorConstruction.hh"
#include "S2ActionInitialization.hh"

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"
#include "G4PhysListFactory.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Randomize.hh"
///////////////////////////////////
int main (int argc,char** argv)
{
G4UIExecutive* ui = 0;
  if ( argc == 1 ) {
    ui = new G4UIExecutive(argc, argv);
}
G4Random::setTheEngine(new CLHEP::MTwistEngine);
#ifdef G4MULTITHREADED
  G4MTRunManager* runManager = new G4MTRunManager;
#else
  G4RunManager* runManager = new G4RunManager;
#endif
auto detConstruction = new S2DetectorConstruction();
runManager->SetUserInitialization(detConstruction);
//set physicslist by physicslistfactory
G4PhysListFactory* physListFactory = new G4PhysListFactory();
G4VUserPhysicsList* physicsList = physListFactory->GetReferencePhysList("QGSP_BERT_EMZ");
physicsList->SetVerboseLevel(1);
runManager->SetUserInitialization(physicsList);
auto actionInitialization = new S2ActionInitialization(detConstruction);
runManager->SetUserInitialization(actionInitialization);
G4VisManager* visManager = new G4VisExecutive;
visManager->Initialize();
G4UImanager* UImanager = G4UImanager::GetUIpointer();
if ( ! ui ) { 
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  else { 
    // interactive mode
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    delete ui;
  }
delete visManager;
  delete runManager;
}
