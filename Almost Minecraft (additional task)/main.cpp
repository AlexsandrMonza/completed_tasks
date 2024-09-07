#include <iostream>

int main ()
{
    int area [5][5];
    int control=0;
    int floor=0;

//Заполняем площадь этажами (H высоты)
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            std::cin>>control;

//Контролируем высоту (макс высота 10)
            while (control>10){
                std::cout<<"Error height.\n";
                std::cin>>control;
            }

            area[i][j]=control;
        }
    }

//Срез по этажу
    std::cout<<"At what level do we make a slice?\n";
    std::cin>>floor;

    for(int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            area[i][j]-=floor;
            if (area[i][j]==0){
                area[i][j]=true;
            }
            if (area[i][j]<0){
                area[i][j]=false;
            }
            if (area[i][j]>0){
                area[i][j]=true;
            }
        }
    }

//вывод заполненого массива
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            std::cout<<area[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}