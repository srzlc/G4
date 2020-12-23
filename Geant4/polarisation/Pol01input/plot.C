//ROOT macro file for plotting histograms
//root[0] .x plot.C
//>>root -l plot.C
{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  //Open file
  TFile f("pol01.root");
   //Create a canvas and divide it into 2x2 pads
  TCanvas* c1 = new TCanvas("c1","",20,20,1000,1000);
  c1->Divide(2,2);
  //Draw Positron Kinenergy in the pad 1
  c1->cd(1);
  TH1D* hist1 = (TH1D*)f.Get("h2");
  hist1->Draw("HIST");
  //Draw Positron xpolarization in the pad 2
  c1->cd(2);
  TH1D* hist2 = (TH1D*)f.Get("h3");
  hist2->Draw("HIST");
  //Draw Positron ypolarization in the pad 3
  c1->cd(3);
  TH2D* hist3 = (TH2D*)f.Get("h6");
  hist3->Draw("HIST");
  //Draw Positron longitudinalPolarization in the pad 4
  c1->cd(4);
  TH1D* hist4 = (TH1D*)f.Get("h5");
  hist4->Draw("HIST");
  //Create a canvas and divide it into 1x2
  TCanvas* c2 = new TCanvas("c2","",20,20,1000,1000);
  c2->Divide(1,2);
  //Draw initial Gamma Energy spectrum in the pad 1
  c2->cd(1);
  TH1D* Gamma1 = (TH1D*)f.Get("h1");
  Gamma1->Draw("HIST");
  //Draw initial Gamma Position in the pad 2
  c2->cd(2);
  TH2D* Gamma2 = (TH2D*)f.Get("Position");
  Gamma2->Draw("HIST");
}
