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
  G4double worldZHalfLength = 0.;
  G4LogicalVolume* world
    = G4LogicalVolumeStore::GetInstance()->GetVolume("WorldLogical");
  G4Box* worldBox = NULL;
  if(world)    worldBox         = dynamic_cast<G4Box*>(world->GetSolid());
  if(worldBox) worldZHalfLength = worldBox->GetZHalfLength();
  else
    {
    G4cerr << "World volume of box not found." << G4endl;
    G4cerr << "Perhaps you have changed geometry." << G4endl;
    G4cerr << "The gun will be place in the center." << G4endl;
    }
  fParticleGun->SetParticlePosition(G4ThreeVector((G4UniformRand()-0.5)*4.e-1*cm,(G4UniformRand()-0.5)*4.e-1*cm,-worldZHalfLength));
//  fParticleGun->SetParticlePosition(G4ThreeVector(1.*cm,0.,0.));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,worldZHalfLength));
  fParticleGun->GeneratePrimaryVertex(anEvent);
}

