#include "Analysis.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

Analysis::Analysis()
{}
Analysis::~Analysis()
{}
void Analysis::Book()
{
  GammaEnergy.open("GammaEnergy.txt",std::ios::app);
}
void Analysis::Save()
{
  GammaEnergy.close();
}
void Analysis::Record(G4double a)
{
  if (GammaEnergy.is_open())
  {
    GammaEnergy<<a<<G4endl;
  }
}
