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
#include "G4Transform3D.hh"
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
//#include "G4GlobalMagFieldMessenger.hh"
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
  G4double R_sizeXY=200*cm,R_sizeZ=200*cm;
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
  for(G4int i =0;i<x;++i)
  {
  //set target position
    G4ThreeVector pos1=G4ThreeVector(1.*i*cm,0.,0.);
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
  }
/*////detector construction
  G4ThreeVector pos2=G4ThreeVector(-0.5*cm,0.,0. );
//define material Silicon
          density   =2.330*g/cm3;
          a         =28.08*g/mole;
  G4State state     =kStateSolid;
  G4double ISilicon =173.*eV; 
  G4Material* Si=new G4Material(name="Silicon",z=14.,a,density,state);
  Si->GetIonisation()->SetMeanExcitationEnergy(ISilicon);
//set detector figure
  G4double shape2_Rmin   = 35.*cm,shape2_Rmax=40.*cm;
  G4double shape2_SPhi   = 0.*deg,shape2_DPhi=180.*deg;
  G4double shape2_STheta = 0.*deg,shape2_DTheta=180.*deg;
//solid
  G4Sphere* solidShape2=
    new G4Sphere("SShape2",
                 shape2_Rmin,shape2_Rmax,shape2_SPhi,shape2_DPhi,shape2_STheta,shape2_DTheta);
G4Material* Ge = nist->FindOrBuildMaterial("G4_Ge");
//G4Material* Li = nist->FindOrBuildMaterial("G4_Li");
//G4Material* shape2_mat = new G4Material(name="HPGe", )
//logicalvolume
  logicShape2=
    new G4LogicalVolume(solidShape2,
                        Ge,
                        "Shape2LV");
//phydical volume
  G4RotationMatrix* r2=new G4RotationMatrix();
  r2->rotateZ(270.*deg);
  new G4PVPlacement(r2,
                    pos2,
                    logicShape2,
                    "Shape2",
                    logicWorld,
                    false,
                    0,
                    checkOverlaps);*/
////detector
  G4Material* Ge       = nist->FindOrBuildMaterial("G4_Ge");
  G4Material* Li         = nist->FindOrBuildMaterial("G4_Li");
  G4double density2      = 5.35*g/cm3;
  G4int ncomponents2     =2;
  G4Material* shape2_mat = new G4Material(name="HPGe",density2,ncomponents2);
  shape2_mat->AddMaterial(Li,fractionmass=1.3972e-11*perCent);
  shape2_mat->AddMaterial(Ge,fractionmass=(1-1.3972e-13)*100.*perCent);
  G4double phi0        = 0. *deg;
  G4double phi1        = 15.*deg;
  G4double phi2        = 30.*deg;
  G4double phi3        = 45.*deg;
  G4double phi4        = 60.*deg;
  G4double phi5        = 75.*deg;
  G4double phi6        = 90.*deg;
  G4RotationMatrix r0  =  G4RotationMatrix();
  G4RotationMatrix r1  =  G4RotationMatrix();
  G4RotationMatrix r2  =  G4RotationMatrix();
  G4RotationMatrix r3  =  G4RotationMatrix();
  G4RotationMatrix r4  =  G4RotationMatrix();
  G4RotationMatrix r5  =  G4RotationMatrix();
  G4RotationMatrix r6  =  G4RotationMatrix();
  r0.rotateY(90.*deg);
  r0.rotateZ(phi0-90.*deg);
  r1.rotateY(90.*deg);
  r1.rotateZ(phi1-90.*deg);
  r2.rotateY(90.*deg);
  r2.rotateZ(phi2-90.*deg);
  r3.rotateY(90.*deg);
  r3.rotateZ(phi3-90.*deg);
  r4.rotateY(90.*deg);
  r4.rotateZ(phi4-90.*deg);
  r5.rotateY(90.*deg);
  r5.rotateZ(phi5-90.*deg);
  r6.rotateY(90.*deg);
  r6.rotateZ(phi6-90.*deg);
  G4double rMin        = 0.*cm;
  G4double rMax        = 3*cm;
  G4double hz          = 10*cm;
  G4double phiMin      = 0.*deg;
  G4double phiMax      = 360.*deg;
  G4ThreeVector Pos    = G4ThreeVector(0.,30.*cm,0.);
  G4Transform3D transform0(r0,Pos);
  G4Transform3D transform1(r1,Position(phi1));
  G4Transform3D transform2(r2,Position(phi2));
  G4Transform3D transform3(r3,Position(phi3));
  G4Transform3D transform4(r4,Position(phi4));
  G4Transform3D transform5(r5,Position(phi5));
  G4Transform3D transform6(r6,Position(phi6));
//detector 0
  G4Tubs* Detector0
    = new G4Tubs("Detector0",
                 rMin,
                 rMax, 
                 hz,
                 phiMin,
                 phiMax);
  fLogicDetector0
    = new G4LogicalVolume(Detector0,
                          Ge,
                          "DetectorLogical0");
  new G4PVPlacement(transform0,
                    fLogicDetector0,
                    "DectectorReal0",
                    logicWorld,
                    false,
                    0,
                    true);
//detector 1
  G4Tubs* Detector1
    = new G4Tubs("Detector1",
                 rMin,
                 rMax,
                 hz,
                 phiMin,
                 phiMax);
  fLogicDetector1
    = new G4LogicalVolume(Detector1,
                          Ge,
                          "DetectorLogical1");
  new G4PVPlacement(transform1,
                    fLogicDetector1,
                    "DectectorReal1",
                    logicWorld,
                    false,
                    0,
                    true);
//detector 2
  G4Tubs* Detector2
    = new G4Tubs("Detector2",
                 rMin,
                 rMax,
                 hz,
                 phiMin,
                 phiMax);
  fLogicDetector2
    = new G4LogicalVolume(Detector2,
                          Ge,
                          "DetectorLogical2");
  new G4PVPlacement(transform2,
                    fLogicDetector2,
                    "DectectorReal2",
                    logicWorld,
                    false,
                    0,
                    true);
//detector 3
  G4Tubs* Detector3
    = new G4Tubs("Detector3",
                 rMin,
                 rMax,
                 hz,
                 phiMin,
                 phiMax);
  fLogicDetector3
    = new G4LogicalVolume(Detector3,
                          Ge,
                          "DetectorLogical3");
  new G4PVPlacement(transform3,
                    fLogicDetector3,
                    "DectectorReal3",
                    logicWorld,
                    false,
                    0,
                    true);
//detector 4
  G4Tubs* Detector4
    = new G4Tubs("Detector4",
                 rMin,
                 rMax,
                 hz,
                 phiMin,
                 phiMax);
  fLogicDetector4
    = new G4LogicalVolume(Detector4,
                          Ge,
                          "DetectorLogical4");
  new G4PVPlacement(transform4,
                    fLogicDetector4,
                    "DectectorReal4",
                    logicWorld,
                    false,
                    0,
                    true);
//detector 5
  G4Tubs* Detector5
    = new G4Tubs("Detector5",
                 rMin,
                 rMax,
                 hz,
                 phiMin,
                 phiMax);
  fLogicDetector5
    = new G4LogicalVolume(Detector5,
                          Ge,
                          "DetectorLogical5");
  new G4PVPlacement(transform5,
                    fLogicDetector5,
                    "DectectorReal5",
                    logicWorld,
                    false,
                    0,
                    true);
//detector 6
  G4Tubs* Detector6
    = new G4Tubs("Detector6",
                 rMin,
                 rMax,
                 hz,
                 phiMin,
                 phiMax);
  fLogicDetector6
    = new G4LogicalVolume(Detector6,
                          shape2_mat,
                          "DetectorLogical6");
  new G4PVPlacement(transform6,
                    fLogicDetector6,
                    "DectectorReal6",
                    logicWorld,
                    false,
                    0,
                    true);
        
//visualization
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
  gammaFilter->add("gamma");
  gammaFilter->show();

  G4SDParticleFilter* electronFilter = 
    new G4SDParticleFilter("electronFilter","e-");
  electronFilter->add("e-");
  electronFilter->show();

  G4SDParticleFilter* positronFilter =
    new G4SDParticleFilter("positronFilter","e+");
  positronFilter->add("e+");
  positronFilter->show();
//multifunctiondetector0
  G4MultiFunctionalDetector* det0 = 
    new G4MultiFunctionalDetector("DetectorLogical0");
  G4VPrimitiveScorer* pr0;
  pr0 = new G4PSEnergyDeposit("EdepOfPositron");
  pr0 ->SetFilter(positronFilter);
  det0->RegisterPrimitive(pr0);

  pr0 = new G4PSEnergyDeposit("EdepOfGamma");
  pr0 ->SetFilter(gammaFilter);
  det0->RegisterPrimitive(pr0);

  pr0 = new G4PSEnergyDeposit("EdepOfElectron");
  pr0 ->SetFilter(electronFilter);
  det0->RegisterPrimitive(pr0);

  pr0 = new G4PSNofSecondary("NofPositron");
  pr0 ->SetFilter(positronFilter);
  det0->RegisterPrimitive(pr0);
  
  G4SDManager::GetSDMpointer()->AddNewDetector(det0);
  fLogicDetector0->SetSensitiveDetector(det0);

//multifunctiondetector1 
  G4MultiFunctionalDetector* det1 = 
    new G4MultiFunctionalDetector("DetectorLogical1");
  G4VPrimitiveScorer* pr1;
  pr1 = new G4PSEnergyDeposit("EdepOfPositron");
  pr1 ->SetFilter(positronFilter);
  det1->RegisterPrimitive(pr1);

  pr1 = new G4PSEnergyDeposit("EdepOfGamma");
  pr1 ->SetFilter(gammaFilter);
  det1->RegisterPrimitive(pr1);

  pr1 = new G4PSEnergyDeposit("EdepOfElectron");
  pr1 ->SetFilter(electronFilter);
  det1->RegisterPrimitive(pr1);

  pr1 = new G4PSNofSecondary("NofPositron");
  pr1 ->SetFilter(positronFilter);
  det1->RegisterPrimitive(pr1);
  
  G4SDManager::GetSDMpointer()->AddNewDetector(det1);
  fLogicDetector1->SetSensitiveDetector(det1);
//multifunctiondetector2
  G4MultiFunctionalDetector* det2 =
    new G4MultiFunctionalDetector("DetectorLogical2");
  G4VPrimitiveScorer* pr2;
  pr2 = new G4PSEnergyDeposit("EdepOfPositron");
  pr2 ->SetFilter(positronFilter);
  det2->RegisterPrimitive(pr2);

  pr2 = new G4PSEnergyDeposit("EdepOfGamma");
  pr2 ->SetFilter(gammaFilter);
  det2->RegisterPrimitive(pr2);

  pr2 = new G4PSEnergyDeposit("EdepOfElectron");
  pr2 ->SetFilter(electronFilter);
  det2->RegisterPrimitive(pr2);

  pr2 = new G4PSNofSecondary("NofPositron");
  pr2 ->SetFilter(positronFilter);
  det2->RegisterPrimitive(pr2);

  G4SDManager::GetSDMpointer()->AddNewDetector(det2);
  fLogicDetector2->SetSensitiveDetector(det2);
//multifunctiondetector3
  G4MultiFunctionalDetector* det3 =
    new G4MultiFunctionalDetector("DetectorLogical3");
  G4VPrimitiveScorer* pr3;
  pr3 = new G4PSEnergyDeposit("EdepOfPositron");
  pr3->SetFilter(positronFilter);
  det3->RegisterPrimitive(pr3);

  pr3 = new G4PSEnergyDeposit("EdepOfGamma");
  pr3 ->SetFilter(gammaFilter);
  det3->RegisterPrimitive(pr3);

  pr3 = new G4PSEnergyDeposit("EdepOfElectron");
  pr3 ->SetFilter(electronFilter);
  det3->RegisterPrimitive(pr3);

  pr3 = new G4PSNofSecondary("NofPositron");
  pr3 ->SetFilter(positronFilter);
  det3->RegisterPrimitive(pr3);

  G4SDManager::GetSDMpointer()->AddNewDetector(det3);
  fLogicDetector3->SetSensitiveDetector(det3);
//multifunctiondetector4
  G4MultiFunctionalDetector* det4 =
    new G4MultiFunctionalDetector("DetectorLogical4");
  G4VPrimitiveScorer* pr4;
  pr4 = new G4PSEnergyDeposit("EdepOfPositron");
  pr4 ->SetFilter(positronFilter);
  det4->RegisterPrimitive(pr4);

  pr4 = new G4PSEnergyDeposit("EdepOfGamma");
  pr4 ->SetFilter(gammaFilter);
  det4->RegisterPrimitive(pr4);

  pr4 = new G4PSEnergyDeposit("EdepOfElectron");
  pr4 ->SetFilter(electronFilter);
  det4->RegisterPrimitive(pr4);

  pr4 = new G4PSNofSecondary("NofPositron");
  pr4 ->SetFilter(positronFilter);
  det4->RegisterPrimitive(pr4);

  G4SDManager::GetSDMpointer()->AddNewDetector(det4);
  fLogicDetector4->SetSensitiveDetector(det4);
//multifunctiondetector5
  G4MultiFunctionalDetector* det5 =
    new G4MultiFunctionalDetector("DetectorLogical5");
  G4VPrimitiveScorer* pr5;
  pr5 = new G4PSEnergyDeposit("EdepOfPositron");
  pr5 ->SetFilter(positronFilter);
  det5->RegisterPrimitive(pr5);

  pr5 = new G4PSEnergyDeposit("EdepOfGamma");
  pr5 ->SetFilter(gammaFilter);
  det5->RegisterPrimitive(pr5);

  pr5 = new G4PSEnergyDeposit("EdepOfElectron");
  pr5 ->SetFilter(electronFilter);
  det5->RegisterPrimitive(pr5);

  pr5 = new G4PSNofSecondary("NofPositron");
  pr5 ->SetFilter(positronFilter);
  det5->RegisterPrimitive(pr5);

  G4SDManager::GetSDMpointer()->AddNewDetector(det5);
  fLogicDetector5->SetSensitiveDetector(det5);
//multifunctiondetector6
  G4MultiFunctionalDetector* det6 =
    new G4MultiFunctionalDetector("DetectorLogical6");
  G4VPrimitiveScorer* pr6;
  pr6 = new G4PSEnergyDeposit("EdepOfPositron");
  pr6 ->SetFilter(positronFilter);
  det6->RegisterPrimitive(pr6);

  pr6 = new G4PSEnergyDeposit("EdepOfGamma");
  pr6 ->SetFilter(gammaFilter);
  det6->RegisterPrimitive(pr6);

  pr6 = new G4PSEnergyDeposit("EdepOfElectron");
  pr6 ->SetFilter(electronFilter);
  det6->RegisterPrimitive(pr6);

  pr6 = new G4PSNofSecondary("NofPositron");
  pr6 ->SetFilter(positronFilter);
  det6->RegisterPrimitive(pr6);

  G4SDManager::GetSDMpointer()->AddNewDetector(det6);
  fLogicDetector6->SetSensitiveDetector(det6);


}
G4ThreeVector S3DetectorConstruction::Position(G4double a)
{
  G4ThreeVector position 
    = G4ThreeVector(-std::sin(a)*30.*cm,std::cos(a)*30.*cm,0.);
  return position;
}
