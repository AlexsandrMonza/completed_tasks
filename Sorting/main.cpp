#include <iostream>

int main () {
    float number[15];

    for ( int i = 0; i < 15; i++ ) {
        std::cin >> number[i];
    }

    for ( int i = 0; i < 15; i++ ) {
        float max = 0;
        for ( int j = i; j < 15; j++ ) {
            if ( number[j] > max ) {
                float size = 0;
                max = number[j];
                size = number[i];
                number[i] = max;
                number[j] = size;
            }
        }
    }

    for ( int i = 0; i < 15; i++ ) {
        std::cout << number[i] << " ";
    }
}
