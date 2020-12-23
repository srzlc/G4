#include "S3DetectorConstruction.hh"
#include "S3ActionInitialization.hh"
#include "S3Analysis.hh"
#include "G4ScoringManager.hh"
#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif
#include "G4UImanager.hh"
//#include "G4PhysListFactory.hh"
#include "S3PhysicsList.hh"
//#include "G4StepLimiterPhysics.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Randomize.hh"
///////////////////////////////////
int main (int argc,char** argv)
{
  G4UIExecutive* ui = 0;
  if ( argc == 1 ) 
  {
    ui = new G4UIExecutive(argc, argv);
  }
//  G4Random::setTheEngine(new CLHEP::MTwistEngine);
G4Random::setTheEngine(new CLHEP::RanecuEngine);
#ifdef G4MULTITHREADED
  G4MTRunManager* runManager = new G4MTRunManager;
  G4int nThreads = 24;
  runManager->SetNumberOfThreads(nThreads);
#else
  G4RunManager* runManager = new G4RunManager;
#endif
  G4ScoringManager::GetScoringManager();
  auto detConstruction = new S3DetectorConstruction();
  runManager->SetUserInitialization(detConstruction);
/*  G4PhysListFactory* physListFactory = new G4PhysListFactory();
  G4VUserPhysicsList* physicsList = physListFactory->GetReferencePhysList("QGSP_BERT");
  physicsList->SetVerboseLevel(1);
  runManager->SetUserInitialization(physicsList); */
  runManager->SetUserInitialization(new S3PhysicsList);
  auto actionInitialization = new S3ActionInitialization(detConstruction);
  runManager->SetUserInitialization(actionInitialization);
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  if ( ! ui ) 
  { 
  //batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  else 
  { 
  //interactive mode
    UImanager->ApplyCommand("/control/execute init_vis.mac");
 
    ui->SessionStart();
    delete ui;
  }
  delete visManager;
  delete runManager;
}
