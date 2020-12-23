#ifndef S2PrimaryGeneratorAction_h
#define S2PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;

/// The primary generator action class with particle gun.
class S2PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    S2PrimaryGeneratorAction();    
    virtual ~S2PrimaryGeneratorAction();

    // method from the base class
    virtual void GeneratePrimaries(G4Event* event);         
  
  private:
    G4ParticleGun*  fParticleGun;   // pointer a to G4 gun class
//    G4ParticleGun*  fParticleGun1; 
//    G4ParticleGun*  fParticleGun2; 
     G4ThreeVector GenerateDirection();
//    G4double GeneratePosition();
//    G4double GenerateE();
};


#endif
