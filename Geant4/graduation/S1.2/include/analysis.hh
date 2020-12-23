#ifndef analysis_h
#define analysis_h 1
#include "globals.hh"
#include <fstream>
#include <iostream>
using namespace std;
class analysis
{
  public:
  analysis();
  ~analysis();
  void Book();
  void Save();
  void RecordValue(G4double a,G4String name);
  void Add(G4double a);
private:
  ofstream output;
  G4double Sum=0;
};
#endif
