// Macro to plot 2*2 histograms as summary of the assessment workflow

template <typename T2>
std::string to_string_wp(const T2 a_value, const int n = 5){
    std::ostringstream out;
    out << std::setprecision(n) << a_value;
    return out.str();
}
using namespace std;
void plotFile(TString prefix = "");

const Int_t Nmax = 15;

void plot(){
    TString filename[40];
    TString filename2[40];
    TString filename3[40];

    filename[0] = "30R_30Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[1] = "30R_50Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[2] = "30R_70Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[3] = "30R_100Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[4] = "30R_120Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[5] = "50R_30Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[6] = "50R_50Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[7] = "50R_70Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[8] = "50R_100Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[9] = "50R_120Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[10] = "70R_30Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[11] = "70R_50Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[12] = "70R_70Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[13] = "70R_100Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[14] = "70R_120Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[15] = "100R_30Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[16] = "100R_50Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[17] = "100R_70Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[18] = "100R_100Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[19] = "100R_120Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[20] = "120R_30Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[21] = "120R_50Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[22] = "120R_70Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[23] = "120R_100Phi_0.1RCut_-15.ZMin_15.ZMax";
    filename[24] = "120R_120Phi_0.1RCut_-15.ZMin_15.ZMax";
    
    filename2[0] = "30R_30Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[1] = "30R_50Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[2] = "30R_70Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[3] = "30R_100Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[4] = "30R_120Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[5] = "50R_30Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[6] = "50R_50Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[7] = "50R_70Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[8] = "50R_100Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[9] = "50R_120Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[10] = "70R_30Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[11] = "70R_50Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[12] = "70R_70Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[13] = "70R_100Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[14] = "70R_120Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[15] = "100R_30Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[16] = "100R_50Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[17] = "100R_70Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[18] = "100R_100Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[19] = "100R_120Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[20] = "120R_30Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[21] = "120R_50Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[22] = "120R_70Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[23] = "120R_100Phi_0.1RCut_-13.ZMin_13.ZMax";
    filename2[24] = "120R_120Phi_0.1RCut_-13.ZMin_13.ZMax";
    
    filename3[0] = "30R_30Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[1] = "30R_50Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[2] = "30R_70Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[3] = "30R_100Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[4] = "30R_120Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[5] = "50R_30Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[6] = "50R_50Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[7] = "50R_70Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[8] = "50R_100Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[9] = "50R_120Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[10] = "70R_30Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[11] = "70R_50Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[12] = "70R_70Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[13] = "70R_100Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[14] = "70R_120Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[15] = "100R_30Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[16] = "100R_50Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[17] = "100R_70Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[18] = "100R_100Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[19] = "100R_120Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[20] = "120R_30Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[21] = "120R_50Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[22] = "120R_70Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[23] = "120R_100Phi_0.1RCut_-18.ZMin_18.ZMax";
    filename3[24] = "120R_120Phi_0.1RCut_-18.ZMin_18.ZMax";
    
    for( int j=0; j<25; j++){
        plotFile(filename[j]);
        plotFile(filename2[j]);
        plotFile(filename3[j]);

    }
}


void plotFile(TString prefix = ""){
        
    TFile *f;
    TString assname = "MFTAssessment_";
    TString rootname = ".root";

    TString fullname = assname+prefix+rootname;

    f= new TFile(fullname,"read");
    if(!f){
        return;
    }
    std::cout <<" -> Histo loaded " << std::endl;

    TH2F *histoGen;
    TH2F *histoTrackable;
    TH2F *histoRecoTrue;
    TH2F *histoPhi;

    TLegend *leg[Nmax];
    TLegend *leg2[Nmax];

    TString sNPrimaries;
    TString sNSecondaries;
    TString sNFakes;
    TString sNPrimariesPer;
    TString sNSecondariesPer;
    TString sNFakesPer;

    histoGen = (TH2F *)f->Get("mHistZvtxVsEtaGen");
    histoTrackable = (TH2F *)f->Get("mHistRVsZTrackable");
    histoRecoTrue = (TH2F *)f->Get("mHistZvtxVsEtaRecoTrueMC");

    histoRecoTrue->Divide(histoGen);

    histoPhi = (TH2F *)f->Get("mHistPhiVsPtTrackable");
    auto *histoPhiProj  = histoPhi->ProjectionY();

    auto etaDistrib = (TH1F *)f->Get("mMFTTrackEta");
    auto PtVsEtaRecoFake = (TH2F *)f->Get("mHistPtVsEtaRecoFake");
    auto *etaFakes = PtVsEtaRecoFake->ProjectionX();

    auto PhiVsPtRecoFake = (TH2F *)f->Get("mHistPhiVsPtRecoFake");
    auto *phiFakes = PhiVsPtRecoFake->ProjectionY();
    auto HistoPhi = (TH1F *)f->Get("mMFTTrackPhi");

    auto referenceRunHisto = (TH1F *)f->Get("mMFTTrackNumberOfClusters");
    auto nTracks = referenceRunHisto->GetEntries();
    std::cout << "Number of MFT Tracks = " << nTracks << std::endl;
    auto recoPrimariesHisto = (TH1F *)f->Get("mHistIsPrimaryRecoTrueMC");
    if (recoPrimariesHisto)
    {
      auto nPrimaries = recoPrimariesHisto->GetBinContent(2);
      auto nSecondaries = recoPrimariesHisto->GetBinContent(1);
      auto nTrue = nPrimaries + nSecondaries;
      auto nFakes = nTracks - nTrue;

      std::cout << nPrimaries / nTrue << " % primaries: " << nPrimaries << std::endl;
      std::cout << nSecondaries / nTrue << " % secondaries: " << nSecondaries << std::endl;
      std::cout << nFakes / nTrue << " % fakes: " << nFakes << std::endl;

        sNPrimaries = to_string_wp(nPrimaries);
        sNSecondaries = to_string_wp(nSecondaries);
        sNFakes = to_string_wp(nFakes);

        sNPrimariesPer = to_string_wp(nPrimaries/nTrue);
        sNSecondariesPer = to_string_wp(nSecondaries/nTrue);
        sNFakesPer = to_string_wp(nFakes/nTrue);
    }

    etaFakes->SetLineColor(2);
    phiFakes->SetLineColor(2);

    leg[0] = new TLegend(.14, 0.93, .2, 0.99);
    leg[1] = new TLegend(.3, .32, .4, .4);
    leg[2] = new TLegend(.3, .24, .4, .32);
    leg[3] = new TLegend(.3, .16, .4, .24);
    leg[4] = new TLegend(.1, .78, .4, .82);

    for(int i=0; i<5;i++){
        leg[i]->SetBorderSize(0);
        leg[i]->SetTextSize(0.06);
    }
    leg[3]->SetTextColor(2);

    leg[0]->AddEntry(histoRecoTrue, prefix, " ");
    leg[1]->AddEntry(histoRecoTrue, sNPrimariesPer+" % primaries:"+sNPrimaries, " ");
    leg[2]->AddEntry(histoRecoTrue, sNSecondariesPer+" % secondaries:"+sNSecondaries, " ");
    leg[3]->AddEntry(histoRecoTrue, sNFakesPer+" % fakes:"+sNFakes, " ");
    leg[4]->AddEntry(histoRecoTrue, "Acc x Eff: RecoTrue/Generated", " ");

    histoTrackable->SetAxisRange(0.5,10.,"Y");
    histoPhiProj->SetMinimum(0);
    gStyle->SetOptTitle(0);
    histoRecoTrue->SetTitle("");
    
    auto c = new TCanvas("c", "", 700, 500);
    c->Divide(2, 2);
    std::cout <<" -> Drawing histograms " << std::endl <<
    c->cd(1); histoRecoTrue->Draw("COLZ"); leg[0]->Draw(); leg[4]->Draw();
    c->cd(2); etaDistrib->Draw("HIST"); etaFakes->Draw(" SAME"); leg[1]->Draw(); leg[2]->Draw(); leg[3]->Draw();
    c->cd(3); histoTrackable->Draw("COLZ");
    c->cd(4); histoPhiProj  ->Draw("HIST SAME"); phiFakes->Draw(" SAME");

    c->SaveAs("canvas_"+prefix+".root");
    c->SaveAs("canvas_"+prefix+".png");

    delete c;
    delete f;
    for(int i=0; i<5;i++){
        delete leg[i];
    }
}



