#include "RunActionMaster.hh"
#include "G4MPImanager.hh"
#include "G4Threading.hh"
#include <iostream>
#include "Analysis.hh"
#include "G4MPIhistoMerger.hh"
#include "G4Run.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
RunActionMaster::RunActionMaster()
{
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
RunActionMaster::~RunActionMaster()
{
  delete G4AnalysisManager::Instance();
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void RunActionMaster::BeginOfRunAction(const G4Run* aRun)
{
  G4cout << "RunMaster### Run " << aRun->GetRunID() << " start." << G4endl;
  auto fAnalysisManager = G4AnalysisManager::Instance();
//  fAnalysisManager->SetActivation(true);
  fAnalysisManager->SetVerboseLevel(1);
  
  fAnalysisManager->SetFirstHistoId(1);
  // Creating an 1-dimensional histograms in the root directory of the tree
  fAnalysisManager->CreateH1("h1","Initial Gamma Energy",120,0.,30.*MeV);
  fAnalysisManager->CreateH1("h2","Positron Energy",120,0.,30.*MeV);
  fAnalysisManager->CreateH1("h3","xPolarization",120,-1.5,1.5);
  fAnalysisManager->CreateH1("h4","yPolarization",120,-1.5,1.5);
  fAnalysisManager->CreateH1("h5","longitudinalPolarization",120,-1.5,1.5);
  fAnalysisManager->CreateH2("Position","Initial Gamma Position",120,-0.2*mm,0.2*mm,120,-0.02*mm,0.02*mm);
  fAnalysisManager->CreateH2("h6","Fig.6.",120,0.,30.*MeV,120,-1.5,1.5);
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void RunActionMaster::EndOfRunAction(const G4Run* arun)
{
  const G4int rank = G4MPImanager::GetManager()->GetRank();
  G4cout<<"======================================================"<<G4endl;
  G4cout<<"Start EndOfRunAction for master thread in rank: "<<rank<<G4endl;
  G4cout<<"======================================================"<<G4endl;
  //Save g4analysis objects to a file
  G4MPIhistoMerger hm(G4AnalysisManager::Instance());
  hm.SetVerbosity(1);
  hm.Merge();
  if(true)
  {
    std::ostringstream fname;
    fname<<"rank"<<rank;
    if(rank == 0)
    {
      fname.str("rank-merged");
      auto fAnalysisManager = G4AnalysisManager::Instance();
      fAnalysisManager->OpenFile(fname.str());
      fAnalysisManager->Write();
      fAnalysisManager->CloseFile();  
    }
  }  
  G4cout<<"======================================================"<<G4endl;
  G4cout<<"End EndOfRunAction for master thread in rank: "<<rank<<G4endl;
  G4cout<<"======================================================"<<G4endl;

} 
