#include "S2TrackerHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include <iomanip>
G4ThreadLocal G4Allocator<S2TrackerHit>* S2TrackerHitAllocator = 0;
//////
S2TrackerHit::S2TrackerHit() : G4VHit(),fEdep(0.),fTrackLength(0.)
{}
S2TrackerHit::~S2TrackerHit() {}
//////
S2TrackerHit::S2TrackerHit(const S2TrackerHit& right) : G4VHit()
{
  fEdep           = right.fEdep;
  fTrackLength  = right.fTrackLength;
}
//////
const S2TrackerHit& S2TrackerHit::operator=(const S2TrackerHit& right)
{
  fEdep        = right.fEdep;
  fTrackLength = right.fTrackLength;
  return* this;
}
G4bool S2TrackerHit::operator==(const S2TrackerHit& right) const
{
  return (this == &right) ? true : false;
}

