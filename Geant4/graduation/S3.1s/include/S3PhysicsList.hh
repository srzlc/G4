#ifndef S3PhysicsList_h
#define S3PhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "globals.hh"
class PhysicsConstructor;
////////////////////
class S3PhysicsList: public G4VModularPhysicsList
{
  public:
             S3PhysicsList();
    virtual ~S3PhysicsList();
  //construct particle and physics
    virtual void ConstructParticle();
    virtual void ConstructProcess();
    virtual void SetCuts();
            void AddDecay();
  private:
    G4VPhysicsConstructor* fEmPhysicsList;
    G4String               fEmName;
};
#endif
