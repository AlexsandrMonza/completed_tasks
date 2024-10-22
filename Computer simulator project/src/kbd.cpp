#include "cpu.h"

void input (int kbd[]){
    std::cout<<"Input 8 numbers:\n";
    for(int i=0;i<8;i++){
        std::cout<<i+1<<": ";
        std::cin>>kbd[i];
    }
}