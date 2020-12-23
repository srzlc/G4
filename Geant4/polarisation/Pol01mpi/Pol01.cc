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

#include "G4MPImanager.hh"
#include "G4MPIsession.hh"
#include "Randomize.hh"
#include "ActionInitialization.hh"
#include "DetectorConstruction.hh"
#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif
#include "PhysicsList.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
int main(int argc,char** argv) {
  //MPI
  //At first,G4MPImanager/G4MPIsession should be created
  G4MPImanager* g4MPI = new G4MPImanager(argc, argv);
  //MPI session(G4MPIsession) instead of G4UIterminal
  //Terminal availability depends on your MPI implementation
  G4MPIsession* session = g4MPI->GetMPIsession();
  //choose the Random engine
  //  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
//  CLHEP::HepRandom::setTheEngine(new CLHEP::RanluxEngine());
  
  // Construct the default run manager
  #ifdef G4MULTITHREADED
    G4MTRunManager* runManager = new G4MTRunManager;
    G4int nThreads = 48;
    runManager->SetNumberOfThreads(nThreads);
  #else
    G4RunManager * runManager = new G4RunManager;
  #endif
  // set mandatory initialization classes
  DetectorConstruction* det;
  runManager->SetUserInitialization(det = new DetectorConstruction);
  runManager->SetUserInitialization(new PhysicsList);
  runManager->SetUserInitialization(new ActionInitialization(det));
  
  runManager->Initialize();

  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();

  //ready for go MPIsession treats both interactive and batch modes
  //just start your session as below
  session->SessionStart();
  // job termination     
  delete visManager;
  delete runManager;
  delete g4MPI;
  return EXIT_SUCCESS;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo...... 
