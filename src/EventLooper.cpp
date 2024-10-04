#define EventLooper_cxx
#include "EventLooper.hh"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void EventLooper::Loop()
{

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   // Create histograms for each channel
   TH1D *h_ch0  = new TH1D("h_ch0",  "Channel 0", 200, 0, 4096);
   TH1D *h_ch1  = new TH1D("h_ch1",  "Channel 1", 200, 0, 4096);
   TH1D *h_ch2  = new TH1D("h_ch2",  "Channel 2", 200, 0, 4096);
   TH1D *h_ch3  = new TH1D("h_ch3",  "Channel 3", 200, 0, 4096);
   TH1D *h_ch4  = new TH1D("h_ch4",  "Channel 4", 200, 0, 4096);
   TH1D *h_ch5  = new TH1D("h_ch5",  "Channel 5", 200, 0, 4096);
   TH1D *h_ch6  = new TH1D("h_ch6",  "Channel 6", 200, 0, 4096);
   TH1D *h_ch7  = new TH1D("h_ch7",  "Channel 7", 200, 0, 4096);
   TH1D *h_ch8  = new TH1D("h_ch8",  "Channel 8", 200, 0, 4096);
   TH1D *h_ch9  = new TH1D("h_ch9",  "Channel 9", 200, 0, 4096);
   TH1D *h_ch10 = new TH1D("h_ch10", "Channel 10", 200, 0, 4096);
   TH1D *h_ch11 = new TH1D("h_ch11", "Channel 11", 200, 0, 4096);
   TH1D *h_ch12 = new TH1D("h_ch12", "Channel 12", 200, 0, 4096);
   TH1D *h_ch13 = new TH1D("h_ch13", "Channel 13", 200, 0, 4096);
   TH1D *h_ch14 = new TH1D("h_ch14", "Channel 14", 200, 0, 4096);
   TH1D *h_ch15 = new TH1D("h_ch15", "Channel 15", 200, 0, 4096);

 
   // Create output ROOT file
   TString outputFileName = "output.root";
   TFile *outputFile = new TFile(outputFileName, "RECREATE");


   // Loop for n-tuple's all events
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {

       Long64_t ientry = LoadTree(jentry);
       if (ientry < 0) break;
       nb = fChain->GetEntry(jentry);   nbytes += nb;

       // if (Cut(ientry) < 0) continue;

       // Fill histograms with channel data
       h_ch0->Fill(q_ch0);
       h_ch1->Fill(q_ch1);
       h_ch2->Fill(q_ch2);
       h_ch3->Fill(q_ch3);
       h_ch4->Fill(q_ch4);
       h_ch5->Fill(q_ch5);
       h_ch6->Fill(q_ch6);
       h_ch7->Fill(q_ch7);
       h_ch8->Fill(q_ch8);
       h_ch9->Fill(q_ch9);
       h_ch10->Fill(q_ch10);
       h_ch11->Fill(q_ch11);
       h_ch12->Fill(q_ch12);
       h_ch13->Fill(q_ch13);
       h_ch14->Fill(q_ch14);
       h_ch15->Fill(q_ch15);
   }

   // Write histograms to the output ROOT file
   outputFile->cd(); // Change to output file directory
   h_ch0->Write();
   h_ch1->Write();
   h_ch2->Write();
   h_ch3->Write();
   h_ch4->Write();
   h_ch5->Write();
   h_ch6->Write();
   h_ch7->Write();
   h_ch8->Write();
   h_ch9->Write();
   h_ch10->Write();
   h_ch11->Write();
   h_ch12->Write();
   h_ch13->Write();
   h_ch14->Write();
   h_ch15->Write();

   // Close the output file
   outputFile->Close();

}
