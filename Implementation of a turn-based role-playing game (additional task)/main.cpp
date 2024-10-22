#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

struct enemys {
    char pointName;
    std::string name;
    int health = 0;
    int armor = 0;
    int damage = 0;
    int X = 0;
    int Y = 0;
    bool point=true;
};
struct characters {
    enemys enemy[6];
};

void fieldOut(char field[20][20]) {
    for (int i = 0; i < 20; i++) {    //Выводим поле
        for (int k = 0; k < 20; k++) {
            std::cout << field[i][k];
        }
        std::cout << "\n";
    }
} //Выводим поле
void new_game(characters &character, char field[20][20]){
    int pointX=0;
    int pointY=0;


    for ( int i = 0; i < 6; i++ ) {
        if ( i == 5 ) {
            character.enemy[i].pointName = 'P';
            break;
        }
        character.enemy[i].name = "Enemy #" + std::to_string ( i + 1 );
        character.enemy[i].pointName = 'E';
        character.enemy[i].health = (std::rand () % 101) + 50;
        character.enemy[i].armor = std::rand () % 51;
        character.enemy[i].damage = (std::rand () % 16) + 15;
    }  //Хар-ки врагов

    std::cout << "Let's create a character!\n";
    std::cout << "Name your a character:\n";
    std::cin >> character.enemy[5].name;
    std::cout << "Health your a character:\n";
    std::cin >> character.enemy[5].health;
    std::cout << "Armor your a character:\n";
    std::cin >> character.enemy[5].armor;
    std::cout << "Damage your a character:\n";
    std::cin >> character.enemy[5].damage;

    for ( int i = 0; i < 6; i++ ) {

        if ( i < 5 ) {
            do {
                pointX = (std::rand () % 20) + 1;
                pointY = (std::rand () % 20) + 1;
            } while ( field[pointY - 1][pointX - 1] == character.enemy[i].pointName );

            field[pointY - 1][pointX - 1] = character.enemy[i].pointName;
            character.enemy[i].X = pointX - 1;
            character.enemy[i].Y = pointY - 1;
        } //Расстановка врагов на поле

        if ( i == 5 ) {
            do {
                pointX = (std::rand () % 20) + 1;
                pointY = (std::rand () % 20) + 1;
            } while ( field[pointY - 1][pointX - 1] == character.enemy[i].pointName );

            field[pointY - 1][pointX - 1] = character.enemy[i].pointName;
            character.enemy[i].Y = pointY - 1;
            character.enemy[i].X = pointX - 1;
        } //Ставим нашего персонажа
    }   //Расстановка игроков на поле
    fieldOut ( field );
} //Новая игра
void save_game(std::ofstream &saveFile,characters &character){
    for ( int i = 0; i < 6; i++ ) {
        saveFile.write ( &character.enemy[i].pointName, sizeof ( character.enemy[i].pointName ));
        int len = character.enemy[i].name.length ();
        saveFile.write (( char * ) &len, sizeof ( len ));
        saveFile.write ( character.enemy[i].name.c_str (), len );
        saveFile.write (( char * ) &character.enemy[i].health, sizeof ( character.enemy[i].health ));
        saveFile.write (( char * ) &character.enemy[i].armor, sizeof ( character.enemy[i].armor ));
        saveFile.write (( char * ) &character.enemy[i].damage, sizeof ( character.enemy[i].damage ));
        saveFile.write (( char * ) &character.enemy[i].X, sizeof ( character.enemy[i].X ));
        saveFile.write (( char * ) &character.enemy[i].Y, sizeof ( character.enemy[i].Y ));
        saveFile.write (( char * ) &character.enemy[i].point, sizeof ( character.enemy[i].point ));
    }
}
void load_game (std::ifstream &saveFile,characters &character, char field[20][20]) {
    for ( int i = 0; i < 6; i++ ) {
        saveFile.read (( char * ) &character.enemy[i].pointName, sizeof ( character.enemy[i].pointName ));
        int len;
        saveFile.read (( char * ) &len, sizeof ( len ));
        character.enemy[i].name.resize ( len );
        saveFile.read (( char * ) character.enemy[i].name.c_str (), len );
        saveFile.read (( char * ) &character.enemy[i].health, sizeof ( character.enemy[i].health ));
        saveFile.read (( char * ) &character.enemy[i].armor, sizeof ( character.enemy[i].armor ));
        saveFile.read (( char * ) &character.enemy[i].damage, sizeof ( character.enemy[i].damage ));
        saveFile.read (( char * ) &character.enemy[i].X, sizeof ( character.enemy[i].X ));
        saveFile.read (( char * ) &character.enemy[i].Y, sizeof ( character.enemy[i].Y ));
        saveFile.read (( char * ) &character.enemy[i].point, sizeof ( character.enemy[i].point ));
    }
    for(int i=0;i<6;i++){
        field[character.enemy[i].Y][character.enemy[i].X]=character.enemy[i].pointName;
    }
    fieldOut(field);
}//Загрузка игры
void state (characters &character){
    for ( int i = 0; i < 6; i++ ) {
        std::cout << character.enemy[i].name << "\n";
        std::cout << character.enemy[i].health << "\n";
        std::cout << character.enemy[i].armor << "\n";
        std::cout<<character.enemy[i].damage<<"\n\n";
    }
} //Хар-ка и состояние игроков на поле

int main() {
    srand ( time ( NULL ));

    characters character;
    std::string direction;
    std::string operation;
    int number = 0;

    std::cout << "New game or download save? (new,load)\n";
    std::cin >> operation;

    char field[20][20]; //Игровое поле
    for ( int i = 0; i < 20; i++ ) {
        for ( int k = 0; k < 20; k++ ) {
            field[i][k] = '.';
        }
    }    //Запоняем поле '.'
    if ( operation == "new" ) {
        new_game(character,field);
    } //Если новая игра
    if ( operation == "load" ) {
        std::ifstream saveFile ("C:\\Users\\Alexsandr Makhov\\Desktop\\Save.bin", std::ios::binary );
        load_game (saveFile,character, field);
        saveFile.close();
    } //Если загрузка игры

    while ( character.enemy[5].health > 0 || direction != "save" ||
            (character.enemy[0].health <= 0 && character.enemy[1].health <= 0 &&
             character.enemy[2].health <= 0 && character.enemy[3].health <= 0 &&
             character.enemy[4].health <= 0)) {

        if ( character.enemy[5].health <= 0 ) {
            std::cout << "Player dead.\n";
            break;
        } //Если здорове персонажа 0 значит игрок проиграл

        if ( character.enemy[0].health <= 0 && character.enemy[1].health <= 0 &&
             character.enemy[2].health <= 0 && character.enemy[3].health <= 0 &&
             character.enemy[4].health <= 0 ) {
            std::wcout << "Player win.\n";
            break;
        } //Если здоровье противников равно 0, значит они проиграли

        std::cout << "Direction:\n";
        std::cin >> direction;

        if ( direction == "save" ) {
            std::ofstream saveFile ( "C:\\Users\\Alexsandr Makhov\\Desktop\\Save.bin", std::ios::binary );
            save_game(saveFile,character);
            saveFile.close ();
            break;
        }

        if ( direction == "W" || direction == "w" ) {


            if ( character.enemy[5].Y - 1 >= 0 ) {
                if ( field[character.enemy[5].Y - 1][character.enemy[5].X] == '.' ) {
                    field[character.enemy[5].Y][character.enemy[5].X] = '.';
                    field[character.enemy[5].Y - 1][character.enemy[5].X] = character.enemy[5].pointName;
                    character.enemy[5].Y = character.enemy[5].Y - 1;
                }

                if ( field[character.enemy[5].Y - 1][character.enemy[5].X] == 'E' ) {
                    for ( int i = 0; i < 5; i++ ) {
                        if ((character.enemy[i].Y == character.enemy[5].Y - 1) &&
                            (character.enemy[i].X == character.enemy[5].X)) {
                            character.enemy[i].armor -= character.enemy[5].damage;
                            if ( character.enemy[i].armor <= 0 ) {
                                character.enemy[i].health += character.enemy[i].armor;
                                character.enemy[i].armor = 0;
                            }
                        }
                    }
                }
            } else {
                std::cout << "Error coordinate!\n";
            }
        } //Движение игрока вверх
        if ( direction == "S" || direction == "s" ) {

            if ( character.enemy[5].Y + 1 <= 19 ) {

                if ( field[character.enemy[5].Y + 1][character.enemy[5].X] == '.' ) {
                    field[character.enemy[5].Y][character.enemy[5].X] = '.';
                    field[character.enemy[5].Y + 1][character.enemy[5].X] = character.enemy[5].pointName;
                    character.enemy[5].Y = character.enemy[5].Y + 1;
                }

                if ( field[character.enemy[5].Y + 1][character.enemy[5].X] == 'E' ) {
                    for ( int i = 0; i < 5; i++ ) {
                        if ((character.enemy[i].Y == character.enemy[5].Y + 1) &&
                            (character.enemy[i].X == character.enemy[5].X)) {
                            character.enemy[i].armor -= character.enemy[5].damage;
                            if ( character.enemy[i].armor <= 0 ) {
                                character.enemy[i].health += character.enemy[i].armor;
                                character.enemy[i].armor = 0;
                            }
                        }
                    }
                }
            } else {
                std::cout << "Error coordinate!\n";
            }
        } //Движение игрока вниз
        if ( direction == "A" || direction == "a" ) {

            if ( character.enemy[5].X - 1 >= 0 ) {

                if ( field[character.enemy[5].Y][character.enemy[5].X - 1] == '.' ) {
                    field[character.enemy[5].Y][character.enemy[5].X] = '.';
                    field[character.enemy[5].Y][character.enemy[5].X - 1] = character.enemy[5].pointName;
                    character.enemy[5].X = character.enemy[5].X - 1;
                }

                if ( field[character.enemy[5].Y][character.enemy[5].X - 1] == 'E' ) {
                    for ( int i = 0; i < 5; i++ ) {
                        if ((character.enemy[i].Y == character.enemy[5].Y) &&
                            (character.enemy[i].X == character.enemy[5].X - 1)) {
                            character.enemy[i].armor -= character.enemy[5].damage;
                            if ( character.enemy[i].armor <= 0 ) {
                                character.enemy[i].health += character.enemy[i].armor;
                                character.enemy[i].armor = 0;
                            }
                        }
                    }
                }
            } else {
                std::cout << "Error coordinate!\n";
            }
        } //Движение игрока влево
        if ( direction == "D" || direction == "d" ) {

            if ( character.enemy[5].X + 1 <= 19 ) {

                if ( field[character.enemy[5].Y][character.enemy[5].X + 1] == '.' ) {
                    field[character.enemy[5].Y][character.enemy[5].X] = '.';
                    field[character.enemy[5].Y][character.enemy[5].X + 1] = character.enemy[5].pointName;
                    character.enemy[5].X = character.enemy[5].X + 1;
                }

                if ( field[character.enemy[5].Y][character.enemy[5].X + 1] == 'E' ) {
                    for ( int i = 0; i < 5; i++ ) {
                        if ((character.enemy[i].Y == character.enemy[5].Y) &&
                            (character.enemy[i].X == character.enemy[5].X + 1)) {
                            character.enemy[i].armor -= character.enemy[5].damage;
                            if ( character.enemy[i].armor <= 0 ) {
                                character.enemy[i].health += character.enemy[i].armor;
                                character.enemy[i].armor = 0;
                            }
                        }
                    }
                }
            } else {
                std::cout << "Error coordinate!\n";
            }
        } //Движение игрока вправо

        for ( int i = 0; i < 5; i++ ) {
            number = std::rand () % 4;

            if ( number == 0 ) {

                if ( character.enemy[i].health > 0 && character.enemy[i].Y - 1 >= 0 ) {

                    if ( field[character.enemy[i].Y - 1][character.enemy[i].X] == '.' ) {
                        field[character.enemy[i].Y][character.enemy[i].X] = '.';
                        field[character.enemy[i].Y - 1][character.enemy[i].X] = character.enemy[i].pointName;
                        character.enemy[i].Y = character.enemy[i].Y - 1;
                    }

                    if ( field[character.enemy[i].Y - 1][character.enemy[i].X] == 'P' ) {
                        character.enemy[5].armor -= character.enemy[i].damage;
                        if ( character.enemy[5].armor <= 0 ) {
                            character.enemy[5].health += character.enemy[5].armor;
                            character.enemy[5].armor = 0;
                        }
                    }
                }

                if ( character.enemy[i].health <= 0 && character.enemy[i].point==true ) {
                    field[character.enemy[i].Y][character.enemy[i].X] = '.';
                    character.enemy[i].point=false;
                }
            }

            if ( number == 1 ) {

                if ( character.enemy[i].health > 0 && character.enemy[i].Y + 1 <= 19 ) {

                    if ( field[character.enemy[i].Y + 1][character.enemy[i].X] == '.' ) {
                        field[character.enemy[i].Y][character.enemy[i].X] = '.';
                        field[character.enemy[i].Y + 1][character.enemy[i].X] = character.enemy[i].pointName;
                        character.enemy[i].Y = character.enemy[i].Y + 1;
                    }

                    if ( field[character.enemy[i].Y + 1][character.enemy[i].X] == 'P' ) {
                        character.enemy[5].armor -= character.enemy[i].damage;
                        if ( character.enemy[5].armor <= 0 ) {
                            character.enemy[5].health += character.enemy[5].armor;
                            character.enemy[5].armor = 0;
                        }
                    }
                }

                if ( character.enemy[i].health <= 0 && character.enemy[i].point==true ) {
                    field[character.enemy[i].Y][character.enemy[i].X] = '.';
                    character.enemy[i].point=false;
                }
            }

            if ( number == 2 ) {

                if ( character.enemy[i].health > 0 && character.enemy[i].X - 1 >= 0 ) {

                    if ( field[character.enemy[i].Y][character.enemy[i].X - 1] == '.' ) {
                        field[character.enemy[i].Y][character.enemy[i].X] = '.';
                        field[character.enemy[i].Y][character.enemy[i].X - 1] = character.enemy[i].pointName;
                        character.enemy[i].X = character.enemy[i].X - 1;
                    }

                    if ( field[character.enemy[i].Y][character.enemy[i].X - 1] == 'P' ) {
                        character.enemy[5].armor -= character.enemy[i].damage;
                        if ( character.enemy[5].armor <= 0 ) {
                            character.enemy[5].health += character.enemy[5].armor;
                            character.enemy[5].armor = 0;
                        }
                    }
                }

                if ( character.enemy[i].health <= 0 && character.enemy[i].point==true ) {
                    field[character.enemy[i].Y][character.enemy[i].X] = '.';
                    character.enemy[i].point=false;
                }
            }

            if ( number == 3 ) {

                if ((character.enemy[i].health > 0) && character.enemy[i].X + 1 <= 19 ) {

                    if ( field[character.enemy[i].Y][character.enemy[i].X + 1] == '.' ) {
                        field[character.enemy[i].Y][character.enemy[i].X] = '.';
                        field[character.enemy[i].Y][character.enemy[i].X + 1] = character.enemy[i].pointName;
                        character.enemy[i].X = character.enemy[i].X + 1;
                    }

                    if ( field[character.enemy[i].Y][character.enemy[i].X + 1] == 'P' ) {
                        character.enemy[5].armor -= character.enemy[i].damage;
                        if ( character.enemy[5].armor <= 0 ) {
                            character.enemy[5].health += character.enemy[5].armor;
                            character.enemy[5].armor = 0;
                        }
                    }
                }

                if ( character.enemy[i].health <= 0 && character.enemy[i].point==true ) {
                    field[character.enemy[i].Y][character.enemy[i].X] = '.';
                    character.enemy[i].point=false;
                }
            }
        } //Случайное перемещение врагов

        state (character); //Хар-ка и состояние игроков на поле

        fieldOut ( field );
    }
}