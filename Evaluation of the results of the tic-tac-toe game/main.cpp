#include <iostream>
#include <string>

//Счетчик кол-ва X
int strAllX (std::string strA, std::string strB, std::string strC) {
    int i;
    int countX = 0;

    for ( i = 0; i < strA.length (); i++ ) {
        if ( strA[i] == 'X' ) {
            countX += 1;
        }
    }
    for ( i = 0; i < strB.length (); i++ ) {
        if ( strB[i] == 'X' ) {
            countX += 1;
        }
    }
    for ( i = 0; i < strC.length (); i++ ) {
        if ( strC[i] == 'X' ) {
            countX += 1;
        }
    }
    return countX;
}

//Счетчик кол-ва O
int strAllO (std::string strA, std::string strB, std::string strC) {
    int i;
    int countO = 0;

    for ( i = 0; i < strA.length (); i++ ) {
        if ( strA[i] == 'O' ) {
            countO += 1;
        }
    }
    for ( i = 0; i < strB.length (); i++ ) {
        if ( strB[i] == 'O' ) {
            countO += 1;
        }
    }
    for ( i = 0; i < strC.length (); i++ ) {
        if ( strC[i] == 'O' ) {
            countO += 1;
        }
    }
    return countO;
}

//Счетчик кол-ва '.'
int strAllPoint (std::string strA, std::string strB, std::string strC) {
    int i;
    int countPoint = 0;

    for ( i = 0; i < strA.length (); i++ ) {
        if ( strA[i] == '.' ) {
            countPoint += 1;
        }
    }
    for ( i = 0; i < strB.length (); i++ ) {
        if ( strB[i] == '.' ) {
            countPoint += 1;
        }
    }
    for ( i = 0; i < strC.length (); i++ ) {
        if ( strC[i] == '.' ) {
            countPoint += 1;
        }
    }
    return countPoint;
}

//Проверка на допустимые символы
int errors(std::string strA, std::string strB, std::string strC){
    int i = 0;
    int error = 0;
    for ( i = 0; i < strA.length (); i++ ) {
        if ( strA[i] != 'X' && strA[i] != 'O' && strA[i] != '.' ) {
            error += 1;
        }
    }
    for ( i = 0; i < strB.length (); i++ ) {
        if ( strB[i] != 'X' && strB[i] != 'O' && strB[i] != '.' ) {
            error += 1;
        }
    }
    for ( i = 0; i < strC.length (); i++ ) {
        if ( strC[i] != 'X' && strC[i] != 'O' && strC[i] != '.' ) {
            error += 1;
        }
    }
    return error;
}

int main ()
{
    int winX = 0;       //Счетчик выигрышной позиции Х
    int winO = 0;       //Счетчик выигрышной позиции О
    std::string strA;   //Строка А
    std::string strB;   //Строка B
    std::string strC;   //Строка С

    std::cout << "Enter result game: \n";
    std::cin >> strA;
    std::cin >> strB;
    std::cin >> strC;

    int countX = strAllX (strA, strB, strC);          //Счетчик кол-ва X
    int countO = strAllO (strA, strB, strC);          //Счетчик символов O
    int countPoint = strAllPoint (strA, strB, strC);  //Счетчик точек
    int error = errors (strA, strB, strC);            //Счетчик неверных символов

    std::cout<<countX<<countO<<countPoint<<error;

    if ( error == 0 ) {

// Выигрышные позиции для Х
        if ( ( strA[0] == 'X' && strA[1] == 'X' && strA[2] == 'X' ) ||
             ( strA[0] == 'X' && strB[0] == 'X' && strC[0] == 'X' ) ||
             ( strB[0] == 'X' && strB[1] == 'X' && strB[2] == 'X' ) ||
             ( strA[1] == 'X' && strB[1] == 'X' && strC[1] == 'X' ) ||
             ( strC[2] == 'X' && strC[1] == 'X' && strC[0] == 'X' ) ||
             ( strC[2] == 'X' && strB[2] == 'X' && strA[2] == 'X' ) ||
             ( strA[0] == 'X' && strB[1] == 'X' && strC[2] == 'X' ) ||
             ( strA[2] == 'X' && strB[1] == 'X' && strC[0] == 'X' ) ) {
            if ( countO >= countX ) {
                std::cout << "Incorrect (The crosses have already won, and there can't be as many or more zeros)";
            } else {
                std::cout << "Petya won!";
            }
        }

// Выигрышные позиции для O
        else if ( ( strA[0] == 'O' && strA[1] == 'O' && strA[2] == 'O' ) ||
                  ( strA[0] == 'O' && strB[0] == 'O' && strC[0] == 'O' ) ||
                  ( strB[0] == 'O' && strB[1] == 'O' && strB[2] == 'O' ) ||
                  ( strA[1] == 'O' && strB[1] == 'O' && strC[1] == 'O' ) ||
                  ( strC[2] == 'O' && strC[1] == 'O' && strC[0] == 'O' ) ||
                  ( strC[2] == 'O' && strB[2] == 'O' && strA[2] == 'O' ) ||
                  ( strA[0] == 'O' && strB[1] == 'O' && strC[2] == 'O' ) ||
                  ( strA[2] == 'O' && strB[1] == 'O' && strC[0] == 'O' ) ) {

//Сравнение символов
            if ( countX > countO ) {
                std::cout << "Incorrect (There can be no more crosses at the end of the game than zeros)";
            } else if ( countO > countX ) {
                std::cout << "Incorrect (There can't be more noughts at the end of the game than crosses)";
            } else {
                std::cout << "Vanya won!";
            }
        }

//Ничья
        else if ( countPoint >= 1 ) {
            std::cout << "Nobody (Not finished playing)";
        } else if ( countPoint == 0 ) {
            std::cout << "Nobody (Draw)";
        }
    }
    else {
        std::cout<< "Incorrect (Only the characters X, O and dot are allowed).";
    }
}