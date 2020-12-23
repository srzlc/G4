// ROOT macro file for plotting example S3 histograms 
// 
// Can be run from ROOT session:
// root[0] .x plotHisto.C

{
  gROOT->Reset();
//  gROOT->SetStyle("Plain");
  
  // Draw histos filled by Geant4 simulation 
  //   

  // Open file filled by Geant4 simulation 
  TFile* f    = new TFile("S3.root");

  TCanvas* c1 = new TCanvas("c1","EnergyDeposit");
  TH1D* hist1 = (TH1D*)f->Get("Positron0");
  hist1->GetXaxis()->SetTitle("Positron Energy / MeV");
  hist1->GetYaxis()->SetTitle("Count");
  hist1->GetXaxis()->CenterTitle();
  hist1->GetYaxis()->CenterTitle();
  hist1->Draw("HIST");
  
  TCanvas* c2 = new TCanvas("c2","EnergyDeposit");
  TH1D* hist2 = (TH1D*)f->Get("Positron1");
  hist2->GetXaxis()->SetTitle("Positron Energy / MeV");
  hist2->GetYaxis()->SetTitle("Count");
  hist2->GetXaxis()->CenterTitle();
  hist2->GetYaxis()->CenterTitle();
  hist2->Draw("HIST");

  TCanvas* c3 = new TCanvas("c3","EnergyDeposit");
  TH1D* hist3 = (TH1D*)f->Get("Positron2");
  hist3->GetXaxis()->SetTitle("Positron Energy / MeV");
  hist3->GetYaxis()->SetTitle("Count");
  hist3->GetXaxis()->CenterTitle();
  hist3->GetYaxis()->CenterTitle();
  hist3->Draw("HIST");

  TCanvas* c4 = new TCanvas("c4","EnergyDeposit");
  TH1D* hist4 = (TH1D*)f->Get("Positron3");
  hist4->GetXaxis()->SetTitle("Positron Energy / MeV");
  hist4->GetYaxis()->SetTitle("Count");
  hist4->GetXaxis()->CenterTitle();
  hist4->GetYaxis()->CenterTitle();
  hist4->Draw("HIST");

  TCanvas* c5 = new TCanvas("c5","EnergyDeposit");
  TH1D* hist5 = (TH1D*)f->Get("Positron4");
  hist5->GetXaxis()->SetTitle("Positron Energy / MeV");
  hist5->GetYaxis()->SetTitle("Count");
  hist5->GetXaxis()->CenterTitle();
  hist5->GetYaxis()->CenterTitle();
  hist5->Draw("HIST");

  TCanvas* c6 = new TCanvas("c6","EnergyDeposit");    
  TH1D* hist6 = (TH1D*)f->Get("Positron5");
  hist6->GetXaxis()->SetTitle("Positron Energy / MeV");
  hist6->GetYaxis()->SetTitle("Count");
  hist6->GetXaxis()->CenterTitle();
  hist6->GetYaxis()->CenterTitle();
  hist6->Draw("HIST");

  TCanvas* c7 = new TCanvas("c7","EnergyDeposit");
  TH1D* hist7 = (TH1D*)f->Get("Positron6");
  hist7->GetXaxis()->SetTitle("Positron Energy / MeV");
  hist7->GetYaxis()->SetTitle("Count");
  hist7->GetXaxis()->CenterTitle();
  hist7->GetYaxis()->CenterTitle();
  hist7->Draw("HIST");
  
  c1->cd();
  c1->Update();
}  
