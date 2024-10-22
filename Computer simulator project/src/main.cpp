#include "kbd.h"
#include "ram.h"
#include "gpu.h"
#include "disk.h"
#include "cpu.h"


int main () {

    std::string action;

    while (action != "exit") {
        std::cout << "Enter action (input, display, sum, save, load and exit)\n";
        std::cin >> action;

        if (action == "input") {
            input (numbersKbd);
            write (numbersKbd,numbersRam);
        }

        if (action == "display") {
            read (numbersRam, numbersGpu);
            display (numbersGpu);
        }

        if (action == "sum") {
            computer (numbersRam);
        }

        if (action == "save") {
            save (numbersRam);
        }

        if (action == "load") {
            load (numbersRam);
        }

        if (action=="exit"){
            break;
        }
    }
}