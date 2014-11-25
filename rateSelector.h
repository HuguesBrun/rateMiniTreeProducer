//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Oct 23 17:09:19 2014 by ROOT version 6.00/00
// from TTree eventsTree/
// found on file: rate_DY.root
//////////////////////////////////////////////////////////

#ifndef rateSelector_h
#define rateSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include "vector"


struct thePtEta{
    float pt;
    float eta;
};

struct thePtEtaDouble{
    float Leadpt;
    float Leadeta;
    float Trailpt;
    float Traileta;
};

class rateSelector : public TSelector {
public :
    
    
    TFile *myFile;
    TTree *myTree;
    
    
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
    
    
    int passIsoMu24;
    float passMu24Pt;
    float passMu24Eta;
    
    float passIsoMu24Pt;
    float passIsoMu24Eta;
    
    
    int passMu17Mu8;
    float passMu17Mu8LeadPt;
    float passMu17Mu8LeadEta;
    float passMu17Mu8TrailPt;
    float passMu17Mu8TrailEta;
    
    int passMu17TkMu8;
    float passMu17TkMu8LeadPt;
    float passMu17TkMu8LeadEta;
    float passMu17TkMu8TrailPt;
    float passMu17TkMu8TrailEta;
    
    int passMu17Mu8Iso;
    float passMu17Mu8IsoLeadPt;
    float passMu17Mu8IsoLeadEta;
    float passMu17Mu8IsoTrailPt;
    float passMu17Mu8IsoTrailEta;
    
    int passMu17TkMu8Iso;
    float passMu17TkMu8IsoLeadPt;
    float passMu17TkMu8IsoLeadEta;
    float passMu17TkMu8IsoTrailPt;
    float passMu17TkMu8IsoTrailEta;
    
    int passMu17Mu8SameSign;
    float passMu17Mu8SameSignLeadPt;
    float passMu17Mu8SameSignLeadEta;
    float passMu17Mu8SameSignTrailPt;
    float passMu17Mu8SameSignTrailEta;

   // Declaration of leaf types
   Int_t           T_Event_RunNumber;
   Int_t           T_Event_EventNumber;
   Int_t           T_Event_LuminosityBlock;
   Int_t           T_Event_nPU;
   Float_t         T_Event_nTruePU;
   Int_t           T_Event_nPUm;
   Int_t           T_Event_nPUp;
   Float_t         T_Event_AveNTruePU;
   vector<int>     *T_Event_pathsFired;
   vector<float>   *T_Trig_Eta;
   vector<float>   *T_Trig_Pt;
   vector<float>   *T_Trig_Phi;
   vector<int>     *T_Trig_Leg;
   vector<float>   *T_Trig_Value;
   vector<float>   *T_Trig_Value2;
   vector<float>   *T_Gen_Eta;
   vector<float>   *T_Gen_Phi;
   vector<float>   *T_Gen_Pt;
   vector<int>     *T_Gen_pdgID;
   vector<int>     *T_Gen_MotherID;
   vector<int>     *T_Gen_FromW;
   vector<int>     *T_Gen_FromTau;

   // List of branches
   TBranch        *b_T_Event_RunNumber;   //!
   TBranch        *b_T_Event_EventNumber;   //!
   TBranch        *b_T_Event_LuminosityBlock;   //!
   TBranch        *b_T_Event_nPU;   //!
   TBranch        *b_T_Event_nTruePU;   //!
   TBranch        *b_T_Event_nPUm;   //!
   TBranch        *b_T_Event_nPUp;   //!
   TBranch        *b_T_Event_AveNTruePU;   //!
   TBranch        *b_T_Event_pathsFired;   //!
   TBranch        *b_T_Trig_Eta;   //!
   TBranch        *b_T_Trig_Pt;   //!
   TBranch        *b_T_Trig_Phi;   //!
   TBranch        *b_T_Trig_Leg;   //!
   TBranch        *b_T_Trig_Value;   //!
   TBranch        *b_T_Trig_Value2;   //!
   TBranch        *b_T_Gen_Eta;   //!
   TBranch        *b_T_Gen_Phi;   //!
   TBranch        *b_T_Gen_Pt;   //!
   TBranch        *b_T_Gen_pdgID;   //!
   TBranch        *b_T_Gen_MotherID;   //!
   TBranch        *b_T_Gen_FromW;   //!
   TBranch        *b_T_Gen_FromTau;   //!

   rateSelector(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~rateSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();
   virtual thePtEta MatchWithTriggerPt(int theIte);
    virtual thePtEtaDouble  MatchWithTriggerPt(int theIte, int theIte2);



   ClassDef(rateSelector,0);
};

#endif

#ifdef rateSelector_cxx
void rateSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).
    
    myFile = new TFile("theOutFile.root","RECREATE");
    myTree = new TTree("myTree","");
    
    myTree->Branch("passIsoMu24",&passIsoMu24,"passIsoMu24/I");
    
    myTree->Branch("passMu24Pt",&passMu24Pt,"passMu24Pt/F");
    myTree->Branch("passMu24Eta",&passMu24Eta,"passMu24Eta/F");

    myTree->Branch("passIsoMu24Pt",&passIsoMu24Pt,"passMu24Pt/F");
    myTree->Branch("passIsoMu24Eta",&passIsoMu24Eta,"passIsoMu24Eta/F");
    
    myTree->Branch("passMu17Mu8",&passMu17Mu8,"passMu17Mu8/I");
    myTree->Branch("passMu17Mu8LeadPt",&passMu17Mu8LeadPt,"passMu17Mu8LeadPt/F");
    myTree->Branch("passMu17Mu8LeadEta",&passMu17Mu8LeadEta,"passMu17Mu8LeadEta/F");
    myTree->Branch("passMu17Mu8TrailPt",&passMu17Mu8TrailPt,"passMu17Mu8TrailPt/F");
    myTree->Branch("passMu17Mu8TrailEta",&passMu17Mu8TrailEta,"passMu17Mu8TrailEta/F");

    myTree->Branch("passMu17TkMu8",&passMu17TkMu8,"passMu17TkMu8/I");
    myTree->Branch("passMu17TkMu8LeadPt",&passMu17TkMu8LeadPt,"passMu17TkMu8LeadPt/F");
    myTree->Branch("passMu17TkMu8LeadEta",&passMu17TkMu8LeadEta,"passMu17TkMu8LeadEta/F");
    myTree->Branch("passMu17TkMu8TrailPt",&passMu17TkMu8TrailPt,"passMu17TkMu8TrailPt/F");
    myTree->Branch("passMu17TkMu8TrailEta",&passMu17TkMu8TrailEta,"passMu17TkMu8TrailEta/F");


    myTree->Branch("passMu17Mu8Iso",&passMu17Mu8Iso,"passMu17Mu8Iso/I");
    myTree->Branch("passMu17Mu8IsoLeadPt",&passMu17Mu8IsoLeadPt,"passMu17Mu8IsoLeadPt/F");
    myTree->Branch("passMu17Mu8IsoLeadEta",&passMu17Mu8IsoLeadEta,"passMu17Mu8IsoLeadEta/F");
    myTree->Branch("passMu17Mu8IsoTrailPt",&passMu17Mu8IsoTrailPt,"passMu17Mu8IsoTrailPt/F");
    myTree->Branch("passMu17Mu8IsoTrailEta",&passMu17Mu8IsoTrailEta,"passMu17Mu8IsoTrailEta/F");

    
    myTree->Branch("passMu17TkMu8Iso",&passMu17TkMu8Iso,"passMu17TkMu8Iso/I");
    myTree->Branch("passMu17TkMu8IsoLeadPt",&passMu17TkMu8IsoLeadPt,"passMu17TkMu8IsoLeadPt/F");
    myTree->Branch("passMu17TkMu8IsoLeadEta",&passMu17TkMu8IsoLeadEta,"passMu17TkMu8IsoLeadEta/F");
    myTree->Branch("passMu17TkMu8IsoTrailPt",&passMu17TkMu8IsoTrailPt,"passMu17TkMu8IsoTrailPt/F");
    myTree->Branch("passMu17TkMu8IsoTrailEta",&passMu17TkMu8IsoTrailEta,"passMu17TkMu8IsoTrailEta/F");

    myTree->Branch("passMu17TkMu8Iso",&passMu17TkMu8Iso,"passMu17TkMu8Iso/I");
    myTree->Branch("passMu17TkMu8IsoLeadPt",&passMu17TkMu8IsoLeadPt,"passMu17TkMu8IsoLeadPt/F");
    myTree->Branch("passMu17TkMu8IsoLeadEta",&passMu17TkMu8IsoLeadEta,"passMu17TkMu8IsoLeadEta/F");
    myTree->Branch("passMu17TkMu8IsoTrailPt",&passMu17TkMu8IsoTrailPt,"passMu17TkMu8IsoTrailPt/F");
    myTree->Branch("passMu17TkMu8IsoTrailEta",&passMu17TkMu8IsoTrailEta,"passMu17TkMu8IsoTrailEta/F");

    myTree->Branch("passMu17Mu8SameSign",&passMu17Mu8SameSign,"passMu17Mu8SameSign/I");
    myTree->Branch("passMu17Mu8SameSignLeadPt",&passMu17Mu8SameSignLeadPt,"passMu17Mu8SameSignLeadPt/F");
    myTree->Branch("passMu17Mu8SameSignLeadEta",&passMu17Mu8SameSignLeadEta,"passMu17Mu8SameSignLeadEta/F");
    myTree->Branch("passMu17Mu8SameSignTrailPt",&passMu17Mu8SameSignTrailPt,"passMu17Mu8SameSignTrailPt/F");
    myTree->Branch("passMu17Mu8SameSignTrailEta",&passMu17Mu8SameSignTrailEta,"passMu17Mu8SameSignTrailEta/F");

    
    
   // Set object pointer
   T_Event_pathsFired = 0;
   T_Trig_Eta = 0;
   T_Trig_Pt = 0;
   T_Trig_Phi = 0;
   T_Trig_Leg = 0;
   T_Trig_Value = 0;
   T_Trig_Value2 = 0;
   T_Gen_Eta = 0;
   T_Gen_Phi = 0;
   T_Gen_Pt = 0;
   T_Gen_pdgID = 0;
   T_Gen_MotherID = 0;
   T_Gen_FromW = 0;
   T_Gen_FromTau = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("T_Event_RunNumber", &T_Event_RunNumber, &b_T_Event_RunNumber);
   fChain->SetBranchAddress("T_Event_EventNumber", &T_Event_EventNumber, &b_T_Event_EventNumber);
   fChain->SetBranchAddress("T_Event_LuminosityBlock", &T_Event_LuminosityBlock, &b_T_Event_LuminosityBlock);
   fChain->SetBranchAddress("T_Event_nPU", &T_Event_nPU, &b_T_Event_nPU);
   fChain->SetBranchAddress("T_Event_nTruePU", &T_Event_nTruePU, &b_T_Event_nTruePU);
   fChain->SetBranchAddress("T_Event_nPUm", &T_Event_nPUm, &b_T_Event_nPUm);
   fChain->SetBranchAddress("T_Event_nPUp", &T_Event_nPUp, &b_T_Event_nPUp);
   fChain->SetBranchAddress("T_Event_AveNTruePU", &T_Event_AveNTruePU, &b_T_Event_AveNTruePU);
   fChain->SetBranchAddress("T_Event_pathsFired", &T_Event_pathsFired, &b_T_Event_pathsFired);
   fChain->SetBranchAddress("T_Trig_Eta", &T_Trig_Eta, &b_T_Trig_Eta);
   fChain->SetBranchAddress("T_Trig_Pt", &T_Trig_Pt, &b_T_Trig_Pt);
   fChain->SetBranchAddress("T_Trig_Phi", &T_Trig_Phi, &b_T_Trig_Phi);
   fChain->SetBranchAddress("T_Trig_Leg", &T_Trig_Leg, &b_T_Trig_Leg);
   fChain->SetBranchAddress("T_Trig_Value", &T_Trig_Value, &b_T_Trig_Value);
   fChain->SetBranchAddress("T_Trig_Value2", &T_Trig_Value2, &b_T_Trig_Value2);
   fChain->SetBranchAddress("T_Gen_Eta", &T_Gen_Eta, &b_T_Gen_Eta);
   fChain->SetBranchAddress("T_Gen_Phi", &T_Gen_Phi, &b_T_Gen_Phi);
   fChain->SetBranchAddress("T_Gen_Pt", &T_Gen_Pt, &b_T_Gen_Pt);
   fChain->SetBranchAddress("T_Gen_pdgID", &T_Gen_pdgID, &b_T_Gen_pdgID);
   fChain->SetBranchAddress("T_Gen_MotherID", &T_Gen_MotherID, &b_T_Gen_MotherID);
   fChain->SetBranchAddress("T_Gen_FromW", &T_Gen_FromW, &b_T_Gen_FromW);
   fChain->SetBranchAddress("T_Gen_FromTau", &T_Gen_FromTau, &b_T_Gen_FromTau);
}

Bool_t rateSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef rateSelector_cxx
