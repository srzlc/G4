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
/// \file polarisation/Pol01/src/DetectorConstruction.cc
/// \brief Implementation of the DetectorConstruction class
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Sphere.hh"
#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4RotationMatrix.hh"
#include "G4UnitsTable.hh"
#include "G4RotationMatrix.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction(),
  fWorld(0), fBox(0), fTargetMaterial(0), fWorldMaterial(0)
{
  fBoxSizeXY = 50*mm;
  fBoxSizeZ = 3*mm;
  fWorldSize = 1.*m;
  SetTargetMaterial("G4_Be");  
  SetWorldMaterial("G4_Galactic");  
  fMessenger = new DetectorMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{ 
  delete fMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Cleanup old geometry
  G4GeometryManager::GetInstance()->OpenGeometry();
  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();
  

  // World
  //
  G4Box*
  sWorld = new G4Box("World",                            //name
                   fWorldSize/2,fWorldSize/2,fWorldSize/2); //dimensions

  G4LogicalVolume*                                                                 
  lWorld = new G4LogicalVolume(sWorld,                   //shape
                               fWorldMaterial,           //material
                              "World");                  //name

  fWorld = new G4PVPlacement(0,                          //no rotation
                             G4ThreeVector(),            //at (0,0,0)
                             lWorld,                     //logical volume
                             "World",                    //name
                             0,                          //mother volume
                             false,                      //no boolean operation
                             0);                         //copy number
                                                      
  // Box
  //                           
  G4Box*
  sBox = new G4Box("Target",                           //its name
                   fBoxSizeXY/2.,fBoxSizeXY/2.,fBoxSizeZ/2.);//its dimensions
                   
  G4LogicalVolume*
  lBox = new G4LogicalVolume(sBox,                        //its shape
                             fTargetMaterial,             //its material
                             "theBox");                   //its name

  
  fBox = new G4PVPlacement(0,                             //no rotation
                           G4ThreeVector(),               //at (0,0,0)
                           lBox,                          //its logical volume
                           fTargetMaterial->GetName(),    //its name
                           lWorld,                        //its mother  volume
                           false,                         //no boolean operation
                           0);                            //copy number
  // Detector
  G4double pRmin = 14.*cm;
  G4double pRmax = 16.*cm;
  G4double pSPhi = 0.*degree;
  G4double pDPhi = 180.*degree;
  G4double pSTheta = 0.*degree;
  G4double pDTheta = 180.*degree;
  G4Sphere*
  sSphere = new G4Sphere("Detector",                              //its name
                         pRmin,pRmax,pSPhi,pDPhi,pSTheta,pDTheta);//its size
  G4LogicalVolume*
  lSphere = new G4LogicalVolume(sSphere,                          //its shape
                                 fWorldMaterial,                  //material
                                 "theDetector");                  //its name
  G4RotationMatrix* rx = new G4RotationMatrix();
  rx->rotateX(270.*deg);
  fSphere = new G4PVPlacement(rx,                                  //rotation
                              G4ThreeVector(),                    //at (0,0,0)
                              lSphere,                            //its lvolume
                              "fDetector",                        //its name
                              lWorld,                             //motherVol
                              false,                      //no boolean operation
                              0);                            //copy number
  
  PrintParameters();
  //Visualization attributes
  //G4VisAttributes* worldVisAtt = new G4VisAttributes(G4Colour(1.0,1.0,1.0));
  G4VisAttributes* targetVisAtt = new G4VisAttributes(G4Colour(0.0,0.0,1.0));
 G4VisAttributes* detectorVisAtt = new G4VisAttributes(G4Colour(1.0,1.0,0.0));
  lWorld  ->SetVisAttributes(G4VisAttributes::GetInvisible());
  lBox    ->SetVisAttributes(targetVisAtt);
  lSphere ->SetVisAttributes(detectorVisAtt);
  //always return the root volume
  //
  return fWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::PrintParameters()
{
  G4cout << "\n The Box is " << G4BestUnit(fBoxSizeXY,"Length")
         << " x " << G4BestUnit(fBoxSizeXY,"Length")
         << " x " << G4BestUnit(fBoxSizeZ,"Length")
         << " of " << fTargetMaterial->GetName() << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetTargetMaterial(G4String materialChoice)
{
  // search the material by its name
  G4Material* mat =
    G4NistManager::Instance()->FindOrBuildMaterial(materialChoice);
  if (mat != fTargetMaterial) {
    if(mat) {
      fTargetMaterial = mat;
      UpdateGeometry();
    } else {
      G4cout << "### Warning!  Target material: <"
           << materialChoice << "> not found" << G4endl;  
    }     
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetWorldMaterial(G4String materialChoice)
{
  // search the material by its name
  G4Material* mat =
    G4NistManager::Instance()->FindOrBuildMaterial(materialChoice);
  if (mat != fWorldMaterial) {
    if(mat) {
      fWorldMaterial = mat;
      UpdateGeometry();
    } else {
      G4cout << "### Warning! World material: <"
           << materialChoice << "> not found" << G4endl;  
    }     
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetSizeXY(G4double value)
{
  fBoxSizeXY = value; 
  if (fWorldSize<fBoxSizeXY) fWorldSize = 1.2*fBoxSizeXY;
  UpdateGeometry();
}

void DetectorConstruction::SetSizeZ(G4double value)
{
  fBoxSizeZ = value; 
  if (fWorldSize<fBoxSizeZ) fWorldSize = 1.2*fBoxSizeZ;
  UpdateGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "G4RunManager.hh"

void DetectorConstruction::UpdateGeometry()
{
  if (fWorld) 
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
