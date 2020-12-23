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
//#include "S2TrackerSD.hh"
//#include "G4AutoDelete.hh"
//#include "G4SDManager.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4PVReplica.hh"
//#include "G4GlobalMagFieldMessenger.hh"
////////
S2DetectorConstruction::S2DetectorConstruction()
: G4VUserDetectorConstruction(),fScoringVolume(0)
{ }
S2DetectorConstruction::~S2DetectorConstruction()
{ }
////////
G4VPhysicalVolume* S2DetectorConstruction::Construct()
{
G4NistManager* nist=G4NistManager::Instance();
//standard R
G4String name,symbol;
G4double a,z,density;
G4int iz,n;
G4int ncomponents,natoms;
G4double abundance,fractionmass;
G4double temperature,pressure;
G4double R_sizeXY=60*cm,R_sizeZ=60*cm;
//environment:vacuum
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
G4double shape_hz=7.e-1*cm;
G4double shape_phimin=0.*deg,shape_phimax=360.*deg;
//solid
G4Tubs* solidShape=
new G4Tubs("Shape",
shape_rmin,shape_rmax,shape_hz,shape_phimin,shape_phimax);
//logicalvolume
G4LogicalVolume* logicShape=
new G4LogicalVolume(solidShape,
shape_mat,
"Shape");
//rotate target
G4RotationMatrix* ry=new G4RotationMatrix();
ry->rotateY(90.*deg);
//physical volume
G4VPhysicalVolume* Shape=
new G4PVPlacement(ry,
pos1,
logicShape,
"Shape",
logicWorld,
false,
0,
checkOverlaps);
////detector construction
G4ThreeVector pos2=G4ThreeVector(-30.*cm,0.,0. );
//define material Silicon
density=2.330*g/cm3;
a=28.08*g/mole;
G4State state=kStateSolid;
G4Material* Si=new G4Material(name="Silicon",z=14.,a,density,state);
//set detector figure
G4double shape_rmin2=0.*cm,shape_rmax2=10.*cm;
G4double shape_hz2=8*cm;
G4double shape_phimin2=0.*deg,shape_phimax2=360.*deg;
//solid
G4Tubs* solidShape2=
new G4Tubs("Shape2",
shape_rmin2,shape_rmax2,shape_hz2,shape_phimin2,shape_phimax2);
//logicalvolume
G4LogicalVolume* logicShape2=
new G4LogicalVolume(solidShape2,
Si,
"Shape2LV");
//phydical volume
G4VPhysicalVolume* Shape2=
new G4PVPlacement(ry,
pos2,
logicShape2,
"Shape2",
logicWorld,
false,
0,
checkOverlaps);
fScoringVolume = logicShape2;
return physWorld;
}

