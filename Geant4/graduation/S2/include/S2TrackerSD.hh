/// \file S2TrackerSD.hh
/// \brief Definition of the S2TrackerSD class

#ifndef S2TrackerSD_h
#define S2TrackerSD_h 1

#include "G4VSensitiveDetector.hh"

#include "S2TrackerHit.hh"

#include <vector>

class G4Step;
class G4HCofThisEvent;

///sensitive detector class
///
/// In Initialize(), it creates one hit for each calorimeter layer and one more
/// hit for accounting the total quantities in all layers.
///
/// The values are accounted in hits in ProcessHits() function which is called
/// by Geant4 kernel at each step.

class S2TrackerSD : public G4VSensitiveDetector
{
  public:
    S2TrackerSD(const G4String& name, 
                     const G4String& hitsCollectionName);
    virtual ~S2TrackerSD();
  
    // methods from base class
    virtual void   Initialize(G4HCofThisEvent* hitCollection);
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
    virtual void   EndOfEvent(G4HCofThisEvent* hitCollection);

  private:
    S2TrackerHitsCollection* fHitsCollection;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

