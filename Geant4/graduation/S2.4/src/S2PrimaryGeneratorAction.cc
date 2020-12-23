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
//  fParticleGun1(0), 
//  fParticleGun2(0)
{
//set particle gun 
  G4int n_particle= 1;
  fParticleGun  = new G4ParticleGun(n_particle);
//  fParticleGun1 = new G4ParticleGun(n_particle);
//  fParticleGun2 = new G4ParticleGun(n_particle);
 // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="e-");
  fParticleGun->SetParticleDefinition(particle);
//   G4String particleName1;
//  G4ParticleDefinition* particle1
//    = particleTable->FindParticle(particleName1="e-");
//  fParticleGun1->SetParticleDefinition(particle1);
//   G4String particleName2;
//  G4ParticleDefinition* particle2
//    = particleTable->FindParticle(particleName2="e+");
//  fParticleGun2->SetParticleDefinition(particle2);
 // fParticleGun->SetParticleEnergy(CLHEP::RandPoisson::shoot(100.*MeV));
// fParticleGun1->SetParticleEnergy(40.*MeV);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
S2PrimaryGeneratorAction::~S2PrimaryGeneratorAction()
{
//   delete fParticleGun1;
//   delete fParticleGun2;
   delete fParticleGun;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void S2PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
 // fParticleGun->SetParticlePosition(GeneratePosition());
 // fParticleGun->SetParticleMomentumDirection(GenerateDirection());
  fParticleGun->SetParticlePosition(G4ThreeVector(1.*cm,0.,0.));
  fParticleGun->SetParticleMomentumDirection(GenerateDirection());
  fParticleGun->SetParticleEnergy(GenerateE());
  fParticleGun->GeneratePrimaryVertex(anEvent);
 
// fParticleGun1->SetParticlePosition(G4ThreeVector(10.*cm,0.,1.*cm));
//  fParticleGun1->SetParticleMomentumDirection(GenerateDirection());
//  fParticleGun1->GeneratePrimaryVertex(anEvent);
  
//  fParticleGun2->SetParticlePosition(G4ThreeVector(10.*cm,0.,-1.*cm));
//  fParticleGun2->SetParticleMomentumDirection(GenerateDirection());
//  fParticleGun2->SetParticleEnergy(GenerateE());
//  fParticleGun2->GeneratePrimaryVertex(anEvent);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
   G4double S2PrimaryGeneratorAction::GenerateE()
{
G4double e=CLHEP::RandGauss::shoot(100.*MeV,10*MeV);
if(e>300.*MeV){e=0.;}
if(e<50.*MeV){
e=(CLHEP::RandFlat::shoot()+1.)*50.*MeV; 
}
return e;

}
///////////////////////////////////////
   G4ThreeVector S2PrimaryGeneratorAction::GenerateDirection()
{
G4double phi=pi/1024.*rad;
G4double theta=G4UniformRand()*2.*pi*rad;
G4double PX=-cos(phi);
G4double PY=sin(phi)*sin(theta);
G4double PZ=sin(phi)*cos(theta);
return G4ThreeVector(PX,PY,PZ);
}

//   G4double S2PrimaryGeneratorAction::GeneratePosition()
//{
//G4double e=CLHEP::RandPoisson::shoot(85.*MeV);
//if(e>300.*MeV){e=0.;}

//x=(G4UniformRand()-1)*5.*cm;
//return e;
//}
