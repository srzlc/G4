// ROOT macro file for plotting example S3 histograms 
// 
// Can be run from ROOT session:
// root[0] .x plotHisto.C

{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  
  // Draw histos filled by Geant4 simulation 
  //   

  // Open file filled by Geant4 simulation 
  TFile f("S3.root");

  // Create a canvas and divide it into 1x2 pads
  TCanvas* c1 = new TCanvas("c1", "", 20, 20, 1000, 1000);
  c1->Divide(1,3);
  
  // Draw Eabs histogram in the pad 1
  c1->cd(1);
  TH1D* hist1 = (TH1D*)f.Get("Positron");
  hist1->Draw("HIST");
  
  // Draw Labs histogram in the pad 2
  c1->cd(2);
  TH1D* hist2 = (TH1D*)f.Get("Gamma");
  hist2->Draw("HIST");
  // Draw labs histogram in the pad 3
  c1->cd(3);
  TH1D* hist3 = (TH1D*)f.Get("Electron");
  hist3->Draw("HIST");
}  
