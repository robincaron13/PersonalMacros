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

const Int_t Nmax = 4;
const Int_t Nmax0 = 3;

void plotPsi(){
        
    TFile *f[Nmax0];
    
    f[0]= new TFile("AnalysisResults_22s_barrel-large.root","read");
    f[1]= new TFile("AnalysisResults_22s_forward-large.root","read");
    f[2]= new TFile("AnalysisResults_22s_forward2-large.root","read");


    TH1F *hphi[Nmax0];
    for(int i=0; i<Nmax0; i++){
        hphi[i] = (TH1F *)f[i]->Get("analysis-qvector/Psi");
        
        if(i==0) hphi[i]->Draw("HIST");
        if(i>0)  hphi[i]->Draw("HIST same");
        
        Double_t factor = 1.;
        hphi[i]->Scale(factor/hphi[i]->Integral());
        hphi[i]->SetLineColor(i+1);
       

    }
    hphi[0]->GetXaxis()->SetTitle("#Psi_{2} ");
    hphi[0]->GetYaxis()->SetTitle("normalized counts");

    hphi[0]->SetLabelSize(0.055, "xy");
    hphi[0]->SetLabelOffset(0.01, "xy");
    hphi[0]->SetTitleSize(0.055, "xy");
    hphi[0]->SetTitleOffset(1., "x");
    hphi[0]->SetTitleOffset(1.5, "y");
    
    hphi[0]->SetLineColor(1); hphi[0]->SetMarkerStyle(24);
    hphi[1]->SetLineColor(kBlue+1);
    hphi[2]->SetLineColor(kGreen+1);

    TLegend *leg = new TLegend(.6, .6, .8, .8);
    //leg->SetNColumns(2);
    leg->SetTextSize(0.055);
    leg->AddEntry(hphi[0], "LHC22s pass3", " ");
    leg->AddEntry(hphi[0], "Barrel tracks", "l");
    leg->AddEntry(hphi[1], "MFT tracks", "l");
    leg->AddEntry(hphi[2], "FwdTracks w filter", "l");
    leg->Draw();
    leg->SetBorderSize(0);

    gStyle->SetOptStat(0);

}

void ploteta(){
        
    TFile *f[Nmax0];
    
    f[0]= new TFile("AnalysisResults_22s_barrel-large.root","read");
    f[1]= new TFile("AnalysisResults_22s_forward-large.root","read");
    f[2]= new TFile("AnalysisResults_22s_forward2-large.root","read");


    TH1F *hphi[Nmax0];
    for(int i=0; i<Nmax0; i++){
        hphi[i] = (TH1F *)f[i]->Get("analysis-qvector/eta");
        
        if(i==0) hphi[i]->Draw("HIST");
        if(i>0)  hphi[i]->Draw("HIST same");
        
        Double_t factor = 1.;
        hphi[i]->Scale(factor/hphi[i]->Integral());
        hphi[i]->SetLineColor(i+1);
       

    }
    hphi[0]->GetXaxis()->SetTitle("#eta_{trk} ");
    hphi[0]->GetYaxis()->SetTitle("normalized counts");

    hphi[0]->SetLabelSize(0.055, "xy");
    hphi[0]->SetLabelOffset(0.01, "xy");
    hphi[0]->SetTitleSize(0.055, "xy");
    hphi[0]->SetTitleOffset(1., "x");
    hphi[0]->SetTitleOffset(1.5, "y");
    
    hphi[0]->SetLineColor(1); hphi[0]->SetMarkerStyle(24);
    hphi[1]->SetLineColor(kBlue+1); hphi[1]->SetMarkerStyle(25);
    hphi[2]->SetLineColor(kGreen+1);

    TLegend *leg = new TLegend(.6, .6, .8, .8);
    //leg->SetNColumns(2);
    leg->SetTextSize(0.055);
    leg->AddEntry(hphi[0], "LHC22s pass3", " ");
    leg->AddEntry(hphi[0], "Barrel tracks", "l");
    leg->AddEntry(hphi[1], "MFT tracks", "l");
    leg->AddEntry(hphi[2], "FwdTracks w filter", "l");
    leg->Draw();
    leg->SetBorderSize(0);

    gStyle->SetOptStat(0);

}

void plotphi(){
        
    TFile *f[Nmax0];
    
    f[0]= new TFile("AnalysisResults_22s_barrel-large.root","read");
    f[1]= new TFile("AnalysisResults_22s_forward-large.root","read");
    f[2]= new TFile("AnalysisResults_22s_forward2-large.root","read");


    TH1F *hphi[Nmax0];
    for(int i=0; i<Nmax0; i++){
        hphi[i] = (TH1F *)f[i]->Get("analysis-qvector/phi");
        
        if(i==0) hphi[i]->Draw("HIST");
        if(i>0)  hphi[i]->Draw("HIST same");
        
        Double_t factor = 1.;
        hphi[i]->Scale(factor/hphi[i]->Integral());
        hphi[i]->SetLineColor(i+1);
       

    }
    hphi[0]->GetXaxis()->SetTitle("#varphi_{trk} ");
    hphi[0]->GetYaxis()->SetTitle("normalised counts");

    hphi[0]->SetLabelSize(0.055, "xy");
    hphi[0]->SetLabelOffset(0.01, "xy");
    hphi[0]->SetTitleSize(0.055, "xy");
    hphi[0]->SetTitleOffset(1., "x");
    hphi[0]->SetTitleOffset(1.5, "y");
    
    hphi[0]->SetLineColor(1); hphi[0]->SetMarkerStyle(24);
    hphi[1]->SetLineColor(kBlue+1); hphi[1]->SetMarkerStyle(25);
    hphi[2]->SetLineColor(kGreen+1);

    TLegend *leg = new TLegend(.6, .6, .8, .8);
    //leg->SetNColumns(2);
    leg->SetTextSize(0.055);
    leg->AddEntry(hphi[0], "LHC22s pass3", " ");
    leg->AddEntry(hphi[0], "Barrel tracks", "l");
    leg->AddEntry(hphi[1], "MFT tracks", "l");
    leg->AddEntry(hphi[2], "FwdTracks w filter", "l");
    leg->Draw();
    leg->SetBorderSize(0);

    gStyle->SetOptStat(0);

}

void plotVtx(){
        
    TFile *f[Nmax0];
    
    f[0]= new TFile("AnalysisResults_22s_barrel-large.root","read");
    f[1]= new TFile("AnalysisResults_22s_forward-large.root","read");
 
    TString mainDirName;
    TString dirName[10];
    mainDirName = "table-maker";
    dirName[0] = "Event_BeforeCuts";
    dirName[1] = "Event_AfterCuts";

    TH1F *hphi[Nmax0];
    hphi[0] = (TH1F *)f[0]->Get("analysis-qvector/outputQA/Event_BeforeCuts/VtxZ");
    hphi[1] = (TH1F *)f[0]->Get("analysis-qvector/outputQA/Event_AfterCuts/VtxZ");
    
    auto hlist = (THashList*) f[0]->Get(Form("%s/output", mainDirName.Data()));

    auto list0 = (TList*) hlist -> FindObject(dirName[0].Data());
    auto list1 = (TList*) hlist -> FindObject(dirName[1].Data());

    hphi[0] = (TH1F*) list0->FindObject("VtxZ");
    hphi[1] = (TH1F*) list1->FindObject("VtxZ");

    for(int i=0; i<Nmax0; i++){
        
        if(i==0) hphi[i]->Draw("HIST");
        if(i>0)  hphi[i]->Draw("HIST same");
        
        Double_t factor = 1.;
        //hphi[i]->Scale(factor/hphi[i]->Integral());
        hphi[i]->SetLineColor(i+1);
       

    }
    hphi[0]->GetXaxis()->SetTitle("z_{vtx} ");
    hphi[0]->GetYaxis()->SetTitle("normalized counts");

    hphi[0]->SetLabelSize(0.055, "xy");
    hphi[0]->SetLabelOffset(0.01, "xy");
    hphi[0]->SetTitleSize(0.055, "xy");
    hphi[0]->SetTitleOffset(1., "x");
    hphi[0]->SetTitleOffset(1.5, "y");
    
    hphi[0]->SetLineColor(1); hphi[0]->SetMarkerStyle(24);
    hphi[1]->SetLineColor(kBlue+1); hphi[1]->SetMarkerStyle(25);
    
    TLegend *leg = new TLegend(.6, .6, .8, .8);
    //leg->SetNColumns(2);
    leg->SetTextSize(0.055);
    leg->AddEntry(hphi[0], "LHC22s pass3", " ");
    leg->AddEntry(hphi[0], dirName[0].Data(), "l");
    leg->AddEntry(hphi[1], dirName[1].Data(), "l");
    leg->Draw();
    leg->SetBorderSize(0);

    gStyle->SetOptStat(0);

}

void plotQn(){
        
    TFile *f[Nmax0];
    
    f[0]= new TFile("AnalysisResults_22s_barrel-large.root","read");
    f[1]= new TFile("AnalysisResults_22s_forward-large.root","read");
    f[2]= new TFile("AnalysisResults_22s_forward2-large.root","read");

    TString mainDirName;
    TString dirName[10];
    mainDirName = "analysis-qvector";
    dirName[0] = "Event_BeforeCuts";
    dirName[1] = "Event_AfterCuts";

    TString track_name = "Barrel tracks ";
    TString Track_leg[10];
    Track_leg[0] = track_name+dirName[0];
    Track_leg[1] = track_name+dirName[1];

    
    TH1F *histo[30];
   
    auto hlist0 = (THashList*) f[0]->Get(Form("%s/outputQA", mainDirName.Data()));
    auto hlist1 = (THashList*) f[1]->Get(Form("%s/outputQA", mainDirName.Data()));
    auto hlist2 = (THashList*) f[2]->Get(Form("%s/outputQA", mainDirName.Data()));

    
    auto list00 = (TList*) hlist0 -> FindObject(dirName[0].Data());
    auto list0 = (TList*) hlist0 -> FindObject(dirName[1].Data());

    auto list1 = (TList*) hlist1 -> FindObject(dirName[1].Data());
    auto list2 = (TList*) hlist2 -> FindObject(dirName[1].Data());

    histo[0] = (TH1F*) list00->FindObject("Q2X0C");
    histo[1] = (TH1F*) list0->FindObject("Q2X0C");
    histo[2] = (TH1F*) list1->FindObject("Q2X0C");
    histo[10] = (TH1F*) list2->FindObject("Q2X0C");

    histo[3] = (TH1F*) list00->FindObject("Q2Y0C");
    histo[4] = (TH1F*) list0->FindObject("Q2Y0C");
    histo[5] = (TH1F*) list1->FindObject("Q2Y0C");
    histo[11] = (TH1F*) list2->FindObject("Q2Y0C");

    auto c = new TCanvas("c", "", 800, 400);
    c->Divide(2, 1);
    
    c->cd(1);
    histo[0]->Draw("HIST");
    histo[1]->Draw("HIST same");
    histo[2]->Draw("HIST same");
    histo[10]->Draw("HIST same");

    Double_t factor = 1.;
    //histo[i]->Scale(factor/histo[i]->Integral());
    gPad->SetBottomMargin(0.12);
    gPad->SetLeftMargin(0.18);
    
    c->cd(2);
    histo[3]->Draw("HIST");
    histo[4]->Draw("HIST same");
    histo[5]->Draw("HIST same");
    histo[11]->Draw("HIST same");

    Double_t factor2 = 1.;
    //histo[i]->Scale(factor/histo[i]->Integral());
    gPad->SetBottomMargin(0.12);
    gPad->SetLeftMargin(0.18);
    
    histo[0]->GetXaxis()->SetTitle("Q_{2,x}^{C} ");
    //histo[0]->GetYaxis()->SetTitle("normalized counts");
    histo[0]->GetYaxis()->SetTitle("counts");

    histo[0]->SetLabelSize(0.055, "xy");
    histo[0]->SetLabelOffset(0.01, "xy");
    histo[0]->SetTitleSize(0.055, "xy");
    histo[0]->SetTitleOffset(1., "x");
    histo[0]->SetTitleOffset(1.5, "y");
    
    histo[0]->SetLineColor(1);
    histo[1]->SetLineColor(2);
    histo[2]->SetLineColor(kBlue+1);
    histo[10]->SetLineColor(kGreen+1);

    
    histo[3]->GetXaxis()->SetTitle("Q_{2,y}^{C} ");
    //histo[0]->GetYaxis()->SetTitle("normalized counts");
    histo[3]->GetYaxis()->SetTitle("counts");
    histo[3]->SetLabelSize(0.055, "xy");
    histo[3]->SetLabelOffset(0.01, "xy");
    histo[3]->SetTitleSize(0.055, "xy");
    histo[3]->SetTitleOffset(1., "x");
    histo[3]->SetTitleOffset(1.5, "y");
    
    histo[3]->SetLineColor(1);
    histo[4]->SetLineColor(2);
    histo[5]->SetLineColor(kBlue+1);
    histo[11]->SetLineColor(kGreen+1);

    TLegend *leg = new TLegend(.6, .6, .8, .8);
    //leg->SetNColumns(2);
    leg->SetTextSize(0.055);
    leg->AddEntry(histo[0], "LHC22s pass3", " ");
    leg->AddEntry(histo[0], Track_leg[0].Data(), "l");
    leg->AddEntry(histo[1], Track_leg[1].Data(), "l");
    leg->AddEntry(histo[2], "MFT tracks", "l");
    leg->AddEntry(histo[10], "Fwd tracks", "l");
    leg->Draw();
    leg->SetBorderSize(0);


    leg->Draw();
    leg->SetBorderSize(0);
    gStyle->SetOptStat(0);

}


void plotQn_vs_Z(){
        
    TFile *f[Nmax0];
    
    f[0]= new TFile("AnalysisResults_22s_barrel-large.root","read");
    f[1]= new TFile("AnalysisResults_22s_forward-large.root","read");
    f[2]= new TFile("AnalysisResults_22s_forward2-large.root","read");

    TString mainDirName;
    TString dirName[10];
    mainDirName = "analysis-qvector";
    dirName[0] = "Event_BeforeCuts";
    dirName[1] = "Event_AfterCuts";

    TString track_name = "Barrel tracks ";
    TString Track_leg[10];
    Track_leg[0] = track_name+dirName[0];
    Track_leg[1] = track_name+dirName[1];

    
    TProfile *histo[30];
   
    auto hlist0 = (THashList*) f[0]->Get(Form("%s/outputQA", mainDirName.Data()));
    auto hlist1 = (THashList*) f[1]->Get(Form("%s/outputQA", mainDirName.Data()));
    auto hlist2 = (THashList*) f[2]->Get(Form("%s/outputQA", mainDirName.Data()));

    
    auto list00 = (TList*) hlist0 -> FindObject(dirName[0].Data());
    auto list0 = (TList*) hlist0 -> FindObject(dirName[1].Data());

    auto list1 = (TList*) hlist1 -> FindObject(dirName[1].Data());
    auto list2 = (TList*) hlist2 -> FindObject(dirName[1].Data());

    histo[0] = (TProfile*) list00->FindObject("Q2X0A_VtxZ");
    histo[1] = (TProfile*) list0->FindObject("Q2X0A_VtxZ");
    histo[2] = (TProfile*) list1->FindObject("Q2X0A_VtxZ");
    histo[10] = (TProfile*) list2->FindObject("Q2Y0A_VtxZ");

    histo[3] = (TProfile*) list00->FindObject("Q2Y0A_VtxZ");
    histo[4] = (TProfile*) list0->FindObject("Q2Y0A_VtxZ");
    histo[5] = (TProfile*) list1->FindObject("Q2Y0A_VtxZ");
    histo[11] = (TProfile*) list2->FindObject("Q2Y0A_VtxZ");

    auto c = new TCanvas("c", "", 800, 400);
    c->Divide(2, 1);
    
    c->cd(1);
    histo[0]->Draw("EP");
    histo[1]->Draw("EP same");
    histo[2]->Draw("EP same");
    histo[10]->Draw("EP same");

    Double_t factor = 1.;
    //histo[i]->Scale(factor/histo[i]->Integral());
    gPad->SetBottomMargin(0.12);
    gPad->SetLeftMargin(0.18);
    
    c->cd(2);
    histo[3]->Draw("EP");
    histo[4]->Draw("EP same");
    histo[5]->Draw("EP same");
    histo[11]->Draw("EP same");

    Double_t factor2 = 1.;
    //histo[i]->Scale(factor/histo[i]->Integral());
    gPad->SetBottomMargin(0.12);
    gPad->SetLeftMargin(0.18);
    
    histo[0]->GetYaxis()->SetTitle("Q_{2,x}^{A} ");
    //histo[0]->GetYaxis()->SetTitle("normalized counts");
    histo[0]->GetXaxis()->SetTitle("z_{vtx} (cm)");

    histo[0]->SetLabelSize(0.055, "xy");
    histo[0]->SetLabelOffset(0.01, "xy");
    histo[0]->SetTitleSize(0.055, "xy");
    histo[0]->SetTitleOffset(1., "x");
    histo[0]->SetTitleOffset(1.5, "y");
    
    histo[0]->SetLineColor(1);
    histo[1]->SetLineColor(2);
    histo[2]->SetLineColor(kBlue+1);
    histo[10]->SetLineColor(kGreen+1);

    
    histo[3]->GetYaxis()->SetTitle("Q_{2,y}^{A} ");
    //histo[0]->GetYaxis()->SetTitle("normalized counts");
    histo[3]->GetXaxis()->SetTitle("z_{vtx} (cm)");
    histo[3]->SetLabelSize(0.055, "xy");
    histo[3]->SetLabelOffset(0.01, "xy");
    histo[3]->SetTitleSize(0.055, "xy");
    histo[3]->SetTitleOffset(1., "x");
    histo[3]->SetTitleOffset(1.5, "y");
    
    histo[3]->SetLineColor(1);
    histo[4]->SetLineColor(2);
    histo[5]->SetLineColor(kBlue+1);
    histo[11]->SetLineColor(kGreen+1);

    TLegend *leg = new TLegend(.6, .6, .8, .8);
    //leg->SetNColumns(2);
    leg->SetTextSize(0.055);
    leg->AddEntry(histo[0], "LHC22s pass3", " ");
    leg->AddEntry(histo[0], Track_leg[0].Data(), "l");
    leg->AddEntry(histo[1], Track_leg[1].Data(), "l");
    leg->AddEntry(histo[2], "MFT tracks", "l");
    leg->AddEntry(histo[10], "Fwd tracks", "l");
    leg->Draw();
    leg->SetBorderSize(0);


    leg->Draw();
    leg->SetBorderSize(0);
    gStyle->SetOptStat(0);

}

void compareMFT_ITS_Qn(){
        
    const int n =2;
    TFile *f[n];
    
    f[0]= new TFile("AnalysisResults_tracks.root","read");
    f[1]= new TFile("AnalysisResults_mfttracks.root","read");
   

    auto c = new TCanvas("c", "", 800, 400);
    c->Divide(2, 1);
    
    TH1F *hphi[n];
    TH1F *hphi2[n];

    for(int i=0; i<n; i++){
        hphi[i] = (TH1F *)f[i]->Get("qvector-analysis/h2QnX");
        hphi2[i] = (TH1F *)f[i]->Get("qvector-analysis/h2QnY");

        c->cd(1);
        if(i==0) hphi[i]->Draw("HIST");
        if(i>0)  hphi[i]->Draw("HIST same");
        Double_t factor = 1.;
        hphi[i]->Scale(factor/hphi[i]->Integral());
        gPad->SetBottomMargin(0.12);
        gPad->SetLeftMargin(0.18);
        
        c->cd(2);
        if(i==0) hphi2[i]->Draw("HIST");
        if(i>0)  hphi2[i]->Draw("HIST same");
        Double_t factor2 = 1.;
        hphi2[i]->Scale(factor/hphi2[i]->Integral());
        gPad->SetBottomMargin(0.12);
        gPad->SetLeftMargin(0.18);
    }
    hphi[0]->GetXaxis()->SetTitle("Q_{2,x} ");
    hphi[0]->GetYaxis()->SetTitle("normalized counts");

    hphi[0]->SetLineColor(1); hphi[0]->SetMarkerStyle(24);
    hphi[1]->SetLineColor(kBlue+1); hphi[1]->SetMarkerStyle(25);

    hphi2[0]->GetXaxis()->SetTitle("Q_{2,y} ");
    hphi2[0]->GetYaxis()->SetTitle("normalized counts");

    hphi2[0]->SetLineColor(1); hphi2[0]->SetMarkerStyle(24);
    hphi2[1]->SetLineColor(kBlue+1); hphi2[1]->SetMarkerStyle(25);
    
    hphi[0]->SetLabelSize(0.055, "xy");
    hphi[0]->SetLabelOffset(0.01, "xy");
    hphi[0]->SetTitleSize(0.055, "xy");
    hphi[0]->SetTitleOffset(1., "x");
    hphi[0]->SetTitleOffset(1.5, "y");

    hphi2[0]->SetLabelSize(0.055, "xy");
    hphi2[0]->SetLabelOffset(0.01, "xy");
    hphi2[0]->SetTitleSize(0.055, "xy");
    hphi2[0]->SetTitleOffset(1., "x");
    hphi2[0]->SetTitleOffset(1.5, "y");
    
    TLegend *leg = new TLegend(.6, .6, .8, .8);
    //leg->SetNColumns(2);
    leg->AddEntry(hphi[0], "Tracks", "l");
    //leg->AddEntry(hphi[1], "MC pp rec LHC21i3d", "l");
    leg->AddEntry(hphi[1], "MFT Tracks", "l");
    leg->SetTextSize(0.055);

    leg->Draw();
    leg->SetBorderSize(0);

    c->cd(1);
    leg->Draw();

    
    gStyle->SetOptStat(0);

}



void compareMFT_ITS_Nch(){
        
    const int n =2;
    TFile *f[n];
    
    f[0]= new TFile("AnalysisResults_tracks.root","read");
    f[1]= new TFile("AnalysisResults_mfttracks.root","read");
   

    auto c = new TCanvas("c", "", 800, 400);
    c->Divide(2, 1);
    
    TH1F *hphi[n];
    TH1F *hphi2[n];

    for(int i=0; i<n; i++){
        hphi[i] = (TH1F *)f[i]->Get("qvector-analysis/hmult");
        hphi2[i] = (TH1F *)f[i]->Get("qvector-analysis/htracketa");

        c->cd(1);
        if(i==0) hphi[i]->Draw("HIST");
        if(i>0)  hphi[i]->Draw("HIST same");
        Double_t factor = 1.;
        hphi[i]->Scale(factor/hphi[i]->Integral());
        gPad->SetBottomMargin(0.12);
        gPad->SetLeftMargin(0.18);
        
        c->cd(2);
        if(i==0) hphi2[i]->Draw("HIST");
        if(i>0)  hphi2[i]->Draw("HIST same");
        Double_t factor2 = 1.;
        hphi2[i]->Scale(factor/hphi2[i]->Integral());
        gPad->SetBottomMargin(0.12);
        gPad->SetLeftMargin(0.18);
    }
    hphi[0]->GetXaxis()->SetTitle("N_{ch} ");
    hphi[0]->GetYaxis()->SetTitle("normalized counts");

    hphi[0]->SetLineColor(1); hphi[0]->SetMarkerStyle(24);
    hphi[1]->SetLineColor(kBlue+1); hphi[1]->SetMarkerStyle(25);

    hphi2[0]->GetXaxis()->SetTitle("#eta");
    hphi2[0]->GetYaxis()->SetTitle("normalized counts");

    hphi2[0]->SetLineColor(1); hphi2[0]->SetMarkerStyle(24);
    hphi2[1]->SetLineColor(kBlue+1); hphi2[1]->SetMarkerStyle(25);
    
    hphi[0]->SetLabelSize(0.055, "xy");
    hphi[0]->SetLabelOffset(0.01, "xy");
    hphi[0]->SetTitleSize(0.055, "xy");
    hphi[0]->SetTitleOffset(1., "x");
    hphi[0]->SetTitleOffset(1.5, "y");

    hphi2[0]->SetLabelSize(0.055, "xy");
    hphi2[0]->SetLabelOffset(0.01, "xy");
    hphi2[0]->SetTitleSize(0.055, "xy");
    hphi2[0]->SetTitleOffset(1., "x");
    hphi2[0]->SetTitleOffset(1.5, "y");
    
    TLegend *leg = new TLegend(.6, .6, .8, .8);
    //leg->SetNColumns(2);
    leg->AddEntry(hphi[0], "Tracks", "l");
    //leg->AddEntry(hphi[1], "MC pp rec LHC21i3d", "l");
    leg->AddEntry(hphi[1], "MFT Tracks", "l");
    leg->SetTextSize(0.055);

    leg->Draw();
    leg->SetBorderSize(0);

    c->cd(1);
    leg->Draw();

    
    gStyle->SetOptStat(0);

}





void compareMFT_ITS_Fwd(){
        
    const int n =2;
    TFile *f[n];
    
    f[0]= new TFile("mc-pbpb/AnalysisResults_tracks.root","read");
    f[1]= new TFile("mc-pbpb/AnalysisResults_mfttracks.root","read");
   

    auto c = new TCanvas("c", "", 800, 400);
    c->Divide(2, 1);
    
    TProfile *hphi[n],*hphi1[n],*hphi2[n];
    TProfile *hphi20[n],*hphi21[n],*hphi22[n];

    for(int i=0; i<n; i++){
        hphi[i] = (TProfile *)f[i]->Get("qvector-analysis/pT_h2VnSP_0");
        hphi1[i] = (TProfile *)f[i]->Get("qvector-analysis/pT_h2VnSP_2");
        hphi2[i] = (TProfile *)f[i]->Get("qvector-analysis/pT_h2VnSP_4");

        hphi20[i] = (TProfile *)f[i]->Get("qvector-analysis/pT_h2VnEP_0");
        hphi21[i] = (TProfile *)f[i]->Get("qvector-analysis/pT_h2VnEP_2");
        hphi22[i] = (TProfile *)f[i]->Get("qvector-analysis/pT_h2VnEP_4");

        c->cd(1);
        if(i==0) hphi[i]->Draw("EPZ");
        if(i>0)  hphi[i]->Draw("EPZ same");hphi1[i]->Draw("EPZ same");hphi2[i]->Draw("EPZ same");
        
        gPad->SetBottomMargin(0.12);
        gPad->SetLeftMargin(0.18);
        
        c->cd(2);
        if(i==0) hphi20[i]->Draw("EPZ");
        if(i>0)  hphi20[i]->Draw("EPZ same");hphi21[i]->Draw("EPZ same");hphi22[i]->Draw("EPZ same");
        
        gPad->SetBottomMargin(0.12);
        gPad->SetLeftMargin(0.18);
        
    }
    hphi[0]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c}^{2})");
    hphi[0]->GetYaxis()->SetTitle("raw #it{v}_{2}{SP} ");

    hphi[0]->SetLineColor(1); hphi[0]->SetMarkerStyle(24);
    hphi[1]->SetLineColor(kBlue+1); hphi[1]->SetMarkerStyle(25);
    hphi1[0]->SetLineColor(kOrange+1); hphi1[0]->SetMarkerStyle(24);
    hphi1[1]->SetLineColor(kRed+1); hphi1[1]->SetMarkerStyle(25);
    hphi2[0]->SetLineColor(kMagenta+1); hphi2[0]->SetMarkerStyle(24);
    hphi2[1]->SetLineColor(kGreen+1); hphi2[1]->SetMarkerStyle(25);
    
    hphi20[0]->GetXaxis()->SetTitle("#it{p}_{T} (GeV/#it{c}^{2})");
    hphi20[0]->GetYaxis()->SetTitle("raw #it{v}_{2}{EP}  ");

    hphi20[0]->SetLineColor(1); hphi20[0]->SetMarkerStyle(24);
    hphi20[1]->SetLineColor(kBlue+1); hphi20[1]->SetMarkerStyle(25);
    hphi21[0]->SetLineColor(kOrange+1); hphi21[0]->SetMarkerStyle(24);
    hphi21[1]->SetLineColor(kRed+1); hphi21[1]->SetMarkerStyle(25);
    hphi22[0]->SetLineColor(kMagenta+1); hphi22[0]->SetMarkerStyle(24);
    hphi22[1]->SetLineColor(kGreen+1); hphi22[1]->SetMarkerStyle(25);
    
    hphi[0]->SetLabelSize(0.055, "xy");
    hphi[0]->SetLabelOffset(0.01, "xy");
    hphi[0]->SetTitleSize(0.055, "xy");
    hphi[0]->SetTitleOffset(1., "x");
    hphi[0]->SetTitleOffset(1.5, "y");

    hphi20[0]->SetLabelSize(0.055, "xy");
    hphi20[0]->SetLabelOffset(0.01, "xy");
    hphi20[0]->SetTitleSize(0.055, "xy");
    hphi20[0]->SetTitleOffset(1., "x");
    hphi20[0]->SetTitleOffset(1.5, "y");
    
    TLegend *leg = new TLegend(.6, .6, .8, .8);
    //leg->SetNColumns(2);
    leg->AddEntry(hphi[0], "Q-ref Tracks", "lp");
    leg->AddEntry(hphi[1], "Q-ref MFT Tracks", "lp");
    leg->AddEntry(hphi[0], "MFT-MCH-MID", "l");
    leg->AddEntry(hphi1[0], "MFT-MCH", "l");
    leg->AddEntry(hphi2[0], "MCH", "l");
    //leg->AddEntry(hphi[1], "MC pp rec LHC21i3d", "l");
    leg->SetTextSize(0.055);
    leg->SetBorderSize(0);

    TLegend *leg2 = new TLegend(.6, .6, .8, .8);
    //leg->SetNColumns(2);
    leg2->AddEntry(hphi20[0], "Q-ref Tracks", "lp");
    leg2->AddEntry(hphi20[1], "Q-ref MFT Tracks", "lp");
    leg2->AddEntry(hphi20[1], "MFT-MCH-MID", "l");
    leg2->AddEntry(hphi21[1], "MFT-MCH", "l");
    leg2->AddEntry(hphi22[1], "MCH", "l");
    //leg->AddEntry(hphi[1], "MC pp rec LHC21i3d", "l");
    leg2->SetTextSize(0.055);

    leg2->Draw();
    leg2->SetBorderSize(0);
    
    c->cd(1);
    leg->Draw();

    
    gStyle->SetOptStat(0);

}

int main(){
    
    
}

