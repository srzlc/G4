#ifndef SInput_h
#define SInput_h 1
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include <fstream>
#include "G4UnitsTable.hh"
using namespace std;
class SInput
{
  public:
             SInput();
    virtual ~SInput();
    G4double Choose(G4int nOfEvent);
    void Readdata();
    G4ThreeVector PositionChoose(G4int nOfEvent);
  private:
    ifstream input;
    G4double energy[1000000];
    G4double x[1000000];
    G4double y[1000000];
    G4double z[1000000];
};
#endif
