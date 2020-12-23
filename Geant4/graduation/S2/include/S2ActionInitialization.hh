#ifndef S2ActionInitialization_h
#define S2ActionInitialization_h 1
#include "G4VUserActionInitialization.hh"

class S2ActionInitialization : public G4VUserActionInitialization
{
public:
S2ActionInitialization();
virtual ~S2ActionInitialization();
virtual void BuildForMaster() const;
virtual void Build() const;
};
#endif
