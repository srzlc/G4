#include <iostream>
#include "S2DetectorConstruction.hh"
#include "G4RunManager.hh"
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
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
////////
S2DetectorConstruction::S2DetectorConstruction()
: G4VUserDetectorConstruction()
{ }
S2DetectorConstruction::~S2DetectorConstruction()
{ }
////////
G4VPhysicalVolume* S2DetectorConstruction::Construct()
{
G4NistManager* nist=G4NistManager::Instance();
//standard R
G4String name,symbol;
G4double density,a,z;

G4int ncomponents;
G4double fractionmass;
G4double temperature,pressure;
G4double R_sizeXY=100*cm,R_sizeZ=100*cm;
//environment:vacuum
density     = universe_mean_density;    //from PhysicalConstants.h
  pressure    = 3.e-18*pascal;
  temperature = 2.73*kelvin;
  new G4Material("Galactic", z=1., a=1.008*g/mole, density,
                             kStateGas,temperature,pressure);
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
////single wolframium target
//set target material
G4Material* shape_mat =nist->FindOrBuildMaterial("G4_W");
//set target position
G4ThreeVector pos1=G4ThreeVector(0.,0.,0.);
//set target figure
G4double shape_rmin=0.*cm,shape_rmax=8.*cm;
G4double shape_hz=0.35*cm;
G4double shape_phimin=0.*deg,shape_phimax=360.*deg;
//solid
G4Tubs* solidShape=
new G4Tubs("Shape",
shape_rmin,shape_rmax,shape_hz,shape_phimin,shape_phimax);
//logicalvolume
G4LogicalVolume* logicShape=
new G4LogicalVolume(solidShape,
shape_mat,
//R_mat,
"Shape");
//rotate target
G4RotationMatrix* ry=new G4RotationMatrix();
ry->rotateY(90.*deg);
//physical volume

new G4PVPlacement(ry,
pos1,
logicShape,
"Shape",
logicWorld,
false,
0,
checkOverlaps);
return physWorld;
}
