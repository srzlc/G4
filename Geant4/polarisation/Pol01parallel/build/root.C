{
TH1D h1("h1","Gamma Energy",120,0.,12.);
TH1D h2("h2","cos",120,-1.,1.);
TH1D h3("h3","phi",120,-3.14,3.14);
TH1D h4("h4","xP",120,-1.,1.);
TH1D h5("h5","yP",120,-1.,1.);
TH1D h6("h6","zP",120,-1.,1.);
ifstream my;
my.open("Gamma.txt");
double a1;double a2;double a3;double a4;double a5;double a6;
while(my>>a1>>a2>>a3>>a4>>a5>>a6){h1.Fill(a1);h2.Fill(a2);h3.Fill(a3);h4.Fill(a4);h5.Fill(a5);h6.Fill(a6);}
my.close();
}
