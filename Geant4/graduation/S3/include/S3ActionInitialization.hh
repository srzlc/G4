#ifndef S3ActionInitialization_h
#define S3ActionInitialization_h 1
#include "G4VUserActionInitialization.hh"
class S3DetectorConstruction;
class S3ActionInitialization : public G4VUserActionInitialization
{
  public:
             S3ActionInitialization(S3DetectorConstruction*);
    virtual ~S3ActionInitialization();
    virtual void BuildForMaster() const;
    virtual void Build() const;
  private:
    S3DetectorConstruction* det;
};
#endif
