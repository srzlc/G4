#ifndef S2PhysicsList_h
#define S2PhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "globals.hh"
class PhysicsConstructor;
////////////////////
class S2PhysicsList: public G4VModularPhysicsList
{
  public:
             S2PhysicsList();
    virtual ~S2PhysicsList();
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
