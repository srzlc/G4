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
#include <G4VUserMPIrunMerger.hh>
#include "G4MPImanager.hh"
#include "G4Threading.hh"
#include "RunAction.hh"
#include "Analysis.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"


#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"

#include <iostream>
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction()
: G4UserRunAction()
{
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
//  fAnalysisManager->SetActivation(true);
  fAnalysisManager->SetVerboseLevel(1);

  fAnalysisManager->SetFirstHistoId(1);
  // Creating an 1-dimensional histograms in the root directory of the tree
  fAnalysisManager->CreateH1("h1","Initial Gamma Energy",120,0.,30.*MeV);
  fAnalysisManager->CreateH1("h2","Positron Energy",120,0.,30.*MeV);
  fAnalysisManager->CreateH1("h3","xPolarization",120,-1.5,1.5);
  fAnalysisManager->CreateH1("h4","yPolarization",120,-1.5,1.5);
  fAnalysisManager->CreateH1("h5","longitudinalPolarization",120,-1.5,1.5);
  fAnalysisManager->CreateH2("Position","Initial Gamma Position",120,-0.2*mm,0.2*mm,120,-0.02*mm,0.02*mm);
  fAnalysisManager->CreateH2("h6","Fig.6.",120,0.,30.*MeV,120,-1.5,1.5); 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



void RunAction::EndOfRunAction(const G4Run* aRun)
{
  G4int rank = G4MPImanager::GetManager()->GetRank();
  std::ostringstream fname;
  fname<<"rank"<<rank<<"-thread"<<G4Threading::G4GetThreadId();
  auto fAnalysisManager = G4AnalysisManager::Instance();
  fAnalysisManager->OpenFile(fname.str());
  fAnalysisManager->Write();
  fAnalysisManager->CloseFile();  
    

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

