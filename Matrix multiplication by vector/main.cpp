#include <iostream>

int main ()
{
    float matrix [4][4];
    float vector [4];
    float newVector [4];
    float num=0;

//Записываем матрицу
    std::cout<<"Writing down the matrix.\n";
    for (int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            std::cin>>matrix[i][j];
        }
    }

//Записываем вектор
    std::cout<<"Writing a vector.\n";
    for (int i=0;i<4;i++){
            std::cin>>vector[i];
    }

//Перемножаем матрицу на вектор
    for(int i=0;i<4;i++){
        num=0;
        for (int j=0;j<4;j++){
           num+=matrix[i][j]*vector[j];
        }
        newVector[i]=num;
    }

    //Вывод нового вектора (результат перемножения матрицы на вектор)
    for (int i=0;i<4;i++){
        std::cout<<newVector [i]<<"\n";
    }
}