#include "disk.h"

void save (int ram[]){
    std::ofstream Data ("..\\Data.txt");

    for (int i=0;i<8;i++){
        Data<<ram[i]<<"\n";
    }
    Data.close();
}

void load (int ram[]){
    std::ifstream Data ("..\\Data.txt");

    for(int i=0;i<8;i++) {
        Data >> ram[i];
    }
}