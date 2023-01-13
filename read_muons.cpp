// Macro to read AnalysisResults.root files
// then, writing histo and tree output in a file

#include "TBrowser.h"
#include "TBenchmark.h"

#include <ctime>
#include <cmath>
#include <iostream>
#include <TRandom.h>
#include <Riostream.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TTree.h>
#include <TROOT.h>
#include <TFile.h>

template <typename T2>
std::string to_string_wp(const T2 a_value, const int n = 4){
    std::ostringstream out;
    out << std::setprecision(n) << a_value;
    return out.str();
}
using namespace std;
void plot(int kplot = 0, bool norm=false);
void plotMuonLowPt(int kplot = 0, bool norm=false);
void plotMuonsPM(int kplot = 0, bool norm=false);


const Int_t Nmax = 2;
TH1F *hist1dVar[50][20];
TH2F *hist2dVar[50][20];


void getHistosMuonLowPt(){
        
    TFile *f[Nmax];
    
    f[0]= new TFile("AnalysisResults_22mDQ.root","read");

    TH1F *histo[Nmax];
    //histo[0] = (TH1F *)f[0]->Get("table-maker/output/Muons_BeforeCuts/Eta");
    //histo[0] = (TH1F *)f[0]->Get("analysis-qvector/Event_BeforeCuts/VtxZ");

    //histo[1] = (TH1F *)f[0]->Get("table-maker/output/Muons_muonQualityCuts/Eta");
    //histo[1] = (TH1F *)f[0]->Get("analysis-qvector/Event_AfterCuts/VtxZ");

    
    TString mainDirName;
    TString dirName[10];
    mainDirName = "analysis-same-event-pairing";
    dirName[0] = "PairsMuonSEPM_muonLowPt";
    dirName[1] = "PairsMuonSEPP_muonLowPt";
    dirName[2] = "PairsMuonSEMM_muonLowPt";

//    mainDirName = "analysis-event-mixing";
//    dirName[0] = "PairsBarrelMEPM_jpsiO2MCdebugCuts";
//    dirName[1] = "PairsBarrelMEPP_jpsiO2MCdebugCuts";
//    dirName[2] = "PairsBarrelMEMM_jpsiO2MCdebugCuts";

    std::vector<TString> hist1dName;
    //hist1dName = {"Pt","Eta","Phi","MuonNCluster","pdca","RAtAbsorberEnd","Chi2","Chi2MCHMID","Chi2MCHMFT","Chi2MatchScoreMCHMFT","MuonCXX","MuonCYY","MuonCPhiPhi","MuonCTglTgl","MuonC1Pt21Pt2","MCHBitMap_vs_pt", "Mass","Mass_Pt","Eta_Pt","Mass_VtxZ"};
    hist1dName = {"Pt","Mass","Rapidity","Mass_VtxZ","Mass_Rapidity"};

    auto hlist = (THashList*) f[0]->Get(Form("%s/output", mainDirName.Data()));
    
    const int sizeHist = hist1dName.size();
    printf( "--> sizeHist = %d \n ",sizeHist);
    
    for(int k=0; k<3; k++){
        for(int i=0; i<5; i++){
            printf( "----> %d %d \n ",k,i);
            auto list = (TList*) hlist -> FindObject(dirName[k].Data());
            hist1dVar[k][i] = (TH1F*) list->FindObject(hist1dName[i].Data());
            hist1dVar[k][i] -> SetName(dirName[k]);
        }
    }
    
    printf("run: plotMuonLowPt(int kplot, bool norm) \n");

}

void plotMuonLowPt(int kplot, bool norm){
    
    hist1dVar[0][kplot]->SetMarkerColor(1); hist1dVar[0][kplot]->SetLineColor(1);
    hist1dVar[1][kplot]->SetMarkerColor(623); hist1dVar[1][kplot]->SetLineColor(623);
    hist1dVar[2][kplot]->SetMarkerColor(414); hist1dVar[2][kplot]->SetLineColor(414);
    
    if(norm){
        for (int i=0; i<4; i++){
            Double_t factor = 1.;
            hist1dVar[i][kplot]->Scale(factor/hist1dVar[i][kplot]->Integral());
        }
    }
    hist1dVar[1][kplot]->Sumw2();
    hist1dVar[2][kplot]->Sumw2();

    hist1dVar[1][kplot]->Multiply(hist1dVar[2][kplot]);

    for (int bin=1; bin <= hist1dVar[1][kplot]->GetNbinsX(); bin++) {
        printf(" %d   %f ---> %f\n", bin, hist1dVar[1][kplot]->GetBinContent(bin) ,  sqrt(hist1dVar[1][kplot]->GetBinContent(bin)));
        if(hist1dVar[1][kplot]->GetBinContent(bin) > 0.0){
            hist1dVar[1][kplot]->SetBinContent(bin, sqrt(hist1dVar[1][kplot]->GetBinContent(bin)) );
            hist1dVar[1][kplot]->SetBinError(bin, 0.2*sqrt(hist1dVar[1][kplot]->GetBinError(bin)) );
        }
    }
    hist1dVar[1][kplot]->Scale(1.6);

    
    hist1dVar[0][kplot]->Draw("EPZ");
    hist1dVar[1][kplot]->Draw("EPZ same");

    //hist1dVar[0][0]->GetXaxis()->SetTitle(hist1dName[kplot].Data());
    //hist1dVar[0][0]->GetYaxis()->SetTitle("counts");
//    hist1dVar[0][0]->SetLabelSize(0.055, "xy");
//    hist1dVar[0][0]->SetLabelOffset(0.01, "xy");
//    hist1dVar[0][0]->SetTitleSize(0.055, "xy");
//    hist1dVar[0][0]->SetTitleOffset(1., "x");
//    hist1dVar[0][0]->SetTitleOffset(1.5, "y");
//    hist1dVar[0][0]->SetMarkerColor(1); hist1dVar[0][0]->SetLineColor(1); hist1dVar[0][0]->SetMarkerStyle(20);
//    hist1dVar[0][1]->SetMarkerColor(623); hist1dVar[0][1]->SetLineColor(623); hist1dVar[0][1]->SetMarkerStyle(24);
//    hist1dVar[0][2]->SetMarkerColor(414); hist1dVar[0][2]->SetLineColor(414); hist1dVar[0][2]->SetMarkerStyle(24);


    TLegend *leg = new TLegend(.14, .7, .25, .84);
    //leg->SetNColumns(2);
    leg->SetTextSize(0.055);
    leg->AddEntry(hist1dVar[0][kplot], "muonLowPt ", " ");
    leg->AddEntry(hist1dVar[0][kplot], "Paismuon_SEPM", "pl ");
    leg->AddEntry(hist1dVar[1][kplot], "PP + MM ", "pl");
    //leg->AddEntry(hist1dVar[2][kplot], "Paismuon_SEMM", "pl");
    leg->Draw();
    leg->SetBorderSize(0);

    gStyle->SetOptStat(0);
    
}


void getHistosMCHtracks(){
        
    TFile *f[Nmax];
    
    f[0]= new TFile("AnalysisResults_22mDQ.root","read");

    TH1F *histo[Nmax];
    //histo[0] = (TH1F *)f[0]->Get("table-maker/output/Muons_BeforeCuts/Eta");
    //histo[0] = (TH1F *)f[0]->Get("analysis-qvector/Event_BeforeCuts/VtxZ");

    //histo[1] = (TH1F *)f[0]->Get("table-maker/output/Muons_muonQualityCuts/Eta");
    //histo[1] = (TH1F *)f[0]->Get("analysis-qvector/Event_AfterCuts/VtxZ");

    
    TString mainDirName;
    TString dirName[10];
    mainDirName = "analysis-same-event-pairing";
    dirName[0] = "PairsMuonSEPM_mchTrack";
    dirName[1] = "PairsMuonSEPP_mchTrack";
    dirName[2] = "PairsMuonSEMM_mchTrack";

//    mainDirName = "analysis-event-mixing";
//    dirName[0] = "PairsBarrelMEPM_jpsiO2MCdebugCuts";
//    dirName[1] = "PairsBarrelMEPP_jpsiO2MCdebugCuts";
//    dirName[2] = "PairsBarrelMEMM_jpsiO2MCdebugCuts";

    std::vector<TString> hist1dName;
    //hist1dName = {"Pt","Eta","Phi","MuonNCluster","pdca","RAtAbsorberEnd","Chi2","Chi2MCHMID","Chi2MCHMFT","Chi2MatchScoreMCHMFT","MuonCXX","MuonCYY","MuonCPhiPhi","MuonCTglTgl","MuonC1Pt21Pt2","MCHBitMap_vs_pt", "Mass","Mass_Pt","Eta_Pt","Mass_VtxZ"};
    hist1dName = {"Pt","Eta","Phi","Mass","MuonNClusters","pdca","RAtAbsorberEnd"};

    auto hlist = (THashList*) f[0]->Get(Form("%s/output", mainDirName.Data()));
    
    const int sizeHist = hist1dName.size();
    printf( "--> sizeHist = %d \n ",sizeHist);
    
    for(int k=0; k<3; k++){
        for(int i=0; i<6; i++){
            printf( "----> %d %d \n ",k,i);
            auto list = (TList*) hlist -> FindObject(dirName[k].Data());
            hist1dVar[k][i] = (TH1F*) list->FindObject(hist1dName[i].Data());
            hist1dVar[k][i] -> SetName(dirName[k]);
        }
    }
    

}

void getHistosMuonsPM(){
        
    TFile *f[Nmax];
    
    f[0]= new TFile("AnalysisResults_22mDQ.root","read");

    TH1F *histo[Nmax];
    //histo[0] = (TH1F *)f[0]->Get("table-maker/output/Muons_BeforeCuts/Eta");
    //histo[0] = (TH1F *)f[0]->Get("analysis-qvector/Event_BeforeCuts/VtxZ");

    //histo[1] = (TH1F *)f[0]->Get("table-maker/output/Muons_muonQualityCuts/Eta");
    //histo[1] = (TH1F *)f[0]->Get("analysis-qvector/Event_AfterCuts/VtxZ");

    
    TString mainDirName;
    TString dirName[10];
    mainDirName = "analysis-same-event-pairing";
    dirName[0] = "PairsMuonSEPM_mchTrack";
    dirName[1] = "PairsMuonSEPM_matchedMchMid";
    dirName[2] = "PairsMuonSEPM_muonLowPt";
    dirName[3] = "PairsMuonSEPM_muonQualityCuts";

//    mainDirName = "analysis-event-mixing";
//    dirName[0] = "PairsBarrelMEPM_jpsiO2MCdebugCuts";
//    dirName[1] = "PairsBarrelMEPP_jpsiO2MCdebugCuts";
//    dirName[2] = "PairsBarrelMEMM_jpsiO2MCdebugCuts";

    std::vector<TString> hist1dName;
    //hist1dName = {"Pt","Eta","Phi","MuonNCluster","pdca","RAtAbsorberEnd","Chi2","Chi2MCHMID","Chi2MCHMFT","Chi2MatchScoreMCHMFT","MuonCXX","MuonCYY","MuonCPhiPhi","MuonCTglTgl","MuonC1Pt21Pt2","MCHBitMap_vs_pt", "Mass","Mass_Pt","Eta_Pt","Mass_VtxZ"};
    hist1dName = {"Pt","Mass"};

    auto hlist = (THashList*) f[0]->Get(Form("%s/output", mainDirName.Data()));
    
    const int sizeHist = hist1dName.size();
    printf( "--> sizeHist = %d \n ",sizeHist);
    
    for(int k=0; k<4; k++){
        for(int i=0; i<2; i++){
            printf( "----> %d %d \n ",k,i);
            auto list = (TList*) hlist -> FindObject(dirName[k].Data());
            hist1dVar[k][i] = (TH1F*) list->FindObject(hist1dName[i].Data());
            hist1dVar[k][i] -> SetName(dirName[k]);
        }
    }
    
    printf("run: plotMuonsPM(int kplot, bool norm) \n");
}

void plotMuonsPM(int kplot, bool norm){
    
    hist1dVar[0][kplot]->SetMarkerColor(1); hist1dVar[0][kplot]->SetLineColor(1);
    hist1dVar[1][kplot]->SetMarkerColor(623); hist1dVar[1][kplot]->SetLineColor(623);
    hist1dVar[2][kplot]->SetMarkerColor(414); hist1dVar[2][kplot]->SetLineColor(414);
    hist1dVar[3][kplot]->SetMarkerColor(6); hist1dVar[3][kplot]->SetLineColor(6);
    
    if(norm){
        for (int i=0; i<4; i++){
            Double_t factor = 1.;
            hist1dVar[i][kplot]->Scale(factor/hist1dVar[i][kplot]->Integral());
        }
    }
    
    
    hist1dVar[0][kplot]->Draw("EPZ");
    hist1dVar[1][kplot]->Draw("EPZ same");
    hist1dVar[2][kplot]->Draw("EPZ same");
    hist1dVar[3][kplot]->Draw("EPZ same");

    //hist1dVar[0][0]->GetXaxis()->SetTitle(hist1dName[kplot].Data());
    //hist1dVar[0][0]->GetYaxis()->SetTitle("counts");
//    hist1dVar[0][0]->SetLabelSize(0.055, "xy");
//    hist1dVar[0][0]->SetLabelOffset(0.01, "xy");
//    hist1dVar[0][0]->SetTitleSize(0.055, "xy");
//    hist1dVar[0][0]->SetTitleOffset(1., "x");
//    hist1dVar[0][0]->SetTitleOffset(1.5, "y");
//    hist1dVar[0][0]->SetMarkerColor(1); hist1dVar[0][0]->SetLineColor(1); hist1dVar[0][0]->SetMarkerStyle(20);
//    hist1dVar[0][1]->SetMarkerColor(623); hist1dVar[0][1]->SetLineColor(623); hist1dVar[0][1]->SetMarkerStyle(24);
//    hist1dVar[0][2]->SetMarkerColor(414); hist1dVar[0][2]->SetLineColor(414); hist1dVar[0][2]->SetMarkerStyle(24);


    TLegend *leg = new TLegend(.14, .7, .25, .84);
    //leg->SetNColumns(2);
    leg->SetTextSize(0.055);
    leg->AddEntry(hist1dVar[0][kplot], "Paismuon_SEPM", " ");
    leg->AddEntry(hist1dVar[0][kplot], "MCH", "pl ");
    leg->AddEntry(hist1dVar[1][kplot], "MCH+MID", "pl");
    leg->AddEntry(hist1dVar[2][kplot], "muonLowPt", "pl");
    leg->AddEntry(hist1dVar[3][kplot], "muonQualityCuts", "pl");
    leg->Draw();
    leg->SetBorderSize(0);

    gStyle->SetOptStat(0);
    
}


int main(){
    
    
}

