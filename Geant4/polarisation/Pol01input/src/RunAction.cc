//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file polarisation/Pol01/src/RunAction.cc
/// \brief Implementation of the RunAction class
//
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "RunAction.hh"

#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "G4ParticleDefinition.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4EmCalculator.hh"

#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include <iomanip>
#include "SInput.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction(DetectorConstruction* det, PrimaryGeneratorAction* prim,SInput* inp)
: G4UserRunAction(),
  fGamma(0), fElectron(0), fPositron(0),
  fDetector(det), fPrimary(prim), fProcCounter(0), fAnalysisManager(0), 
  fTotalEventCount(0),
  fPhotonStats(), fElectronStats(), fPositronStats(),fInput(inp)
{
  fGamma = G4Gamma::Gamma();
  fElectron = G4Electron::Electron();
  fPositron = G4Positron::Positron();

  BookHisto();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* aRun)
{  
  G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
  
  // save Rndm status
  //  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
  //  CLHEP::HepRandom::showEngineStatus();
  fInput->Readdata();  
  if (fProcCounter) delete fProcCounter;
  fProcCounter = new ProcessesCount;
  fTotalEventCount = 0;
  fPhotonStats.Clear();
  fElectronStats.Clear();
  fPositronStats.Clear();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::FillData(const G4ParticleDefinition* particle,
                         G4double kinEnergy,
                         G4double xPolarization,
                         G4double yPolarization,
                         G4double longitudinalPolarization)
{ 
 if (particle == fGamma) { 
    fPhotonStats.FillData(kinEnergy, longitudinalPolarization); 
  }
  else if (particle == fElectron) { 
    fElectronStats.FillData(kinEnergy, longitudinalPolarization);
  } 
  else if (particle == fPositron) {
    fPositronStats.FillData(kinEnergy, longitudinalPolarization);
    fAnalysisManager->FillH1(2,kinEnergy,1.0);
    fAnalysisManager->FillH1(3,xPolarization,1.0);
    fAnalysisManager->FillH1(4,yPolarization,1.0);   
    fAnalysisManager->FillH1(5,longitudinalPolarization,1.0);
    fAnalysisManager->FillH2(2,kinEnergy,longitudinalPolarization,1.0);
//    G4cout<<kinEnergy<<"============================="<<G4endl;
  }
}
void RunAction::Fill(G4double gammaKinEnergy,G4double x,G4double y)
{
  fAnalysisManager->FillH1(1,gammaKinEnergy,1.0);
  fAnalysisManager->FillH2(1,x,y,1.0);
//  G4cout<<gammaKinEnergy<<"+++++++++++++++++++++++++++"<<G4endl;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BookHisto()
{
  // Always creating analysis manager
  fAnalysisManager = G4AnalysisManager::Instance();
//  fAnalysisManager->SetActivation(true);
  fAnalysisManager->SetVerboseLevel(1);

  // Open file histogram file
  fAnalysisManager->OpenFile("pol01");
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

void RunAction::SaveHisto(G4int nevents)
{
  if(fAnalysisManager) {
    G4double norm = 1.0/G4double(nevents);
    for(int i=1; i<6; ++i) {
      fAnalysisManager->ScaleH1(i, norm);
    }
    fAnalysisManager->ScaleH2(1, norm);
    fAnalysisManager->ScaleH2(2, norm);
    fAnalysisManager->Write();
    fAnalysisManager->CloseFile();
    delete fAnalysisManager;
    fAnalysisManager = 0;
  } 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::CountProcesses(G4String procName)
{
  // is the process already counted ?
  // *AS* change to std::map?!
  size_t nbProc = fProcCounter->size();
  size_t i = 0;
  while ((i<nbProc)&&((*fProcCounter)[i]->GetName()!=procName)) i++;
  if (i == nbProc) fProcCounter->push_back( new ProcessCount(procName));
  
  (*fProcCounter)[i]->Count();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* aRun)
{
  G4int NbOfEvents = aRun->GetNumberOfEvent();
  if (NbOfEvents == 0) return;
  
  G4int  prec = G4cout.precision(5);
    
  G4Material* material = fDetector->GetMaterial();
  G4double density = material->GetDensity();
   
  G4ParticleDefinition* particle = 
                            fPrimary->GetParticleGun()->GetParticleDefinition();
  G4String Particle = particle->GetParticleName();    
  G4double energy = fPrimary->GetParticleGun()->GetParticleEnergy();
  G4cout << "\n The run consists of " << NbOfEvents << " "<< Particle << " of "
         << G4BestUnit(energy,"Energy") << " through " 
         << G4BestUnit(fDetector->GetBoxSizeZ(),"Length") << " of "
         << material->GetName() << " (density: " 
         << G4BestUnit(density,"Volumic Mass") << ")" << G4endl;
  
  //frequency of processes
  G4cout << "\n Process calls frequency --->\n";
  for (size_t i=0; i< fProcCounter->size();i++) {
     G4String procName = (*fProcCounter)[i]->GetName();
     G4int    count    = (*fProcCounter)[i]->GetCounter(); 
     G4cout << "\t" << procName << " = " << count<<"\n";
  }
  
  if (fTotalEventCount == 0) return;
  
  G4cout<<" Gamma: \n";
  fPhotonStats.PrintResults(fTotalEventCount);
  G4cout<<" Electron: \n";
  fElectronStats.PrintResults(fTotalEventCount);
  G4cout<<" Positron: \n";
  fPositronStats.PrintResults(fTotalEventCount);

  //cross check from G4EmCalculator
  //  G4cout << "\n Verification from G4EmCalculator. \n";  
  //  G4EmCalculator emCal;

  //restore default format         
  G4cout.precision(prec);         

  // write out histograms  
  SaveHisto(NbOfEvents);

  // show Rndm status
  CLHEP::HepRandom::showEngineStatus();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EventFinished()
{
  ++fTotalEventCount;
  fPhotonStats.EventFinished();
  fElectronStats.EventFinished();
  fPositronStats.EventFinished();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::ParticleStatistics::ParticleStatistics()
  : fCurrentNumber(0),
    fTotalNumber(0), fTotalNumber2(0),
    fSumEnergy(0), fSumEnergy2(0),
    fSumPolarization(0), fSumPolarization2(0)
  
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::ParticleStatistics::~ParticleStatistics()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::ParticleStatistics::EventFinished()
{
  fTotalNumber+=fCurrentNumber;
  fTotalNumber2+=fCurrentNumber*fCurrentNumber;
  fCurrentNumber=0;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::ParticleStatistics:: FillData(G4double kinEnergy, 
                                              G4double longitudinalPolarization)
{
  ++fCurrentNumber;
  fSumEnergy+=kinEnergy;
  fSumEnergy2+=kinEnergy*kinEnergy;
  fSumPolarization+=longitudinalPolarization;
  fSumPolarization2+=longitudinalPolarization*longitudinalPolarization;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::ParticleStatistics::PrintResults(G4int totalNumberOfEvents)
{
  G4cout<<"Mean Number per Event :"
        <<G4double(fTotalNumber)/G4double(totalNumberOfEvents)<<"\n";
  if (fTotalNumber==0) fTotalNumber=1;
  G4double energyMean=fSumEnergy/fTotalNumber;
  G4double energyRms=std::sqrt(fSumEnergy2/fTotalNumber-energyMean*energyMean);
  G4cout<<"Mean Energy :"<< G4BestUnit(energyMean,"Energy")
        <<" +- "<<G4BestUnit(energyRms,"Energy")<<"\n";
  G4double polarizationMean=fSumPolarization/fTotalNumber;
  G4double polarizationRms=
    std::sqrt(fSumPolarization2/fTotalNumber-polarizationMean*polarizationMean);
  G4cout<<"Mean Polarization :"<< polarizationMean
        <<" +- "<<polarizationRms<<"\n";
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::ParticleStatistics::Clear()
{
  fCurrentNumber=0;
  fTotalNumber=fTotalNumber2=0;
  fSumEnergy=fSumEnergy2=0;
  fSumPolarization=fSumPolarization2=0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
