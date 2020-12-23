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
/// \file polarisation/Pol01/src/SteppingAction.cc
/// \brief Implementation of the SteppingAction class
//
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"

#include "G4RunManager.hh"
#include "G4PolarizationHelper.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(DetectorConstruction* det,
                                RunAction* ruAct)
 : G4UserSteppingAction(),
   fDetector(det),fRunAction(ruAct)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
  G4StepPoint* prePoint = aStep->GetPreStepPoint();
  G4StepPoint* endPoint = aStep->GetPostStepPoint();
  
  G4String procName = endPoint->GetProcessDefinedStep()->GetProcessName();
  if (prePoint->GetTouchableHandle()->GetVolume()==fDetector->GetWorld() &&
      endPoint->GetTouchableHandle()->GetVolume()==fDetector->GetBox()) 
  {
    G4double gammaKinEnergy = endPoint->GetKineticEnergy();
    G4double x = endPoint->GetPosition().x();
    G4double y = endPoint->GetPosition().y();
    fRunAction->Fill(gammaKinEnergy,x,y);
  }
  if (prePoint->GetTouchableHandle()->GetVolume()==fDetector->GetBox() &&
      endPoint->GetTouchableHandle()->GetVolume()==fDetector->GetWorld()) {
    G4Track* aTrack = aStep->GetTrack();   
    const G4ParticleDefinition* part = 
      aTrack->GetDynamicParticle()->GetDefinition();
    //    G4cout<<"a "<<particleName<<" left the Box \n";
    G4ThreeVector position  = endPoint->GetPosition();
    G4double kinEnergy = endPoint->GetKineticEnergy();

    G4double polX = endPoint->GetPolarization().x();
    G4double polY = endPoint->GetPolarization().y();
    G4double polZ = endPoint->GetPolarization().z();

    fRunAction->FillData(part,kinEnergy,polX,polY,polZ);
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
