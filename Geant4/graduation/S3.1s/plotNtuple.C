// ROOT macro file for plotting example S3 ntuple
// 
// Can be run from ROOT session:
// root[0] .x plotNtuple.C

{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  
  // Draw histos filled by Geant4 simulation 
  //   

  // Open file filled by Geant4 simulation 
  TFile f("S3.root");

  // Create a canvas and divide it into 1x3 pads
  TCanvas* c1 = new TCanvas("c1", "", 20, 20, 1000, 1000);
  c1->Divide(1,3);
  
  // Get ntuple
  TNtuple* ntuple = (TNtuple*)f.Get("S3");

  // Draw Eabs histogram in the pad 1
  c1->cd(1);
  ntuple->Draw("EP");
  
  // Draw Labs histogram in the pad 2
  c1->cd(2);
  ntuple->Draw("EG");
  
  // Draw Labs histogram in the pad 3
  c1->cd(3);
  ntuple->Draw("EE");
}  
