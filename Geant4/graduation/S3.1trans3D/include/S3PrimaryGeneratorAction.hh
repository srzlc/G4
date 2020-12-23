/// \file S3PrimaryGeneratorAction.hh
/// \brief Definition of the S3PrimaryGeneratorAction class

#ifndef S3PrimaryGeneratorAction_h
#define S3PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;
class S3DetectorConstruction;
/// The primary generator action class with particle gun.
class S3PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
             S3PrimaryGeneratorAction(S3DetectorConstruction*);    
    virtual ~S3PrimaryGeneratorAction();

  // method from the base class
    virtual void GeneratePrimaries(G4Event*);         
  
  // method to access particle gun
    const G4ParticleGun* GetParticleGun() const { return fParticleGun;}
  private:
    G4ParticleGun*  fParticleGun;   // pointer a to G4 gun class
  //  G4ThreeVector GenerateDirection();
  //  G4ThreeVector GeneratePosition();
    
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
