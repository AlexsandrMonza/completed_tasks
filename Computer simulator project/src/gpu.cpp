#include "cpu.h"

void display (int gpu[]){
    for(int i=0;i<8;i++) {
        std::cout << i + 1 <<": "<<gpu[i]<<"\n";
    }
}