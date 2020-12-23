/****************************************************
    S2PhysicsList.cc
    Implementation of the S2PhysicsList class
*****************************************************/

#include "S2PhysicsList.hh"


#include "G4HadronElasticProcess.hh"
#include "G4IonInelasticProcess.hh"

#include "G4ProcessManager.hh"
#include "G4EmProcessOptions.hh"
#include "G4SystemOfUnits.hh"

#include "G4Decay.hh"
#include "G4LossTableManager.hh"
#include "G4UAtomicDeexcitation.hh"
#include "G4UnitsTable.hh"



#include "G4eMultipleScattering.hh"

#include "G4AnnihiToMuPair.hh"
#include "G4eplusAnnihilation.hh"
#include "G4MuMultipleScattering.hh"
#include "G4hMultipleScattering.hh"
#include "G4VMultipleScattering.hh"
#include "G4GammaXTRadiator.hh"
//#include "G4VMultipleScattering.hh"
// Bosons
#include "G4ChargedGeantino.hh"
#include "G4Geantino.hh"
#include "G4Gamma.hh"
#include "G4OpticalPhoton.hh"

// leptons
#include "G4MuonPlus.hh"
#include "G4MuonMinus.hh"
#include "G4NeutrinoMu.hh"
#include "G4AntiNeutrinoMu.hh"

#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4NeutrinoE.hh"
#include "G4AntiNeutrinoE.hh"

// Hadrons
#include "G4Proton.hh"
#include "G4MesonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"

#include "G4GenericIon.hh"


#include "G4Cerenkov.hh"
#include "G4Scintillation.hh"
#include "G4OpAbsorption.hh"
#include "G4OpRayleigh.hh"
#include "G4OpMieHG.hh"
#include "G4OpBoundaryProcess.hh"

#include "G4EmSaturation.hh"

#include "G4BosonConstructor.hh"
#include "G4LeptonConstructor.hh"
#include "G4MesonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"
#include "G4ShortLivedConstructor.hh"
#include "G4IonParametrisedLossModel.hh"
#include "G4NuclearStopping.hh"
#include "G4UserSpecialCuts.hh"


#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"
#include "G4hIonisation.hh"
#include "G4ionIonisation.hh"

#include "G4hImpactIonisation.hh"

#include "G4ProductionCutsTable.hh"
#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"
#include "G4StepLimiter.hh"

//Physics Model List
#include "G4EmLowEPPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmLivermorePhysics.hh"
#include "G4EmPenelopePhysics.hh"
#include "G4EmLivermorePolarizedPhysics.hh"

#include "G4EmStandardPhysics.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4EmStandardPhysicsWVI.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecay.hh"

#include "G4PhotoNuclearProcess.hh"
#include "G4CascadeInterface.hh"




S2PhysicsList::S2PhysicsList() :G4VUserPhysicsList(),
      fEmPhysicsList(NULL),
      fEmName("")
{
  SetCutsWithDefault();
  SetVerboseLevel(2);
}

S2PhysicsList::~S2PhysicsList()
{}

void S2PhysicsList::ConstructParticle()
{
  G4BosonConstructor bConstructor;
  bConstructor.ConstructParticle();

  G4LeptonConstructor lConstructor;
  lConstructor.ConstructParticle();

  G4MesonConstructor mConstructor;
  mConstructor.ConstructParticle();

  G4BaryonConstructor rConstructor;
  rConstructor.ConstructParticle();

  G4IonConstructor iConstructor;
  iConstructor.ConstructParticle();
}


void S2PhysicsList::ConstructProcess()
{
  AddTransportation();
  AddDecay();
//fEmPhysicsList = new G4EmLowEPPhysics();
//fEmPhysicsList = new G4EmStandardPhysicsWVI();
  fEmPhysicsList = new G4EmLivermorePhysics();
//fEmPhysicsList = new G4EmPenelopePhysics();
//fEmPhysicsList = new S2PhysListEmLow();
  G4ProcessManager* pManager = G4Gamma::Gamma()->GetProcessManager();
   
  G4PhotoNuclearProcess* process = new G4PhotoNuclearProcess();
   
  G4CascadeInterface* bertini = new G4CascadeInterface();
  bertini->SetMaxEnergy(10*GeV);
  process->RegisterMe(bertini);
  pManager->AddDiscreteProcess(process);

  fEmPhysicsList->ConstructProcess();
  
  G4RadioactiveDecay* radioactiveDecay = new G4RadioactiveDecay();
  
  G4bool ARMflag = true;
  radioactiveDecay->SetARM(ARMflag);               //Atomic Rearrangement

// need to initialize atomic deexcitation
  
  G4LossTableManager* man = G4LossTableManager::Instance();
  G4VAtomDeexcitation* deex = man->AtomDeexcitation();
  if (!deex) 
  {
     G4EmParameters::Instance()->SetAugerCascade(true);
     deex = new G4UAtomicDeexcitation();
     deex->InitialiseAtomicDeexcitation();
     deex->SetFluo(true);
     deex->SetPIXE(true);
     deex->SetAuger(true);
     man->SetAtomDeexcitation(deex);
  }
  SetCuts();
}


void S2PhysicsList::AddDecay()
{

  G4Decay* theDecayProcess = new G4Decay();
  auto particleIterator=GetParticleIterator();
  particleIterator->reset();
  while( (*particleIterator)() )
  {
    G4ParticleDefinition* particle = particleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    if(theDecayProcess->IsApplicable(*particle)) 
    {
      pmanager ->AddProcess(theDecayProcess);
    // set ordering for PostStepDoIt and AtRestDoIt
      pmanager ->SetProcessOrdering(theDecayProcess, idxPostStep);
      pmanager ->SetProcessOrdering(theDecayProcess, idxAtRest);
    }
  }
}

void  S2PhysicsList::SetCuts()
{
//G4VUserPhysicsList::SetCutsWithDefault method sets
//the default cut value for all particle types
  
//SetDefaultCutValue(0.01*mm);

// Set the secondary production cut lower than 990. eV
// Very important for processes at low energies

  G4double lowLimit = 10 * eV;
  G4double highLimit = 100. * GeV;
  G4ProductionCutsTable::GetProductionCutsTable()
  ->SetEnergyRange(lowLimit, highLimit);
  SetCutValue(defaultCutValue,"gamma");
  SetCutValue(defaultCutValue, "e-");
  SetCutValue(defaultCutValue, "e+");

  DumpCutValuesTable();
}

/*void S2PhysicsList::AddPhysics(G4String& name)
{
   if (name == "emlow"){
      fEmName = name;
      delete fEmPhysicsList;
      fEmPhysicsList = new G4EmLowEPPhysics();}
   else
       {
         G4cout << "PhysicsList::AddPhysicsList: <" << name << ">"
           << " is not defined"
           << G4endl;
       }
}*/
