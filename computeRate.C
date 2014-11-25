
TChain *chain_DY = new TChain("myTree");
TChain *chain_WMuNu = new TChain("myTree");
TChain *chain_QCDMu20to30 = new TChain("myTree");
TChain *chain_QCDMu30to50 = new TChain("myTree");
TChain *chain_QCDMu50to80 = new TChain("myTree");
TChain *chain_QCDMu80to120 = new TChain("myTree");

struct rateError{
    float rate;
    float error;
    float purity;
};

rateError giveTheRate(TString cut){
    float rateDY = 1.4e-2*2008.4*chain_DY->GetEntries(cut)/chain_DY->GetEntries();
    float rateW = 1.4e-2*16100.*chain_WMuNu->GetEntries(cut)/chain_WMuNu->GetEntries();
    float rateQCDMu20to30 = 1.4e-2*675300000.*0.004*chain_QCDMu20to30->GetEntries(cut)/chain_QCDMu20to30->GetEntries();
    float rateQCDMu30to50 = 1.4e-2*164400000.*0.0081*chain_QCDMu30to50->GetEntries(cut)/chain_QCDMu30to50->GetEntries();
    float rateQCDMu50to80 = 1.4e-2*21930000.*0.01511*chain_QCDMu50to80->GetEntries(cut)/chain_QCDMu50to80->GetEntries();
    float rateQCDMu80to120 = 1.4e-2*3000000.*0.0244*chain_QCDMu80to120->GetEntries(cut)/chain_QCDMu80to120->GetEntries();

    float errorDY = 1.4e-2*2008.4*sqrt(chain_DY->GetEntries(cut))/chain_DY->GetEntries();
    float errorW = 1.4e-2*16100.*sqrt(chain_WMuNu->GetEntries(cut))/chain_WMuNu->GetEntries();
    float errorQCDMu20to30 = 1.4e-2*675300000.*0.004*sqrt(chain_QCDMu20to30->GetEntries(cut))/chain_QCDMu20to30->GetEntries();
    float errorQCDMu30to50 = 1.4e-2*164400000.*0.0081*sqrt(chain_QCDMu30to50->GetEntries(cut))/chain_QCDMu30to50->GetEntries();
    float errorQCDMu50to80 = 1.4e-2*21930000.*0.01511*sqrt(chain_QCDMu50to80->GetEntries(cut))/chain_QCDMu50to80->GetEntries();
    float errorQCDMu80to120 = 1.4e-2*3000000.*0.0244*sqrt(chain_QCDMu80to120->GetEntries(cut))/chain_QCDMu80to120->GetEntries();

    
    cout << "rateDY=" << rateDY << endl;
    cout << "rateW=" << rateW << endl;
    cout << "rateQCDMu20to30=" << rateQCDMu20to30 << endl;
    cout << "rateQCDMu30to50=" << rateQCDMu30to50 << endl;
    cout << "rateQCDMu50to80=" << rateQCDMu50to80 << endl;
    cout << "rateQCDMu80to120=" << rateQCDMu80to120 << endl;
    float sumRate = rateDY + rateW + rateQCDMu20to30 + rateQCDMu30to50 + rateQCDMu50to80 + rateQCDMu80to120;
    cout << "sum= " << sumRate << endl;
    
    float error = errorDY + errorW + errorQCDMu20to30 + errorQCDMu30to50 + errorQCDMu50to80 + errorQCDMu80to120;
    cout << "error=" << error << endl;
    
    purity = (rateDY + rateW)/sumRate;
    
    
    rateError theRateAndError;
    theRateAndError.rate = sumRate;
    theRateAndError.error = error;
    theRateAndError.purity = purity;
    
    
    cout << "rate=" << sumRate << " error=" << error << endl;
    
    return theRateAndError;
}



void computeRate(){
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    chain_DY->Add("theOutFile_DY.root");
    chain_WMuNu->Add("theOutFile_WMuNu.root");
    chain_QCDMu20to30->Add("theOutFile_QCDMu20to30.root");
    chain_QCDMu30to50->Add("theOutFile_QCDMu30to50.root");
    chain_QCDMu50to80->Add("theOutFile_QCDMu50to80.root");
    chain_QCDMu80to120->Add("theOutFile_QCDMu80to120.root");
  
    //giveTheRate("passIsoMu24==1");

    rateError theRateAndTheError = giveTheRate("passIsoMu24==1&&passMu24Pt>24");
    
  /*  float errors[20];
    float rates[20];
    float purities[20];
    float x[20];
    float xError[20];
    
    for (int i = 20 ; i < 40 ; i++){
        TString theCut = Form("passIsoMu24==1&&passMu24Pt>%i",i);
        rateError errorRateInBin = giveTheRate(theCut);
        rates[i-20] = errorRateInBin.rate;
        errors[i-20] = errorRateInBin.error;
        purities[i-20] = errorRateInBin.purity;
        x[i-20] = i;
        xError[i-20] = 0;
    }
    
    TCanvas *c0 = new TCanvas("c0","coucou",600,600);
    c0->SetFillColor(0);
    /*TGraphErrors *graph = new TGraphErrors(20,x,rates,xError,errors);
    graph->GetXaxis()->SetTitle("IsoMuX_eta2p1 threshold (GeV)");
    graph->GetYaxis()->SetTitle("rate (Hz)");
    graph->Draw("AC");*/
 /*   TGraph *graph = new TGraph(20,x,purities);
    graph->GetXaxis()->SetTitle("IsoMuX_eta2p1 threshold (GeV)");
    graph->GetYaxis()->SetTitle("purity");
    graph->Draw("AC");
    c0->Print("PurityVsPt.png");
   */ 
  /*  giveTheRate("passIsoMu24==1&&passMu24Pt>24&&abs(passMu24Eta)<2.1");
    cout << "hello" << endl;
    giveTheRate("passMu17Mu8==1");
    giveTheRate("passMu17Mu8LeadPt>17&&passMu17Mu8TrailPt>8");
    giveTheRate("passMu17Mu8Iso==1");*/
    giveTheRate("(passMu17Mu8SameSign==1&&passMu17Mu8Iso==0)");
    giveTheRate("passMu17Mu8SameSign==1");
    giveTheRate("passMu17Mu8==1");
    giveTheRate("passMu17Mu8Iso==1");

}
