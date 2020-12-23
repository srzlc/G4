#include "SInput.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include <iomanip>
#include "G4PhysicalConstants.hh"
//////////////
SInput::SInput()
{}
SInput::~SInput()
{}
void SInput::Readdata()
{
  input.open("InitialGamma.txt",ios::in);
  if(!input.is_open()) return;
  for(int i=0;i<1000000;++i)
  {
    input>>energy[i]>>x[i]>>y[i]>>z[i];
  }
  input.close();
}
G4double SInput::Choose(G4int nOfEvent)
{
  G4double E;
  E = energy[nOfEvent];
  return E;
}
G4ThreeVector SInput::PositionChoose(G4int nOfEvent)
{
  G4double PX = x[nOfEvent]*mm;
  G4double PY = y[nOfEvent]*mm;
  G4double PZ = (z[nOfEvent]-50)*mm; 
  return G4ThreeVector(PX,PY,PZ);
}
