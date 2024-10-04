
#include <iostream>
#include "EventLooper.hh"

int main() {


    std::cout<<"  [ Log ] : This is the program for the [ ParticleLab_Analyzer ]"<<std::endl;

    EventLooper *evtLooper = new EventLooper();

    // Run the Loop function to process the data
    std::cout<<"  [ Log ] : Now We will open the .root files and looping all events"<<std::endl;
    evtLooper->Loop();

    std::cout<<"  [ Log ] : All events are searched!!"<<std::endl;
    std::cout<<"  [ Log ] : Let's close the --> event looper <--"<<std::endl;

    delete evtLooper;

    std::cout<<"\n  [ Log ] : All Jobs are done"<<std::endl;

    return 0;

}
