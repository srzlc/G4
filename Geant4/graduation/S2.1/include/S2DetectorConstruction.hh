#ifndef S2DetectorConstruction_h
#define S2DetectorConstruction_h 1
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
class G4VPhysicalVolume;
class G4LogicalVolume;
/////////////
class S2DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
   S2DetectorConstruction();
   virtual ~S2DetectorConstruction();
   virtual G4VPhysicalVolume* Construct();
   G4LogicalVolume* GetScoringVolume() const {return fScoringVolume; }
 protected:
   G4LogicalVolume* fScoringVolume;
};
/////////////
#endif
