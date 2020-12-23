#ifndef S3DetectorConstruction_h
#define S3DetectorConstruction_h 1
#include "G4ThreeVector.hh"
#include "G4VUserDetectorConstruction.hh"
//#include "G4Cache.hh"
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
//    G4Cache<S2TrackerSD*> fTrackerSD;
    G4LogicalVolume*      fLogicDetector0; 
    G4LogicalVolume*      fLogicDetector1;
    G4LogicalVolume*      fLogicDetector2;
    G4LogicalVolume*      fLogicDetector3;
    G4LogicalVolume*      fLogicDetector4;
    G4LogicalVolume*      fLogicDetector5;
    G4LogicalVolume*      fLogicDetector6;
    G4ThreeVector Position(G4double a);
};
/////////////
#endif
