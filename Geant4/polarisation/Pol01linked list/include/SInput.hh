#ifndef SInput_h
#define SInput_h 1
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include <fstream>
#include "G4UnitsTable.hh"
using namespace std;
typedef struct node
{
  G4double energy;
  G4double x;
  G4double y;
  G4double z;
  struct node* next;
}Data;
class SInput
{
  public:
             SInput();
    virtual ~SInput();
    G4double Choose();
    void OpenFile();
    void CloseFile();
    void ReadData();
    void RefreshData();
    void Changenode();
    G4ThreeVector PositionChoose();
  private:
    ifstream input;
    Data* pNow;
    Data* pFresh;
    Data* head;
};
#endif
