#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TString.h"
#include <iostream>

void fb(int data=0,int limit=4){
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);//if you want to get rid of the statistics box
  
  TFile* files[5];
  files[0] = new TFile("../daten/mc/ee.root");
  files[1] = new TFile("../daten/mc/mm.root");
  files[2] = new TFile("../daten/mc/tt.root");
  files[3] = new TFile("../daten/mc/qq.root");
  files[4] = new TFile("../daten/daten/daten_4.root");
  

  TFile* file;
  if(data=0) file = files[1];
  else file = files[4];
  
  TTree* h[6];
  int n[3];
  
  float sumWithoutCut[4];
  float sumWithCut[4];
  float eff[4];
  float pur[4];
  
  TString limits[]={"1==1","E_lep>44&&E_lep<44.5","E_lep>44.5&&E_lep<45","E_lep>45&&E_lep<45.4","E_lep>45.4&&E_lep<45.8","E_lep>45.8&&E_lep<46.2","E_lep>46.2&&E_lep<46.5","E_lep>46.5&&E_lep<47"};
  
  float sum1;
  float sum2;
  
  float Br[4]={1.3994,1.3994,1.3994,29.0672};
  
  int colors[5]={1,2,3,4,6};//for ee, mm, tt, qq, data
  TString numbers[5] = {"0","1","2","3","4"};
  TString names[5] = {"ee","mm","tt","qq","data"};
  TString arguments[6] = {"Ncharged","E_ecal","Pcharged","E_hcal","cos_thet","E_lep"};
  TString boundaries[6] = {"(40,0,40)","(120,0,120)","(120,0,120)","(40,0,40)","(100,-1,1)","(30,44,48)"};
  Int_t posX[6] = {840,1260,840,1260,840,1260};
  Int_t posY[6] = {0,0,357,357,700,700};
  
  TString argument;
  TString bounds;
  
  TString cuts[] = {"Ncharged<5 && E_ecal<50 && (Pcharged>=75||Pcharged<1)","Ncharged<5 && E_ecal<50 && (Pcharged>=75||Pcharged<1)&&cos_thet>0","Ncharged<5 && E_ecal<50 && (Pcharged>=75||Pcharged<1)&&cos_thet<0"};
	TString cutnames[] = {"Myonen","Myonen vorwaerts","Myonen rueckwaerts"};
  
  for(unsigned int k=0; k<3;k++){
  	argument="cos_thet";
  	bounds="(100,-1,1)";
   	new TCanvas(TString("c")+k,argument+TString(" (")+cutnames[k]+TString(")"),posX[k],posY[k],410,305);

  	
  	if(data=0)	h[k] = (TTree*)file->Get("h3");
  	else 				h[k] = (TTree*)file->Get("h33");
		h[k]->SetTitle("bla");
		n[k]=h[k]->Draw(TString(argument)+TString(">>")+argument+k+bounds,TString("(")+cuts[k]+TString(")&&")+limits[limit]);

	}
	
	cout<<"Gesamt:    "<<n[0]<<endl;
	cout<<"Vorwärts:  "<<n[1]<<endl;
	cout<<"Rückwärts: "<<n[2]<<endl;
	
	float A=abs(n[1]-n[2])/(1.0*n[0]);
	float sA=sqrt(1./n[0]*(1+pow((n[1]-n[2])/(1.*n[0]),2)));
	
	cout<<endl;
	cout<<"A_FB:      "<<A<<" +- "<<sA<<endl;
	
	float sinsq_weinberg=1./4*(1-sqrt(A/3.));
	float ssinsq_weinberg=1./(4*sqrt(6))*sA/A;
	cout<<"sin^2(theta_w): "<<sinsq_weinberg<<" +- "<<ssinsq_weinberg<<endl;
	
}
