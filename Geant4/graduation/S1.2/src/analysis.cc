#include "analysis.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
///////////////
analysis::analysis()
{}
analysis::~analysis()
{}
void analysis::Book()
{
output.open("test.txt");
}
void analysis::Add(G4double a)
{
Sum+=a;
output<<"Sum="<<Sum<<endl;
}
void analysis::Save()
{
output.close();
}
void analysis::RecordValue(G4double a,G4String name)
{
output<<name<<"\t"<<a<<endl;
}

