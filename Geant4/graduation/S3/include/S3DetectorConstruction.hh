#ifndef S3DetectorConstruction_h
#define S3DetectorConstruction_h 1
#include "G4VUserDetectorConstruction.hh"
#include "G4Cache.hh"
#include "globals.hh"
#include "tls.hh"
class G4VPhysicalVolume;
class G4LogicalVolume;
//class S2TrackerSD;
/////////////
class S3DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
             S3DetectorConstruction();
    virtual ~S3DetectorConstruction();
    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();
  private:
//    G4Cache<S3TrackerSD*> fTrackerSD;
    G4LogicalVolume*      logicShape2; 
};
/////////////
#endif
