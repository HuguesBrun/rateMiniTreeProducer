#define rateSelector_cxx
// The class definition in rateSelector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("rateSelector.C")
// root> T->Process("rateSelector.C","some options")
// root> T->Process("rateSelector.C+")
//

#include "rateSelector.h"
#include <TH2.h>
#include <TStyle.h>


void rateSelector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void rateSelector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t rateSelector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either rateSelector::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
    fChain->GetEntry(entry);
    if (entry%1000==0) cout << "i=" << entry << endl;
    
    
    
    passIsoMu24 =  T_Event_pathsFired->at(5);
    
    thePtEta ptETaMu24 = MatchWithTriggerPt(0);
    passMu24Pt = ptETaMu24.pt;
    passMu24Eta = ptETaMu24.eta;
    
    
    thePtEta ptETaIsoMu24 = MatchWithTriggerPt(1);
    passIsoMu24Pt = ptETaIsoMu24.pt;
    passIsoMu24Eta = ptETaIsoMu24.eta;
    
    passMu17Mu8 =  T_Event_pathsFired->at(0);
    thePtEtaDouble Mu17Mu8 = MatchWithTriggerPt(5,5);
    passMu17Mu8LeadPt = Mu17Mu8.Leadpt;
    passMu17Mu8LeadEta = Mu17Mu8.Leadeta;
    passMu17Mu8TrailPt = Mu17Mu8.Trailpt;
    passMu17Mu8TrailEta = Mu17Mu8.Traileta;
    
    passMu17TkMu8 =  T_Event_pathsFired->at(1);
    thePtEtaDouble Mu17TkMu8 = MatchWithTriggerPt(8,8);
    passMu17TkMu8LeadPt = Mu17TkMu8.Leadpt;
    passMu17TkMu8LeadEta = Mu17TkMu8.Leadeta;
    passMu17TkMu8TrailPt = Mu17TkMu8.Trailpt;
    passMu17TkMu8TrailEta = Mu17TkMu8.Traileta;
    
    passMu17Mu8Iso =  T_Event_pathsFired->at(2);
    thePtEtaDouble Mu17Mu8Iso = MatchWithTriggerPt(9,9);
    passMu17Mu8IsoLeadPt = Mu17Mu8Iso.Leadpt;
    passMu17Mu8IsoLeadEta = Mu17Mu8Iso.Leadeta;
    passMu17Mu8IsoTrailPt = Mu17Mu8Iso.Trailpt;
    passMu17Mu8IsoTrailEta = Mu17Mu8Iso.Traileta;
    
    passMu17TkMu8Iso =  T_Event_pathsFired->at(3);
    thePtEtaDouble Mu17TkMu8Iso = MatchWithTriggerPt(10,10);
    passMu17TkMu8IsoLeadPt = Mu17TkMu8Iso.Leadpt;
    passMu17TkMu8IsoLeadEta = Mu17TkMu8Iso.Leadeta;
    passMu17TkMu8IsoTrailPt = Mu17TkMu8Iso.Trailpt;
    passMu17TkMu8IsoTrailEta = Mu17TkMu8Iso.Traileta;
    
    passMu17Mu8SameSign =  T_Event_pathsFired->at(7);
    thePtEtaDouble Mu17Mu8SameSign = MatchWithTriggerPt(11,11);
    passMu17Mu8SameSignLeadPt = Mu17Mu8SameSign.Leadpt;
    passMu17Mu8SameSignLeadEta = Mu17Mu8SameSign.Leadeta;
    passMu17Mu8SameSignTrailPt = Mu17Mu8SameSign.Trailpt;
    passMu17Mu8SameSignTrailEta = Mu17Mu8SameSign.Traileta;
    
    myTree->Fill();
    
  // if (entry>100) Abort("the end !!!");
   return kTRUE;
}

void rateSelector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void rateSelector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
    
   myFile->Write();
   myFile->Close();
//
}

thePtEta rateSelector::MatchWithTriggerPt(int theIte){
    int nbTriggerLeg = T_Trig_Pt->size();
    //cout << "nbTriggerLeg=" << nbTriggerLeg << endl;
    thePtEta ptEtaOfTheLeg;
    ptEtaOfTheLeg.pt = 0;
    ptEtaOfTheLeg.eta = -10;
    float theMaxPt = 0;
    int theMaxPtIte = -1;
    for (int i = 0 ; i < nbTriggerLeg ; i++){
        if (T_Trig_Leg->at(i)==theIte) {
            if (T_Trig_Pt->at(i) > theMaxPt) {
                theMaxPt = T_Trig_Pt->at(i);
                theMaxPtIte = i;
            }
        }
    }
    
    if (theMaxPtIte > -1){
        ptEtaOfTheLeg.pt = T_Trig_Pt->at(theMaxPtIte);
        ptEtaOfTheLeg.eta = T_Trig_Eta->at(theMaxPtIte);
    }
    
    return ptEtaOfTheLeg;
}

thePtEtaDouble rateSelector::MatchWithTriggerPt(int theIte, int theIte2){
    int nbTriggerLeg = T_Trig_Pt->size();
    //cout << "nbTriggerLeg=" << nbTriggerLeg << endl;
    thePtEtaDouble ptEtaOfTheLeg;
    ptEtaOfTheLeg.Leadpt = 0;
    ptEtaOfTheLeg.Leadeta = -10;
    ptEtaOfTheLeg.Trailpt = 0;
    ptEtaOfTheLeg.Traileta = -10;
    float theMaxPt = 0;
    int theMaxPtIte = -1;
    int theMaxPtIteSec = -1;
    for (int i = 0 ; i < nbTriggerLeg ; i++){
        if (T_Trig_Leg->at(i)==theIte) {
            if (T_Trig_Pt->at(i) > theMaxPt) {
                theMaxPt = T_Trig_Pt->at(i);
                theMaxPtIte = i;
            }
        }
    }
    
    if (theMaxPtIte > -1){
        theMaxPt = 0;
        for (int i = 0 ; i < nbTriggerLeg ; i++){
            if (T_Trig_Pt->at(i) == T_Trig_Pt->at(theMaxPtIte)) continue;
            if (T_Trig_Leg->at(i)==theIte2) {
                if (T_Trig_Pt->at(i) > theMaxPt) {
                    theMaxPt = T_Trig_Pt->at(i);
                    theMaxPtIteSec = i;
                }
            }
        }
        if (theMaxPtIteSec > -1){

           ptEtaOfTheLeg.Leadpt = T_Trig_Pt->at(theMaxPtIte);
           ptEtaOfTheLeg.Leadeta = T_Trig_Eta->at(theMaxPtIte);
           ptEtaOfTheLeg.Trailpt = T_Trig_Pt->at(theMaxPtIteSec);
           ptEtaOfTheLeg.Traileta = T_Trig_Eta->at(theMaxPtIteSec);
            
         /*   cout << "ptEtaOfTheLeg.Leadpt = " << ptEtaOfTheLeg.Leadpt << endl;
            cout << "ptEtaOfTheLeg.Leadeta = " << ptEtaOfTheLeg.Leadeta << endl;
            
            cout << "ptEtaOfTheLeg.Trailpt = " << ptEtaOfTheLeg.Trailpt << endl;
            cout << "ptEtaOfTheLeg.Traileta = " << ptEtaOfTheLeg.Traileta << endl;*/
        }
    }
    
    
    return ptEtaOfTheLeg;
}
