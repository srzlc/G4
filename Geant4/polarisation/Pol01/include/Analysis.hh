#ifndef Analysis_h
#define Analysis_h 1
#include "globals.hh"
#include <fstream>
#include <iostream>
using namespace std;
class Analysis
{
  public:
    Analysis();
    virtual ~Analysis();
    void Book();
    void Save();
    void Record(G4double a);
  private: 
    ofstream GammaEnergy;
};
#endif
