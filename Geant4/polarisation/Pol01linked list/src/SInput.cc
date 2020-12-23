//当在超算上运行时可设置链表大小为1百万
#include "SInput.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include <iomanip>
#include "G4PhysicalConstants.hh"
//////////////
SInput::SInput():pNow(0),pFresh(0),head(0)
{
  head = new Data;
}
SInput::~SInput()
{
}
void SInput::OpenFile()
{
  input.open("InitialGamma.txt",ios::in);
}
void SInput::CloseFile()
{
  input.close();
}
void SInput::ReadData()
{
  Data* pre  = head;
  if(!input.is_open()) return;
  for(int i=0;i<10000;++i)
  {
    Data* p = new Data;
    input>>p->energy>>p->x>>p->y>>p->z;
    pre->next = p;
    pre = p;
    p->next = nullptr;
  }
  pNow =  head;
}
void SInput::RefreshData()
{
  pFresh = head;
  if(!input.is_open()) return;
  for(int i=0;i<10000;++i)
  {
    pFresh=pFresh->next;
    input>>pFresh->energy>>pFresh->x>>pFresh->y>>pFresh->z;
  }
  pNow = head;
}
G4double SInput::Choose()
{
  G4double E;
  E = pNow->energy;
  return E;
}
G4ThreeVector SInput::PositionChoose()
{
  G4double PX = pNow->x;
  G4double PY = pNow->y;
  G4double PZ = pNow->z; 
  return G4ThreeVector(PX*mm,PY*mm,(PZ-50)*mm);
}
void SInput::Changenode()
{
  pNow = pNow->next;
  if (pNow == nullptr)
  {
    SInput::RefreshData(); 
  }
}
