//
//
/// \file S1PrimaryGeneratorAction.cc
/// \brief Implementation of the S1PrimaryGeneratorAction class

#include "S1PrimaryGeneratorAction.hh"

//#include "G4LogicalVolumeStore.hh"
//#include "G4LogicalVolume.hh"
//#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4PhysicalConstants.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

S1PrimaryGeneratorAction::S1PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun1(0),fParticleGun2(0) 
 // fEnvelopeBox(0)
{
  G4int n_particle1= 1,n_particle2=1;
  fParticleGun1  = new G4ParticleGun(n_particle1);
  fParticleGun2  = new G4ParticleGun(n_particle2);
  // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName1,particleName2;
  G4ParticleDefinition* particle1
    = particleTable->FindParticle(particleName1="gamma");
  fParticleGun1->SetParticleDefinition(particle1);
  fParticleGun1->SetParticleEnergy(20.*MeV);
  G4ParticleDefinition* particle2
    = particleTable->FindParticle(particleName2="e-" );
  fParticleGun2->SetParticleDefinition(particle2);
  fParticleGun2->SetParticleEnergy(10.*MeV);
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
S1PrimaryGeneratorAction::~S1PrimaryGeneratorAction()
{
  delete fParticleGun1;
  delete fParticleGun2;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void S1PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  //this function is called at the begining of ecah event
  //

  // In order to avoid dependence of PrimaryGeneratorAction
  // on DetectorConstruction class we get Envelope volume
  // from G4LogicalVolumeStore.
  
 // G4double envSizeXY = 0;
 // G4double envSizeZ = 0;

 // if (!fEnvelopeBox)
 // {
 //   G4LogicalVolume* envLV
 //     = G4LogicalVolumeStore::GetInstance()->GetVolume("Envelope");
 //   if ( envLV ) fEnvelopeBox = dynamic_cast<G4Box*>(envLV->GetSolid());
 // }

 // if ( fEnvelopeBox ) {
 //   envSizeXY = fEnvelopeBox->GetXHalfLength()*2.;
 //   envSizeZ = fEnvelopeBox->GetZHalfLength()*2.;
 // }  
 // else  {
 //   G4ExceptionDescription msg;
 //   msg << "Envelope volume of box shape not found.\n"; 
 //   msg << "Perhaps you have changed geometry.\n";
 //   msg << "The gun will be place at the center.";
 //   G4Exception("B1PrimaryGeneratorAction::GeneratePrimaries()",
 //    "MyCode0002",JustWarning,msg);
 // }

 // G4double size = 0.8; 
 // G4double x0 = size * envSizeXY * (G4UniformRand()-0.5);
 // G4double y0 = size * envSizeXY * (G4UniformRand()-0.5);
 // G4double z0 = -0.5 * envSizeZ;
  
 // fParticleGun->SetParticlePosition(GeneratePosition());
 // fParticleGun->SetParticleMomentumDirection(GenerateDirection());
   fParticleGun1->SetParticlePosition(G4ThreeVector(10.*cm,0.,0.));
  fParticleGun2->SetParticlePosition(G4ThreeVector(10.*cm,0.,3.*cm));
  fParticleGun1->SetParticleMomentumDirection(GenerateDirection());
  fParticleGun2->SetParticleMomentumDirection(GenerateDirection());
  fParticleGun1->GeneratePrimaryVertex(anEvent);
  fParticleGun2->GeneratePrimaryVertex(anEvent);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
   G4ThreeVector S1PrimaryGeneratorAction::GenerateDirection()
{
G4double phi=pi/48.*rad;
G4double theta=G4UniformRand()*2.*pi*rad;
G4double PX=-cos(phi);
G4double PY=sin(phi)*sin(theta);
G4double PZ=sin(phi)*cos(theta);
return G4ThreeVector(PX,PY,PZ);
}

   G4ThreeVector S1PrimaryGeneratorAction::GeneratePosition()
{
G4double x,y,z;
y=0.0,z=0.0;
x=(G4UniformRand()-1)*5.*cm;
return G4ThreeVector(x,y,z);
}
