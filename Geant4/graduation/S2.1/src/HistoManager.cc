#include "HistoManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
/////////////
HistoManager::HistoManager()
  : fFileName("S2")
{
  Book();
}
/////////////
HistoManager::~HistoManager()
{
  //  delete G4AnalysisManager::Instance();
}
/////////////
void HistoManager::Book()
{
  // Create or get analysis manager
  // The choice of analysis technology is done via selection of a namespace
  // in HistoManager.hh
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetFileName(fFileName);
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetActivation(true);     //enable inactivation of histograms
  
  // Define histograms start values
  const G4String id[] = {"0","1","2","3"};
  const G4String title[] = 
                { "KinE of Primary Electron",                       //0
                  "KinE of Gamma",                                  //1
                  "kinE of Secondary Electron",                     //2
                  "KinE of Positron",                               //3
                };
// Default values (to be reset via /analysis/h1/set command)               
  G4int nbins = 500;
  G4double vmin = 0.;
  G4double vmax = 200.*MeV;
// Create all histograms as inactivated 
  // as we have not yet set nbins, vmin, vmax
  for (G4int k=0; k<4; k++) {
    G4int ih = analysisManager->CreateH1(id[k], title[k], nbins, vmin, vmax);
    analysisManager->SetH1Activation(ih, false);
  }
}
