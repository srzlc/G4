/// \file S3PrimaryGeneratorAction.cc
/// \brief Implementation of the S3PrimaryGeneratorAction class

#include "S3PrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4PhysicalConstants.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

S3PrimaryGeneratorAction::S3PrimaryGeneratorAction(S3DetectorConstruction*)
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0)
 
{
//set particle gun 
  G4int n_particle= 1;
  fParticleGun  = new G4ParticleGun(n_particle);
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="e-");
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleEnergy(100.*MeV);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
S3PrimaryGeneratorAction::~S3PrimaryGeneratorAction()
{
  delete fParticleGun;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void S3PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  G4double worldXHalfLength = 0.;
  G4LogicalVolume* world
    = G4LogicalVolumeStore::GetInstance()->GetVolume("WorldLogical");
  G4Box* worldBox = NULL;
  if(world)    worldBox         = dynamic_cast<G4Box*>(world->GetSolid());
  if(worldBox) worldXHalfLength = worldBox->GetXHalfLength();
  else
    {
    G4cerr << "World volume of box not found." << G4endl;
    G4cerr << "Perhaps you have changed geometry." << G4endl;
    G4cerr << "The gun will be place in the center." << G4endl;
    }
  fParticleGun->SetParticlePosition(G4ThreeVector(worldXHalfLength,(G4UniformRand()-0.5)*4.e-1*cm,(G4UniformRand()-0.5)*4.e-1*cm));
//  fParticleGun->SetParticlePosition(G4ThreeVector(1.*cm,0.,0.));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(-worldXHalfLength,0.,0.));
  fParticleGun->GeneratePrimaryVertex(anEvent);
}

/*   G4ThreeVector S3PrimaryGeneratorAction::GenerateDirection()
{
G4double phi=pi/48.*rad;
G4double theta=G4UniformRand()*2.*pi*rad;
G4double PX=-cos(phi);
G4double PY=sin(phi)*sin(theta);
G4double PZ=sin(phi)*cos(theta);
return G4ThreeVector(PX,PY,PZ);
}

   G4ThreeVector S3PrimaryGeneratorAction::GeneratePosition()
{
G4double x,y,z;
y=0.0,z=0.0;
x=(G4UniformRand()-1)*5.*cm;
return G4ThreeVector(x,y,z);
}*/
