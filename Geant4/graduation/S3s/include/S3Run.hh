#ifndef S3Run_h
#define S3Run_h 1
#include "globals.hh"
#include "G4Run.hh"
#include "G4Event.hh"
#include "G4THitsMap.hh"
class S3Run : public G4Run
{
  public:
             S3Run();
    virtual ~S3Run();
    virtual void RecordEvent(const G4Event*);
    virtual void Merge(const G4Run*);
    G4double GetNOfPositron() const {return GetTotal(nOfPositron);}    
  private:
    G4int nOfPositronID;
    G4THitsMap<G4double> nOfPositron;
    G4double GetTotal(const G4THitsMap<G4double> &map) const;
};
#endif

