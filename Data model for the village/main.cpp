#include <iostream>
#include <string>
#include <vector>


//Структура комнаты
struct rooms {
    std::string nameRoom; //Название комнаты
    float square = 0.0f;  //Площадь комнаты
};

//Структура этажа
struct levels {
    float square = 0.0f;  //Площадь этажа
    float heigth = 0.0f;  //Высота потолка
    rooms room[4];        //Кол-во комнат (4)
};

//Структура строения
struct buildings {
    std::string nameBuilding; //Название строения
    float square = 0.0f;      //Площадь строения
    levels level[3];          //Кол-во этажей (3)
};

//Структура региона
struct regions {
    buildings building[4];  //Кол-во строений (4)
};


int main() {
    regions region;
    std::string numbers;
    bool good=false;
    float squareBuilding=0;
    float squareLevel=0;
    float squareRoom=0;
    float countSquare=0;
    int numberRegion = 0;

    std::vector <std::string> vecName; //Название строения

    std::cout << "Number of region?\n";
    std::cin >> numberRegion;

    //Заполняем регионы
    for (int reg = 0; reg < numberRegion; reg++) {

        //Заполняем регион
        for (int building = 0; building < 4; building++) {

            while(!good) {

                std::cout << "Name building: \n";           //Название строения
                std::cin >> region.building[building].nameBuilding;

                for ( int i = 0; i < region.building[building].nameBuilding.length (); i++ ) {
                    if ( ( region.building[building].nameBuilding[i] >= 'A' &&
                           region.building[building].nameBuilding[i] <= 'Z' ) ||
                         ( region.building[building].nameBuilding[i] >= 'a' &&
                           region.building[building].nameBuilding[i] <= 'z' ) ) {
                        good = true;
                    } else {
                        good = false;
                        std::cout<<"Error. Name building is 'A'-'Z' and 'a'-'z'!\n";
                        break;
                    }
                }
            }

            vecName.push_back(region.building[building].nameBuilding);

            std::cout << "Square building: \n";         //Площадь строения
            std::cin >> region.building[building].square;

            squareBuilding=region.building[building].square;
            vecName.push_back(std::to_string(region.building[building].square));


            //Запоняем этажи
           for (int level = 0; level < 3; level++) {

               std::cout << "Heigth " << level + 1 << " level\n";  //Высота этажа
               std::cin >> region.building[building].level[level].heigth;
               vecName.push_back(std::to_string(region.building[building].level[level].heigth));

               std::cout << "Square " << level + 1 << " level\n";   //Площадь этажа
               std::cin >> region.building[building].level[level].square;
               squareLevel = region.building[building].level[level].square;

               while(squareLevel>squareBuilding) {
                   std::cout<<"The floor area cannot be larger than the area of the house!\n";
                   std::cout << "Square " << level + 1 << " level\n";   //Площадь этажа
                   std::cin >> region.building[building].level[level].square;
                   squareLevel = region.building[building].level[level].square;
               }
               countSquare=squareLevel;
               vecName.push_back(std::to_string(region.building[building].level[level].square));


               //Ставим комнаты
              for (int room = 0; room < 4 ; room++) {

                  good=false;

                  while(good!=true) {

                      std::cout << "Name room: \n";          //Название комнаты
                      std::cin >> region.building[building].level[level].room[room].nameRoom;

                      for ( int i = 0; i < region.building[building].level[level].room[room].nameRoom.length (); i++ ) {
                          if ( ( region.building[building].level[level].room[room].nameRoom[i] >= 'A' &&
                                 region.building[building].level[level].room[room].nameRoom[i] <= 'Z' ) ||
                               ( region.building[building].level[level].room[room].nameRoom[i] >= 'a' &&
                                 region.building[building].level[level].room[room].nameRoom[i] <= 'z' ) ) {
                              good = true;
                          } else {
                              good = false;
                              std::cout << "Error. Name room is 'A'-'Z' and 'a'-'z'!\n";
                              break;
                          }
                      }
                      vecName.push_back(region.building[building].level[level].room[room].nameRoom);
                  }

                      std::cout << "Square room: \n";   //Площадь комнаты
                      std::cin >> region.building[building].level[level].room[room].square;
                      squareRoom=region.building[building].level[level].room[room].square;
                      countSquare-=squareRoom;
                      std::cout<<"There is a free area left "<<countSquare<<".\n";
                      if(countSquare<0){
                          std::cout<<"The area of the rooms cannot exceed the floor area!\n";
                          room=0;
                          countSquare=squareLevel;
                      }
                  vecName.push_back(std::to_string(region.building[building].level[level].room[room].square));
              }
           }
        }
    }

    //Чтение
   for (int reg = 0; reg < vecName.size(); reg++) {

       std::cout << "Name building: " << vecName[reg] << "\n";
       reg += 1;
       std::cout << "Square building: " << vecName[reg] << "\n";

       for ( int l = 0; l < 3; l++ ) {
           reg += 1;
           std::cout << "Heigth level: " << vecName[reg] << "\n";
           reg += 1;
           std::cout << "Square level: " << vecName[reg] << "\n";

           for ( int r = 0; r < 4; r++ ) {
               reg += 1;
               std::cout << "Name room: " << vecName[reg] << "\n";
               reg += 1;
               std::cout << "Square room: " << vecName[reg] << "\n";
           }
       }
       std::cout<<"\n\n";
   }
}