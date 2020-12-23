#ifndef S2TrackerHit_h
#define S2TrackerHit_h 1
#include "G4VHit.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4Threading.hh"
#include "G4THitsCollection.hh"
//It defines data members to store the the energy deposit and track lengths
// of charged particles in a selected volume:
// - fEdep, fTrackLength
class S2TrackerHit : public G4VHit
{
public:
  S2TrackerHit();
  S2TrackerHit(const S2TrackerHit&);
  virtual ~S2TrackerHit();
  //operators
  const S2TrackerHit& operator=(const S2TrackerHit&);
  G4bool operator==(const S2TrackerHit&) const;
  inline void* operator new(size_t);
  inline void  operator delete(void*);
  //methods from base class
 // virtual void Draw();
 // virtual void Print();
  //methods to handle data
  void Add(G4double de,G4double dl);
  //get methods
  G4double GetEdep() const;
  G4double GetTrackLength() const;
private:
  G4double fEdep;
  G4double fTrackLength;
};
using S2TrackerHitsCollection = G4THitsCollection<S2TrackerHit>;
extern G4ThreadLocal G4Allocator<S2TrackerHit>* S2TrackerHitAllocator;
inline void* S2TrackerHit::operator new(size_t)
{
  if(!S2TrackerHitAllocator){
    S2TrackerHitAllocator = new G4Allocator<S2TrackerHit>;
   }
   void *hit;
   hit = (void *) S2TrackerHitAllocator->MallocSingle();
   return hit;
}
inline void S2TrackerHit::operator delete(void *hit)
{
  if(!S2TrackerHitAllocator){
    S2TrackerHitAllocator = new G4Allocator<S2TrackerHit>;
   }
   S2TrackerHitAllocator->FreeSingle((S2TrackerHit*)hit); 
}
inline void S2TrackerHit::Add(G4double de,G4double dl)
{
   fEdep+=de;
   fTrackLength+=dl;
}
inline G4double S2TrackerHit::GetEdep() const
{
return fEdep;
}
inline G4double S2TrackerHit::GetTrackLength() const
{
return fTrackLength;
}
#endif


