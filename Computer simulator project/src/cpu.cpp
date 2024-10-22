#include "cpu.h"

void computer (int cpu[]){
    int a=0;
    for(int i=0;i<8;i++){
        a+=cpu[i];
    }
    std::cout<<a<<"\n";
}