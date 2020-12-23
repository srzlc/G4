#include <iostream>
#include "S3DetectorConstruction.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Orb.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
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
#include "G4PVReplica.hh"
#include "G4UserLimits.hh"
////////
S3DetectorConstruction::S3DetectorConstruction()
: G4VUserDetectorConstruction()
{ }
S3DetectorConstruction::~S3DetectorConstruction()
{ }
////////
G4VPhysicalVolume* S3DetectorConstruction::Construct()
{
G4NistManager* nist=G4NistManager::Instance();
//standard R
  G4String name,symbol;
  G4double a,z,density;

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
    new G4Box("World",0.5*world_sizeXY,0.5*world_sizeXY,0.5*world_sizeZ);
  G4LogicalVolume* logicWorld=
    new G4LogicalVolume(solidWorld,
                        R_mat,
                        "WorldLogical"
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
  G4Material* shape_mat =nist->FindOrBuildMaterial("G4_Au");
 G4int x=1;
 for(G4int i=0;i<x;++i)
{//set target position
  G4ThreeVector pos1=G4ThreeVector(0.,0.,-1.*i*cm);
//set target figure
  G4double shape_rmin=0.*cm,shape_rmax=(0.5+0.1*(x-i))*cm;
  G4double shape_hz=0.5*cm;
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
//physical volume
  new G4PVPlacement(0,
  pos1,
  logicShape,
  "Shape",
  logicWorld,
  false,
  0,
  checkOverlaps);}
////detector construction
  G4ThreeVector pos2=G4ThreeVector(0.,0.,40.*cm);
  logicWorld->SetVisAttributes (G4VisAttributes::GetInvisible());
  return physWorld;
}
