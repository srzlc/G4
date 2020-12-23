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
   //get methods
   const G4VPhysicalVolume* GetPV() const; 
  private:
  //methods
  G4VPhysicalVolume* fShape2;
};
/////////////
//inline functions
inline const G4VPhysicalVolume* S2DetectorConstruction::GetPV() const
{
return fShape2;
}
#endif
