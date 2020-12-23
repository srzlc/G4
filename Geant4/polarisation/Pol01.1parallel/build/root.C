{
  TH1D g1("g1","Gamma Energy",120,0.,12.);
  TH1D g2("g2","Gamma xP",120,-1.,1.);
  TH1D g3("g3","Gamma yP",120,-1.,1.);
  TH1D g4("g4","Gamma zP",120,-1.,1.);
  TH1D e1("e1","Electron Energy",120,0.,12.);
  TH1D e2("e2","Electron xP",120,-1.,1.);
  TH1D e3("e3","Electron yP",120,-1.,1.);
  TH1D e4("e4","Electron zP",120,-1.,1.);
  TH1D p1("p1","Positron Energy",120,0.,12.);
  TH1D p2("p2","Positron xP",120,-1.,1.);
  TH1D p3("p3","Positron yP",120,-1.,1.);
  TH1D p4("p4","Positron zP",120,-1.,1.);
  TH1D h1("h1","Initial Gamma Energy",120,0.,30.);
  TH2D h2("h2","Initial Gamma Position",120,-0.3,0.3,120,-0.02,0.02);
  ifstream my1;
  my1.open("Gamma.txt");
  double a1;double a2;double a3;double a4;
  while(my1>>a1>>a2>>a3>>a4){g1.Fill(a1);g2.Fill(a2);g3.Fill(a3);g4.Fill(a4);}
  my1.close();
  ifstream my2;
  my2.open("Electron.txt");
  double b1;double b2;double b3;double b4;
  while(my2>>b1>>b2>>b3>>b4){e1.Fill(b1);e2.Fill(b2);e3.Fill(b3);e4.Fill(b4);}
  my2.close();
  ifstream my3;
  my3.open("Positron.txt");
  double m1;double m2;double m3;double m4;
  while(my3>>m1>>m2>>m3>>m4){p1.Fill(m1);p2.Fill(m2);p3.Fill(m3);p4.Fill(m4);}
  my3.close();
  ifstream my4;
  my4.open("InitialGammaEnergy.txt");
  double d1;
  while(my4>>d1){h1.Fill(d1);}
  my4.close();
  ifstream my5;
  my5.open("InitialGammaPosition.txt");
  double n1;double n2;
  while(my5>>n1>>n2){h2.Fill(n1,n2);}
  my5.close();
  TCanvas* c1 = new TCanvas("c1","",20,20,1000,1000);
  c1->Divide(2,2);
  c1->cd(1);
  g1.Draw("HIST");
  c1->cd(2);
  g2.Draw("HIST");
  c1->cd(3);
  g3.Draw("HIST");
  c1->cd(4);
  g4.Draw("HIST");
 
  TCanvas* c2 = new TCanvas("c2","",20,20,1000,1000);
  c2->Divide(2,2);
  c2->cd(1);
  e1.Draw("HIST");
  c2->cd(2);
  e2.Draw("HIST");
  c2->cd(3);
  e3.Draw("HIST");
  c2->cd(4);
  e4.Draw("HIST");
 
  TCanvas* c3 = new TCanvas("c3","",20,20,1000,1000);
  c3->Divide(2,2);
  c3->cd(1);
  p1.Draw("HIST");
  c3->cd(2);
  p2.Draw("HIST");
  c3->cd(3);
  p3.Draw("HIST");
  c3->cd(4);
  p4.Draw("HIST");

  TCanvas* c4 = new TCanvas("c4","",20,20,1000,1000);
  c4->Divide(1,2);
  c4->cd(1);
  h1.Draw("HIST");
  c4->cd(2);
  h2.Draw("HIST")
}
