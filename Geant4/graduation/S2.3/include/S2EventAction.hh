#ifndef S2EventAction_h
#define S2EventAction_h 1
#include "G4UserEventAction.hh"
#include "globals.hh"
class S2EventAction : public G4UserEventAction
{
public:
   S2EventAction();
   virtual ~S2EventAction();
   virtual void BeginOfEventAction(const G4Event* event);
   virtual void EndOfEventAction(const G4Event* event);
   void AddGamma(G4double de);
   void AddElectron(G4double de);
   void AddPositron(G4double de);
private:
   G4double fGenergy;
   G4double fEenergy;
   G4double fPenergy;
};
inline void S2EventAction::AddGamma(G4double de)
{
fGenergy+=de;
}
inline void S2EventAction::AddElectron(G4double de)
{
fEenergy+=de;
}
inline void S2EventAction::AddPositron(G4double de)
{
fPenergy+=de;
}
#endif
