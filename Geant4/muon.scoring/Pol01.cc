//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file polarisation/Pol01/Pol01.cc
/// \brief Main program of the polarisation/Pol01 example
//
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo...... 

#include "G4Types.hh"

#include "G4UImanager.hh"
#include "Randomize.hh"
#include "ActionInitialization.hh"
#include "DetectorConstruction.hh"
#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif
#include "G4PhysListFactory.hh"
#include "G4TrajectoryDrawByParticleID.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4Colour.hh"
#include "G4ScoringManager.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
int main(int argc,char** argv) {
 
  // Instantiate G4UIExecutive if interactive mode
  G4UIExecutive* ui = nullptr;
  if ( argc == 1 ) {
    ui = new G4UIExecutive(argc, argv);
  }

  //choose the Random engine
  //  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
  CLHEP::HepRandom::setTheEngine(new CLHEP::RanluxEngine());
  
  // Construct the default run manager
  #ifdef G4MULTITHREADED
    G4MTRunManager* runManager = new G4MTRunManager;
    G4int nThreads = 4;
    runManager->SetNumberOfThreads(nThreads);
  #else
    G4RunManager * runManager = new G4RunManager;
  #endif
  G4ScoringManager::GetScoringManager();
  // set mandatory initialization classes
  DetectorConstruction* det;
  runManager->SetUserInitialization(det = new DetectorConstruction);
  G4PhysListFactory* physListFactory = new G4PhysListFactory();
  G4VUserPhysicsList* physicsList   = physListFactory->GetReferencePhysList("QGSP_BERT");
  runManager->SetUserInitialization(physicsList);
  runManager->SetUserInitialization(new ActionInitialization(det));
 // runManager->SetUserAction(prim = new PrimaryGeneratorAction(det));

  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
  G4TrajectoryDrawByParticleID* model = new G4TrajectoryDrawByParticleID;
  model->SetDefault("white");
  model->Set("gamma","white");
  model->Set("e+","white");
  model->Set("e-","white");
  model->Set("mu+","grey");
  model->Set("mu-","grey");
  visManager->RegisterModel(model);
  
  // get the pointer to the User Interface manager 
    G4UImanager* UImanager = G4UImanager::GetUIpointer();  

  if (ui)   // Define UI terminal for interactive mode
    { 
      UImanager->ApplyCommand("/control/execute vis.mac");
      ui->SessionStart();
      delete ui;
    }
  else           // Batch mode
    { 
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UImanager->ApplyCommand(command+fileName);
    }

  // job termination     
  delete visManager;
  delete runManager;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo...... 
