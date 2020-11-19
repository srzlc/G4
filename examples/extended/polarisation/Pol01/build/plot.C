//ROOT macro file for plotting histograms
//
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
  //Draw histogram in the pad 1
  c1->cd(1);
  TH1D* hist1 = (TH1D*)f.Get("h1");
  hist1->Draw("HIST");
}
