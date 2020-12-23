//ROOT macro file for plotting histograms
//root[0] .x plot.C
//>>root -l plot.C
{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  //Open file
  TFile f("pol01.root");
   //Create a canvas and divide it into 3x3 pads
  TCanvas* c1 = new TCanvas("c1","",20,20,1000,1000);
  c1->Divide(3,3);
  //Draw Gamma xpolarization in the pad 1
  c1->cd(1);
  TH1D* hist1 = (TH1D*)f.Get("h4");
  hist1->Draw("HIST");
  //Draw Gamma ypolarization in the pad 2
  c1->cd(2);
  TH1D* hist2 = (TH1D*)f.Get("h5");
  hist2->Draw("HIST");
  //Draw Gamma zpolarization in the pad 3
  c1->cd(3);
  TH1D* hist3 = (TH1D*)f.Get("h6");
  hist3->Draw("HIST");
  //Draw Electron xpolarization in the pad 4
  c1->cd(4);
  TH1D* hist4 = (TH1D*)f.Get("h10");
  hist4->Draw("HIST");
  //Draw Electron ypolarization in the pad 5
  c1->cd(5);
  TH1D* hist5 = (TH1D*)f.Get("h11");
  hist5->Draw("HIST");
  //Draw Electron zpolarization in the pad 6
  c1->cd(6);
  TH1D* hist6 = (TH1D*)f.Get("h12");
  hist6->Draw("HIST");
  //Draw Positron xpolarization in the pad 7 
  c1->cd(7);
  TH1D* hist7 = (TH1D*)f.Get("h16");
  hist7->Draw("HIST");
  //Draw Positron ypolarization in the pad 8
  c1->cd(8);
  TH1D* hist8 = (TH1D*)f.Get("h17");
  hist8->Draw("HIST");
  //Draw Positron zpolarization in the pad 9  
  c1->cd(9);
  TH1D* hist9 = (TH1D*)f.Get("h18");
  hist9->Draw("HIST");
///////////////////////////////////////////////
  //Create a canvas and divide it into 2x3 pads
  TCanvas* c2 = new TCanvas("c2","",20,20,1000,1000);
  c2->Divide(2,3);
  //Draw Gamma
  c2->cd(1);
  TH1D* gamma1 = (TH1D*)f.Get("h1");
  gamma1->Draw("HIST");
  
  c2->cd(2);
  TH1D* gamma2 = (TH1D*)f.Get("h2");
  gamma2->Draw("HIST");
  
  c2->cd(3);
  TH1D* gamma3 = (TH1D*)f.Get("h3");
  gamma3->Draw("HIST");

  c2->cd(4);
  TH1D* gamma4 = (TH1D*)f.Get("h4");
  gamma4->Draw("HIST");

  c2->cd(5);
  TH1D* gamma5 = (TH1D*)f.Get("h5");
  gamma5->Draw("HIST");

  c2->cd(6);
  TH1D* gamma6 = (TH1D*)f.Get("h6");
  gamma6->Draw("HIST");
//////////////////////////////////////////////
  //Create a canvas and divide it into 2x3 pads
  TCanvas* c3 = new TCanvas("c3","",20,20,1000,1000);
  c3->Divide(2,3);
  //Draw Electron
  c3->cd(1);
  TH1D* electron1 = (TH1D*)f.Get("h7");
  electron1->Draw("HIST");
  
  c3->cd(2);
  TH1D* electron2 = (TH1D*)f.Get("h8");
  electron2->Draw("HIST");

  c3->cd(3);
  TH1D* electron3 = (TH1D*)f.Get("h9");
  electron3->Draw("HIST");

  c3->cd(4);
  TH1D* electron4 = (TH1D*)f.Get("h10");
  electron4->Draw("HIST");
  
  c3->cd(5);
  TH1D* electron5 = (TH1D*)f.Get("h11");
  electron5->Draw("HIST");

  c3->cd(6);
  TH1D* electron6 = (TH1D*)f.Get("h12");
  electron6->Draw("HIST");
///////////////////////////////////////////////
  //Create a canvas and divide it into 2x3 pads
  TCanvas* c4 = new TCanvas("c4","",20,20,1000,1000);
  c4->Divide(2,3);
  //Draw Positron
  c4->cd(1);
  TH1D* positron1 = (TH1D*)f.Get("h13");
  positron1->Draw("HIST");

  c4->cd(2);
  TH1D* positron2 = (TH1D*)f.Get("h14");
  positron2->Draw("HIST");
  
  c4->cd(3);
  TH1D* positron3 = (TH1D*)f.Get("h15");
  positron3->Draw("HIST");
  
  c4->cd(4);
  TH1D* positron4 = (TH1D*)f.Get("h16");
  positron4->Draw("HIST");

  c4->cd(5);
  TH1D* positron5 = (TH1D*)f.Get("h17");
  positron5->Draw("HIST");

  c4->cd(6);
  TH1D* positron6 = (TH1D*)f.Get("h18");
  positron6->Draw("HIST");
}
