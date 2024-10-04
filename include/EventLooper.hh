//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct  4 16:56:46 2024 by ROOT version 6.32.02
// from TTree T/data from caen QDC792n 
// found on file: rn4_evts1024_v792n_List.root
//////////////////////////////////////////////////////////

#ifndef EventLooper_hh
#define EventLooper_hh

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class EventLooper {

    public :
       TTree          *fChain;   //!pointer to the analyzed TTree or TChain
       Int_t           fCurrent; //!current Tree number in a TChain
    
    // Fixed size dimensions of array or collections stored in the TTree if any.
    
       // Declaration of leaf types
       Int_t           q_EvtNum;
       Int_t           q_ch0;
       Int_t           q_ch1;
       Int_t           q_ch2;
       Int_t           q_ch3;
       Int_t           q_ch4;
       Int_t           q_ch5;
       Int_t           q_ch6;
       Int_t           q_ch7;
       Int_t           q_ch8;
       Int_t           q_ch9;
       Int_t           q_ch10;
       Int_t           q_ch11;
       Int_t           q_ch12;
       Int_t           q_ch13;
       Int_t           q_ch14;
       Int_t           q_ch15;
    
       // List of branches
       TBranch        *b_q;   //!
    
       EventLooper(TTree *tree=0);
       virtual ~EventLooper();
       virtual Int_t    Cut(Long64_t entry);
       virtual Int_t    GetEntry(Long64_t entry);
       virtual Long64_t LoadTree(Long64_t entry);
       virtual void     Init(TTree *tree);
       virtual void     Loop();
       virtual bool     Notify();
       virtual void     Show(Long64_t entry = -1);
    };  
    #endif
    
    #ifdef EventLooper_cxx
    EventLooper::EventLooper(TTree *tree) : fChain(0) 
    {
    // if parameter tree is not specified (or zero), connect the file
    // used to generate this class and read the Tree.

       TString ntupleDir  = "../ntuple/";
       TString ntupleName = "rn4_evts1024_v792n_List.root";
       TString ntuplePath = ntupleDir + ntupleName;

       if (tree == 0) {
          TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject( ntuplePath );
          if (!f || !f->IsOpen()) {
             f = new TFile( ntuplePath );
          }
          f->GetObject("T",tree);
    
       }
       Init(tree);
    }
    
    EventLooper::~EventLooper()
    {
       if (!fChain) return;
       delete fChain->GetCurrentFile();
    }
    
    Int_t EventLooper::GetEntry(Long64_t entry)
    {
    // Read contents of entry.
       if (!fChain) return 0;
       return fChain->GetEntry(entry);
    }
    Long64_t EventLooper::LoadTree(Long64_t entry)
    {
    // Set the environment to read one entry
       if (!fChain) return -5;
       Long64_t centry = fChain->LoadTree(entry);
       if (centry < 0) return centry;
       if (fChain->GetTreeNumber() != fCurrent) {
          fCurrent = fChain->GetTreeNumber();
          Notify();
       }
       return centry;
    }
    
    void EventLooper::Init(TTree *tree)
    {
       // The Init() function is called when the selector needs to initialize
       // a new tree or chain. Typically here the branch addresses and branch
       // pointers of the tree will be set.
       // It is normally not necessary to make changes to the generated
       // code, but the routine can be extended by the user if needed.
       // Init() will be called many times when running on PROOF
       // (once per file to be processed).
    
       // Set branch addresses and branch pointers
       if (!tree) return;
       fChain = tree;
       fCurrent = -1;
       fChain->SetMakeClass(1);
    
       fChain->SetBranchAddress("q", &q_EvtNum, &b_q);
       Notify();
    }
    
    bool EventLooper::Notify()
    {
       // The Notify() function is called when a new file is opened. This
       // can be either for a new TTree in a TChain or when when a new TTree
       // is started when using PROOF. It is normally not necessary to make changes
       // to the generated code, but the routine can be extended by the
       // user if needed. The return value is currently not used.
    
       return true;
    }
    
    void EventLooper::Show(Long64_t entry)
    {
    // Print contents of entry.
    // If entry is not specified, print current entry
       if (!fChain) return;
       fChain->Show(entry);
    }
    Int_t EventLooper::Cut(Long64_t entry)
    {
    // This function may be called from Loop.
    // returns  1 if entry is accepted.
    // returns -1 otherwise.
       return 1;
    }

#endif // #ifdef EventLooper_cxx
