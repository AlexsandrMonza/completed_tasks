#include <iostream>
#include <string>

int main()
{
    std::string family [10];
    int number=0;

    for (int i = 0; i < 10; i++) {
        std::cin >> family[i];
    }

    while(number <= 10) {
        std::cout << "Number?\n";
        std::cin >> number;
        while ( number > 10 ) {
            std::cout << "Incorrect number!\n";
            std::cout << "Number?\n";
            std::cin >> number;
        }
        std::cout << "Family: " << family[number - 1] << "\n";
    }
}
