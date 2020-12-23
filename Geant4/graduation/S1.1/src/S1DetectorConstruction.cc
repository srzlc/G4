#include <iostream>
#include "S1DetectorConstruction.hh"
#include "G4RunMAnager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Orb.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Isotope.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4UnitsTable.hh"
#include "G4PhysicalConstants.hh"
#include "G4RotationMatrix.hh"
////////
S1DetectorConstruction::S1DetectorConstruction()
: G4VUserDetectorConstruction(),fScoringVolume(0)
{ }
S1DetectorConstruction::~S1DetectorConstruction()
{ }
////////
G4VPhysicalVolume* S1DetectorConstruction::Construct()
{
G4NistManager* nist=G4NistManager::Instance();
//standard R
G4String name,symbol;
G4double a,z,density;
G4int iz,n;
G4int ncomponents,natoms;
G4double abundance,fractionmass;
G4double temperature,pressure;
G4double R_sizeXY=30*cm,R_sizeZ=30*cm;
 density=1.e-5*g/cm3;
 pressure=2.e-2*bar;
 temperature=STP_Temperature;
G4Material*R_mat=new G4Material(name="R_mat",density,ncomponents=1,kStateGas,temperature,pressure);
G4Material* Air=nist->FindOrBuildMaterial("G4_AIR");
R_mat->AddMaterial(Air,fractionmass=1.);
G4bool checkOverlaps=true;
//world
G4double world_sizeXY=1*R_sizeXY;
G4double world_sizeZ =1*R_sizeZ;
G4Box* solidWorld=
new G4Box("World",
0.5*world_sizeXY,0.5*world_sizeXY,0.5*world_sizeZ);
G4LogicalVolume* logicWorld=
new G4LogicalVolume(solidWorld,
R_mat,
"World"
);
G4VPhysicalVolume* physWorld=
new G4PVPlacement(0,
G4ThreeVector(),
logicWorld,
"World",
0,
false,
0,
checkOverlaps);
///
G4Material* shape_mat =nist->FindOrBuildMaterial("G4_Al");
G4ThreeVector pos1=G4ThreeVector(-10*cm,0,0);
G4double shape_rmin=0.*cm,shape_rmax=4.*cm;
G4double shape_hz=1.e-4*cm;
G4double shape_phimin=0.*deg,shape_phimax=360.*deg;
G4Tubs* solidShape=
new G4Tubs("Shape",
shape_rmin,shape_rmax,shape_hz,shape_phimin,shape_phimax);
G4LogicalVolume* logicShape=
new G4LogicalVolume(solidShape,
shape_mat,
"Shape");
G4RotationMatrix* ry=new G4RotationMatrix();

ry->rotateY(90.*deg);
new G4PVPlacement(ry,
pos1,
logicShape,
"Shape",
logicWorld,
false,
0,
checkOverlaps);
////
fScoringVolume=logicShape;
return physWorld;
}
