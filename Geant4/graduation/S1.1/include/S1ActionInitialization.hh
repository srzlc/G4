#ifndef S1ActionInitialization_h
#define S1ActionInitialization_h 1
#include "G4VUserActionInitialization.hh"

class S1ActionInitialization : public G4VUserActionInitialization
{
public:
S1ActionInitialization();
virtual ~S1ActionInitialization();
virtual void BuildForMaster() const;
virtual void Build() const;
};
#endif
