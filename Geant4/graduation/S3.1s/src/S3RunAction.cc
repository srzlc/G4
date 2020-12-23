#include "S3RunAction.hh"
#include "G4RunManager.hh"
#include "S3Analysis.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4Track.hh"
#include <iostream>
#include <stdio.h>
using namespace std;
////////////
S3RunAction::S3RunAction() : G4UserRunAction()
{ 
}
///////////
S3RunAction::~S3RunAction()
{ 
}
void S3RunAction::BeginOfRunAction(const G4Run*)
{
}
void S3RunAction::EndOfRunAction(const G4Run*)
{
}
