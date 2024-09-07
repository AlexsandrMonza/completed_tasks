#include <iostream>
#include <vector>

int main()
{
    int I = 0;
    int P = 0;
    float num;
    float result = 0.0f;

    std::cout << "Input items:";
    std::cin >> I;

    std::cout << "Input price:";
    std::cin >> P;

    std::vector <float> items(I);
    std::vector <float> price(P);

    for (int i = 0; i < I; i++) {
        std::cout << "Input items all:";
        std::cin >> items[i];
    }

    for (int i = 0; i < P; i++) {
        std::cout << "Input price all:";
        std::cin >> price[i];
    }

    for (int i = 0; i < items.size(); i++) {
        num = items[i];
        result += price[num];
    }

    std::cout << "Result: " << result;
}