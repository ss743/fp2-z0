#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TString.h"
#include <iostream>

void showGraphs(int cut=1,int limit=1){
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);//if you want to get rid of the statistics box
  
  TFile* files[5];
  files[0] = new TFile("../daten/mc/ee.root");
  files[1] = new TFile("../daten/mc/mm.root");
  files[2] = new TFile("../daten/mc/tt.root");
  files[3] = new TFile("../daten/mc/qq.root");
  files[4] = new TFile("../daten/daten/daten_4.root");
  
  TFile* file = files[4];
  
  TTree* h[6];
  int n;
  
  float sumWithoutCut[4];
  float sumWithCut[4];
  float eff[4];
  float pur[4];
  
  TString limits[]={"1==1","E_lep>44&&E_lep<44.5","E_lep>44.5&&E_lep<45","E_lep>45&&E_lep<45.4","E_lep>45.4&&E_lep<45.8","E_lep>45.8&&E_lep<46.2","E_lep>46.2&&E_lep<46.5","E_lep>46.5&&E_lep<47"};
  
  float sum1;
  float sum2;
  
  float Br[4]={1.3994,1.3994,1.3994,29.0672};

  //Make cuts and get the number of events

//  files[1]->cd(); //ee ntuple
  //without cuts
//  TTree *hee = (TTree*)files[1]->Get("h3");
//  float nEvents_ee_all = hee->Draw("E_ecal>>heEcal_ee_all(200,0,200)","");
//  TH1F* heEcal_ee_all = (TH1F*) gDirectory->Get("heEcal_ee_all");
//  cout << ("n_ee_all=") << nEvents_ee_all << endl;


//  files[1]->cd(); //mm ntuple
  //with cuts
//  TString mmcuts="Ncharged<5 && Pcharged>10";
//  TTree *hmm = (TTree*)files[1]->Get("h3");
//  float nEvents_mm_all = hmm->Draw("E_ecal>>heEcal_mm_all(200,0,200)",mmcuts);
//  TH1F* heEcal_mm_all = (TH1F*) gDirectory->Get("heEcal_mm_all");
//  cout << ("n_mm_all=") << nEvents_mm_all << endl;
  
  int colors[5]={1,2,3,4,6};//for ee, mm, tt, qq, data
  TString numbers[5] = {"0","1","2","3","4"};
  TString names[5] = {"ee","mm","tt","qq","data"};
  TString arguments[6] = {"Ncharged","E_ecal","Pcharged","E_hcal","cos_thet","E_lep"};
  TString boundaries[6] = {"(40,0,40)","(120,0,120)","(120,0,120)","(40,0,40)","(100,-1,1)","(30,44,48)"};
  Int_t posX[6] = {840,1260,840,1260,840,1260};
  Int_t posY[6] = {0,0,357,357,700,700};
  
  TString argument;
  TString bounds;
  
  TString cuts[] = {"1==1","((Ncharged<5 && E_ecal>=74)||(Pcharged==0 && E_ecal>80))&&cos_thet<0.4&&Pcharged>15","Ncharged<5 && E_ecal<50 && (Pcharged>=75||Pcharged<1)","Ncharged<5 && E_ecal<74 && Pcharged<75 && Pcharged>15","Ncharged>7"};
	TString cutnames[] = {"Gesamt","Elektronen","Myonen","Tauonen","Quarks"};
  
  for(unsigned int k=0; k<6;k++){
  	argument=arguments[k];
  	bounds=boundaries[k];
   	new TCanvas(TString("c")+k,argument+TString(" (")+cutnames[cut]+TString(")"),posX[k],posY[k],410,305);

  	
  	h[k] = (TTree*)file->Get("h33");
		h[k]->SetTitle("data");
		if(k==0)n=h[k]->Draw(TString(argument)+TString(">>")+argument+bounds,TString("(")+cuts[cut]+TString(")&&")+limits[limit]);
		else h[k]->Draw(TString(argument)+TString(">>")+argument+bounds,TString("(")+cuts[cut]+TString(")&&")+limits[limit]);

	}
	
	cout<<"Bla: "<<n<<endl;
	


}
