#include <iostream>

//Инициализируем массив true
void newMassive (bool massive[][12]) {
    for ( int i = 0; i < 12; i++ ) {
        for ( int j = 0; j < 12; j++ ) {
            massive[i][j] = true;
        }
    }
}

//Лопаем пузыри
void bursting (bool massive[][12]){
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    std::cout<<"Input coordinates\n";
    std::cin>>a>>b;
    std::cin>>c>>d;
    while (a>11||b>11||c>11||d>11){
        std::cout<<"Coordinates error!\n";
        std::cin>>a>>b;
        std::cin>>c>>d;
    }
    for (int i=a;i<c+1;i++){
        for(int j=b;j<d+1;j++){
            massive [i][j]= false;
        }
    }
}

//Результат после лопанья
void result (bool massive[][12]){
    for (int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            if (massive[i][j]){
                std::cout<<"O";
            }
            else {
                std::cout<<"X";
            }
        }
        std::cout<<"\n";
    }
}

//проверяем на наличие оставшихся шариков
int counter (bool massive[][12]){
    int count=0;
    for (int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            if (massive[i][j]==true){
                count++;
            }
        }
    }
}

int main () {
    int count = 1;
    bool ballons = true;
    //Создаем массив типа bool
    bool massive[12][12];

    //Проинициализированный массив
    newMassive ( massive );
    while ( count != 0 ) {
        //Лопаем пузырики
        bursting ( massive );
//Результат после лопанья
        result ( massive );

        count = counter ( massive );
    }
    std::cout << "The bubbles are over\n";
}