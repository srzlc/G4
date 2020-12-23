#ifndef S1DetectorConstruction_h
#define S1DetectorConstruction_h 1
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
class G4VPhysicalVolume;
class G4LogicalVolume;
/////////////
class S1DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
   S1DetectorConstruction();
   virtual ~S1DetectorConstruction();
   virtual G4VPhysicalVolume* Construct();
   G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }
  protected:
   G4LogicalVolume* fScoringVolume; 
};
/////////////
#endif
