
void countTracks(std::string AssessmentFileName)
{

  TFile *f1 = new TFile(AssessmentFileName.c_str());

  if (!f1)
  {
    std::cout << " bad file: " << AssessmentFileName << std::endl;
    return;
  }

  auto referenceRunHisto = (TH1F *)f1->Get("mMFTTrackNumberOfClusters");
  auto nTracks = referenceRunHisto->GetEntries();
  std::cout << "Number of MFT Tracks = " << nTracks << std::endl;
  auto recoPrimariesHisto = (TH1F *)f1->Get("mHistIsPrimaryRecoTrueMC");
  if (recoPrimariesHisto)
  {
    auto nPrimaries = recoPrimariesHisto->GetBinContent(2);
    auto nSecondaries = recoPrimariesHisto->GetBinContent(1);
    auto nTrue = nPrimaries + nSecondaries;
    auto nFakes = nTracks - nTrue;

    std::cout << nPrimaries / nTrue << " % primaries: " << nPrimaries << std::endl;
    std::cout << nSecondaries / nTrue << " % secondaries: " << nSecondaries << std::endl;
    std::cout << nFakes / nTrue << " % fakes: " << nFakes << std::endl;
  }

  auto etaDistrib = (TH1F *)f1->Get("mMFTTrackEta");
  auto PtVsEtaRecoFake = (TH2F *)f1->Get("mHistPtVsEtaRecoFake");
  auto *etaFakes = PtVsEtaRecoFake->ProjectionX();

  etaDistrib->Draw();
  new TCanvas();
  PtVsEtaRecoFake->Draw();
  new TCanvas();
  etaDistrib->Draw("");
  etaFakes->Draw("hist same");
  //new TCanvas();
  //etaFakes->Divide(etaDistrib);
  //etaFakes->Draw();
}

