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
void plot(int kplot = 0);
void plotEff(int kplot = 0);

const Int_t Nmax = 2;
TH1F *hist1dVar[50][20];
TH2F *hist2dVar[50][20];


void getComp(){
        
    TFile *f[Nmax];
    
    f[0]= new TFile("AnalysisResults_TR_efficiency_22i3d.root","read");

    TH1F *histo[Nmax];
    //histo[0] = (TH1F *)f[0]->Get("table-maker/output/Muons_BeforeCuts/Eta");
    //histo[0] = (TH1F *)f[0]->Get("analysis-qvector/Event_BeforeCuts/VtxZ");

    //histo[1] = (TH1F *)f[0]->Get("table-maker/output/Muons_muonQualityCuts/Eta");
    //histo[1] = (TH1F *)f[0]->Get("analysis-qvector/Event_AfterCuts/VtxZ");

    
    TString mainDirName;
    TString dirName[10];
    mainDirName = "analysis-same-event-pairing";
    //dirName[0] = "MCTruthGen_Jpsi";
    dirName[0] = "PairsMuonSEPM_muonTightQualityCutsForTests";
    dirName[1] = "PairsMuonSEPM_muonTightQualityCutsForTests_mumuFromJpsi";
    dirName[2] = "PairsMuonSEPM_muonTightQualityCutsForTests_mumuFromPsi2S";
    //dirName[0] = "MCTruthGen_Psi2S";
    //dirName[1] = "PairsMuonSEPM_muonQualityCuts_mumuFromPsi2S";
    
//    mainDirName = "analysis-event-mixing";
//    dirName[0] = "PairsBarrelMEPM_jpsiO2MCdebugCuts";
//    dirName[1] = "PairsBarrelMEPP_jpsiO2MCdebugCuts";
//    dirName[2] = "PairsBarrelMEMM_jpsiO2MCdebugCuts";

    std::vector<TString> hist1dName;
    hist1dName = {"Pt","Eta","Phi","MuonNClusters","pdca","RAtAbsorberEnd","Chi2","Chi2MCHMID","Chi2MCHMFT","Chi2MatchScoreMCHMFT","MuonCXX","MuonCYY","MuonCPhiPhi","MuonCTglTgl","MuonC1Pt21Pt2","MCHBitMap_vs_pt", "Mass","Mass_Pt","Eta_Pt","Mass_VtxZ"};
    
    auto hlist = (THashList*) f[0]->Get(Form("%s/output", mainDirName.Data()));
    
    const int sizeHist = hist1dName.size();
    
    for(int k=0; k<20; k++){
        for(int i=0; i<3; i++){
            auto list = (TList*) hlist -> FindObject(dirName[i].Data());
            hist1dVar[k][i] = (TH1F*) list->FindObject(hist1dName[k].Data());
            hist1dVar[k][i] -> SetName(dirName[i]);
            printf( "--> %d %d name = %s \n ",k, i, hist1dName[k].Data());

        }
    }
    

}


void getEff(){
        
    TFile *f[Nmax];
    
    f[0]= new TFile("AnalysisResults_TR_efficiency_22i3d.root","read");

    TH1F *histo[Nmax];
    //histo[0] = (TH1F *)f[0]->Get("table-maker/output/Muons_BeforeCuts/Eta");
    //histo[0] = (TH1F *)f[0]->Get("analysis-qvector/Event_BeforeCuts/VtxZ");

    //histo[1] = (TH1F *)f[0]->Get("table-maker/output/Muons_muonQualityCuts/Eta");
    //histo[1] = (TH1F *)f[0]->Get("analysis-qvector/Event_AfterCuts/VtxZ");

    
    TString mainDirName;
    TString dirName[10];
    mainDirName = "analysis-same-event-pairing";
    dirName[0] = "MCTruthGen_Jpsi";
    dirName[1] = "PairsMuonSEPM_muonQualityCuts_mumuFromJpsi";
    //dirName[1] = "PairsMuonSEPM_muonTightQualityCutsForTests_mumuFromJpsi";
    
    //dirName[0] = "MCTruthGen_Psi2S";
    //dirName[1] = "PairsMuonSEPM_muonQualityCuts_mumuFromPsi2S";
    
//    mainDirName = "analysis-event-mixing";
//    dirName[0] = "PairsBarrelMEPM_jpsiO2MCdebugCuts";
//    dirName[1] = "PairsBarrelMEPP_jpsiO2MCdebugCuts";
//    dirName[2] = "PairsBarrelMEMM_jpsiO2MCdebugCuts";

    std::vector<TString> hist1dName;
    hist1dName = {"Pt","Eta","Phi"};
    
    auto hlist = (THashList*) f[0]->Get(Form("%s/output", mainDirName.Data()));
    
    const int sizeHist = hist1dName.size();
    
    for(int k=0; k<3; k++){
        for(int i=0; i<2; i++){
            auto list = (TList*) hlist -> FindObject(dirName[i].Data());
            hist1dVar[k][i] = (TH1F*) list->FindObject(hist1dName[k].Data());
            hist1dVar[k][i] -> SetName(dirName[i]);
            printf( "--> name = %s \n ",hist1dName[k].Data());

        }
    }
    

}

void plot(int kplot){
    
    hist1dVar[kplot][0]->Draw("EPZ");
    hist1dVar[kplot][1]->Draw("EPZ same");
    hist1dVar[kplot][2]->Draw("EPZ same");

    TLegend *leg = new TLegend(.14, .7, .25, .84);
    //leg->SetNColumns(2);
    leg->SetTextSize(0.055);
    leg->AddEntry(hist1dVar[0][0], "Pairs (LHC21i3d)", " ");
    leg->AddEntry(hist1dVar[0][0], "All", "pl");
    leg->AddEntry(hist1dVar[0][1], "Jpsi", "pl");
    //leg->Draw();
    leg->SetBorderSize(0);

    gStyle->SetOptStat(0);
    
}


void plotEff(int kplot){
    
    //hist1dVar[0][1]->Add(hist1dVar[0][2]);
    hist1dVar[kplot][1]->Divide(hist1dVar[kplot][0]);
    hist1dVar[kplot][1]->Draw("EPZ");
    //hist1dVar[0][1]->Draw("EPZ same");

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
//
    TLegend *leg = new TLegend(.14, .7, .25, .84);
    //leg->SetNColumns(2);
    leg->SetTextSize(0.055);
    leg->AddEntry(hist1dVar[0][0], "Pairs (LHC21i3d)", " ");
    leg->AddEntry(hist1dVar[0][0], "PM", "pl");
    leg->AddEntry(hist1dVar[0][1], "PP+MM", "pl");
    //leg->Draw();
    leg->SetBorderSize(0);

    gStyle->SetOptStat(0);
    
}


int main(){
    
    
}

