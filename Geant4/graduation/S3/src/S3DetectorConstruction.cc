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
//#include "S3TrackerSD.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4SDParticleFilter.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4PSMinKinEAtGeneration.hh"
#include "G4PSEnergyDeposit.hh"
#include "G4PSNofSecondary.hh"
#include "G4SDManager.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4PVReplica.hh"
#include "G4GlobalMagFieldMessenger.hh"
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
//set target position
  G4ThreeVector pos1=G4ThreeVector(0.,0.,0.);
//set target figure
  G4double shape_rmin=0.*cm,shape_rmax=0.5*cm;
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
////detector construction
  G4ThreeVector pos2=G4ThreeVector(-21.*cm,0.,0. );
/*//define material Silicon
          density   =2.330*g/cm3;
          a         =28.08*g/mole;
  G4State state     =kStateSolid;
  G4double ISilicon =173.*eV; 
  G4Material* Si=new G4Material(name="Silicon",z=14.,a,density,state);
  Si->GetIonisation()->SetMeanExcitationEnergy(ISilicon);*/
//set detector figure
  G4double shape2_Rmin   = 0.*cm,shape2_Rmax=40.*cm;
  G4double shape2_SPhi   = 0.*deg,shape2_DPhi=360.*deg;
  G4double shape2_Dz     = 20.*cm;
//solid
  G4Tubs* solidShape2=
    new G4Tubs("SShape2",
                 shape2_Rmin,shape2_Rmax,shape2_Dz,shape2_SPhi,shape2_DPhi);
  G4Material* Ge         = nist->FindOrBuildMaterial("G4_Ge");
  G4Material* Li         = nist->FindOrBuildMaterial("G4_Li");
  G4double density2      = 5.35*g/cm3;
  G4int ncomponents2     =2;
  G4Material* shape2_mat = new G4Material(name="HPGe",density2,ncomponents2);
  shape2_mat->AddMaterial(Li,fractionmass=1.3972e-11*perCent);
  shape2_mat->AddMaterial(Ge,fractionmass=(1-1.3972e-13)*100.*perCent);
//logicalvolume
  logicShape2=
    new G4LogicalVolume(solidShape2,
                        //Ge,
                        shape2_mat,
                        "Shape2LV");
//phydical volume
//  G4RotationMatrix* r2=new G4RotationMatrix();
//  r2->rotateZ(270.*deg);
  new G4PVPlacement(ry,
                    pos2,
                    logicShape2,
                    "Shape2",
                    logicWorld,
                    false,
                    0,
                    checkOverlaps);
//maximun step
//auto detVolUserLimits = new G4UserLimits(0.001*mm);
//logicShape2->SetUserLimits(detVolUserLimits);
  logicWorld->SetVisAttributes (G4VisAttributes::GetInvisible());
  return physWorld;
}
void S3DetectorConstruction::ConstructSDandField()
{
  G4SDManager::GetSDMpointer()->SetVerboseLevel(1);
//sensitive detector
  G4String filterName,particleName;
  G4SDParticleFilter* gammaFilter = 
    new G4SDParticleFilter("gammaFilter","gamma");
//  gammaFilter->add("gamma");
//  gammaFilter->show();

  G4SDParticleFilter* electronFilter = 
    new G4SDParticleFilter("electronFilter","e-");
  electronFilter->add("e-");
  electronFilter->show();

  G4SDParticleFilter* positronFilter =
    new G4SDParticleFilter("positronFilter","e+");
  positronFilter->add("e+");
  positronFilter->show();

  G4MultiFunctionalDetector* det = 
    new G4MultiFunctionalDetector("Shape2LV");
  G4VPrimitiveScorer* pr;
  pr = new G4PSEnergyDeposit("EdepOfPositron");
  pr->SetFilter(positronFilter);
  det->RegisterPrimitive(pr);

  pr = new G4PSNofSecondary("NofPositron");
  pr->SetFilter(positronFilter);
  det->RegisterPrimitive(pr);

  pr = new G4PSEnergyDeposit("EdepOfGamma");
  pr->SetFilter(gammaFilter);
  det->RegisterPrimitive(pr);

  pr = new G4PSEnergyDeposit("EdepOfElectron");
  pr->SetFilter(electronFilter);
  det->RegisterPrimitive(pr);


  G4SDManager::GetSDMpointer()->AddNewDetector(det);
  logicShape2->SetSensitiveDetector(det);

}
