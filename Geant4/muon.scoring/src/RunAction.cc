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
/// \file polarisation/Pol01/src/RunAction.cc
/// \brief Implementation of the RunAction class
//
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "RunAction.hh"
#include "Analysis.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "G4ParticleDefinition.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4EmCalculator.hh"

#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4MuonMinus.hh"
#include "G4MuonPlus.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include <iomanip>
#include <fstream>
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction(DetectorConstruction* det, PrimaryGeneratorAction* prim)
: G4UserRunAction(),
  fGamma(0), fElectron(0), fPositron(0),fMuonMinus(0),fMuonPlus(0)
{
  fGamma = G4Gamma::Gamma();
  fElectron = G4Electron::Electron();
  fPositron = G4Positron::Positron();
  fMuonMinus= G4MuonMinus::MuonMinus();
  fMuonPlus = G4MuonPlus::MuonPlus(); 
  auto fAnalysisManager = G4AnalysisManager::Instance();
//  fAnalysisManager->SetActivation(true);
  fAnalysisManager->SetVerboseLevel(1);

  fAnalysisManager->SetFirstHistoId(1);
  // Creating an 1-dimensional histograms in the root directory of the tree
  fAnalysisManager->CreateH1("MuonMinus","MuonMinus Energy",120,0.,50.*GeV);
  fAnalysisManager->CreateH1("MuonPlus","MuonPlus Energy",120,0.,50.*GeV);
  fAnalysisManager->CreateH2("MuonMinusxy","MuonMinus Position",120,-1.*cm,1.*cm,120,-1.*cm,1.*cm);
  fAnalysisManager->CreateH2("MuonPlusxy","MuonPlus",120,-1.*cm,1.*cm,120,-1.*cm,1.*cm);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{
  delete G4AnalysisManager::Instance();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* aRun)
{  
  G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
  auto fAnalysisManager = G4AnalysisManager::Instance();
  fAnalysisManager->OpenFile("pol01");
  // save Rndm status
  //  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
  //  CLHEP::HepRandom::showEngineStatus();
 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::FillData(const G4ParticleDefinition* particle,
                         G4double kinEnergy,
                         G4double x,
                         G4double y
                         )
{ 
  auto fAnalysisManager = G4AnalysisManager::Instance();  
  if (particle == fMuonMinus) {
    fAnalysisManager->FillH1(1,kinEnergy,1.0);
    fAnalysisManager->FillH2(1,x,y,1.0);
    G4cout<<"======================="<<kinEnergy<<G4endl;
  }
  if (particle == fMuonPlus){
    fAnalysisManager->FillH1(2,kinEnergy,1.0);
    fAnalysisManager->FillH2(2,x,y,1.0);
  }
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* aRun)
{
  auto fAnalysisManager = G4AnalysisManager::Instance();
  fAnalysisManager->Write();
  fAnalysisManager->CloseFile();  
    

  // show Rndm status
//  CLHEP::HepRandom::showEngineStatus();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

