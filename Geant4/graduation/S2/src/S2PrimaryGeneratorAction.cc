/// \file S2PrimaryGeneratorAction.cc
/// \brief Implementation of the S2PrimaryGeneratorAction class

#include "S2PrimaryGeneratorAction.hh"

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

S2PrimaryGeneratorAction::S2PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0)
 
{
//set particle gun 
  G4int n_particle= 1;
  fParticleGun  = new G4ParticleGun(n_particle);
  // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="e-");
  fParticleGun->SetParticleDefinition(particle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
S2PrimaryGeneratorAction::~S2PrimaryGeneratorAction()
{
  delete fParticleGun;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void S2PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
 // fParticleGun->SetParticlePosition(GeneratePosition());
 // fParticleGun->SetParticleMomentumDirection(GenerateDirection());
  fParticleGun->SetParticlePosition(G4ThreeVector(1.*cm,0.,0.));
  fParticleGun->SetParticleMomentumDirection(GenerateDirection());
  fParticleGun->SetParticleEnergy(CLHEP::RandPoisson::shoot(100.*MeV));
  fParticleGun->GeneratePrimaryVertex(anEvent);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
   G4ThreeVector S2PrimaryGeneratorAction::GenerateDirection()
{
G4double phi=pi/48.*rad;
G4double theta=G4UniformRand()*2.*pi*rad;
G4double PX=-cos(phi);
G4double PY=sin(phi)*sin(theta);
G4double PZ=sin(phi)*cos(theta);
return G4ThreeVector(PX,PY,PZ);
}

   G4ThreeVector S2PrimaryGeneratorAction::GeneratePosition()
{
G4double x,y,z;
y=0.0,z=0.0;
x=(G4UniformRand()-1)*5.*cm;
return G4ThreeVector(x,y,z);
}
