//ROOT macro file for plotting histograms
//root[0] .x plot.C
//>>root -l plot.C
{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  //Open file
  TFile f("pol01.root");
   //Create a canvas and divide it into 2x4 pads
  TCanvas* c1 = new TCanvas("c1","",20,20,1000,1000);
  //Draw M-kinEnergy in the pad 1
  TH1D* hist1 = (TH1D*)f.Get("MuonMinus");
  hist1->Draw("HIST");
  TCanvas* c3 = new TCanvas("c3","",20,20,1000,1000);
  //Draw M+ kinEnergy in the pad 2
  TH1D* hist2 = (TH1D*)f.Get("MuonPlus");
  hist2->Draw("HIST");
  //Draw Positron kinEnergy in the pad 3
  TCanvas* c4 = new TCanvas("c4","",20,20,1000,1000);
  TH1D* hist3 = (TH1D*)f.Get("Positron");
  hist3->Draw("HIST");
  //Draw Electron kinEnergy in the pad 4
  TCanvas* c5 = new TCanvas("c5","",20,20,1000,1000);
  TH1D* hist4 = (TH1D*)f.Get("Electron");
  hist4->Draw("HIST");
  //Draw PionPlus kinEnergy in the pad 5
  TCanvas* c6 = new TCanvas("c6","",20,20,1000,1000);
  TH1D* hist5 = (TH1D*)f.Get("PionPlus");
  hist5->Draw("HIST");
  //Draw PionMinus kinEnergy in the pad 6
  TCanvas* c7 = new TCanvas("c7","",20,20,1000,1000);
  TH1D* hist6 = (TH1D*)f.Get("PionMinus");
  hist6->Draw("HIST");
  //Draw Gamma kinEnergy in the pad 7
  TCanvas* c8 = new TCanvas("c8","",20,20,1000,1000);
  TH1D* hist7 = (TH1D*)f.Get("Gamma");
  hist7->Draw("HIST");
  //Create a canvas and divide it into 2x4 pads
  TCanvas* c2 = new TCanvas("c2","",20,20,1000,1000);
  c2->Divide(2,4);
  //Draw MuonMinus Position in the pad 1
  c2->cd(1);
  TH2D* pos1 = (TH2D*)f.Get("MuonMinusxy");
  pos1->Draw("HIST");
  //Draw MuonPlus Position in the pad 2
  c2->cd(2);
  TH2D* pos2 = (TH2D*)f.Get("MuonPlusxy");
  pos2->Draw("HIST");
  //Draw Positron Position in the pad 3
  c2->cd(3);
  TH2D* pos3 = (TH2D*)f.Get("Positronxy");
  pos3->Draw("HIST");
  //Draw Electron Position in the pad 4
  c2->cd(4);
  TH2D* pos4 = (TH2D*)f.Get("Electronxy");
  pos4->Draw("HIST");
  //Draw PionPlus Position in the pad 5
  c2->cd(5);
  TH2D* pos5 = (TH2D*)f.Get("PionPlusxy");
  pos5->Draw("HIST");
  //Draw PionMinus Position in the pad 6
  c2->cd(6);
  TH2D* pos6 = (TH2D*)f.Get("PionMinusxy");
  pos6->Draw("HIST");
  //Draw Gamma Position in the pad 7
  c2->cd(7);
  TH2D* pos7 = (TH2D*)f.Get("Gammaxy");
  pos7->Draw("HIST");
}
