#include <iostream>
#include <string>

//Расстановка кораблей
void placement (char matrix[][11]) {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    bool num = true;

    //Однопалубные
    std::cout << "We arrange single-deck ships.\n";

    for (int i = 0; i < 4; i++) {
        std::cin >> a >> b;
        while (a > 10 || b > 10) {
            std::cout << "Coordinate error (1)\n";
            std::cin >> a >> b;        }

        while (matrix[a][b] != ' ') {
            std::cout << "This cell is already occupied!\n";
            std::cin >> a >> b;
        }
        matrix[a][b] = '#';
    }

    //Двухпалубные
    std::cout << "We arrange two-deck ships.\n";
    for (int i = 0; i < 3; i++) {
        num = true;
        while (num) {
            std::cin >> a >> b;
            std::cin >> c >> d;

            while (a>10 || b> 10 ||c>10 || d>10) {
                std::cout << "Coordinate error (2)\n";
                std::cin >> a >> b;
                std::cin >> c >> d;
            }

            //Горизонталь
            if (a == c && (b + 1) == d || (b - 1) == d) {
                if (matrix[a][b] == ' ' && matrix[c][d] == ' ') {
                    matrix[a][b] = '#';
                    matrix[c][d] = '#';
                    num = false;
                }
                else if (matrix[a][b] != ' ' || matrix[c][d] != ' ') {
                    std::cout << "This cell is already occupied!\n";
                }
            }

            //Вертикаль
            else if (b == d && (a + 1) == c || (a - 1) == c) {
                if (matrix[a][b] == ' ' && matrix[c][d] == ' ') {
                    matrix[a][b] = '#';
                    matrix[c][d] = '#';
                    num = false;
                }
                else if (matrix[a][b] != ' ' || matrix[c][d] != ' ') {
                    std::cout << "This cell is already occupied!\n";
                }
            }
            else {
                std::cout << "Coordinate error (2)\n";
            }
        }
    }

    //Трехпалубные
    std::cout << "We arrange free-deck ships.\n";
    for (int i = 0; i < 2; i++) {
        num = true;
        while (num) {
            std::cin >> a >> b;
            std::cin >> c >> d;

            while (a > 10 || b > 10 || c > 10 || d > 10) {
                std::cout << "Coordinate error (3)\n";
                std::cin >> a >> b;
                std::cin >> c >> d;
            }

            //Горизонталь
                //Горизонталь (последняя координата слева)
            if (a == c && ((b - 2) == d || (b + 2) == d)) {
                if (a == c && (b - 2) == d) {
                    if (matrix[a][b] == ' ' && matrix[a][b - 1] == ' ' && matrix[c][d] == ' ') {
                        matrix[a][b] = '#';
                        matrix[c][b - 1] = '#';
                        matrix[c][d] = '#';
                        num = false;
                    }
                    else if (matrix[a][b] != ' ' || matrix[a][b - 1] != ' ' || matrix[c][d] != ' ') {
                        std::cout << "This cell is already occupied!\n";
                    }
                }
                //Горизонталь (последняя координата справа)
                else if (a == c && (b + 2) == d) {
                    if (matrix[a][b] == ' ' && matrix[a][b + 1] == ' ' && matrix[c][d] == ' ') {
                        matrix[a][b] = '#';
                        matrix[c][b + 1] = '#';
                        matrix[c][d] = '#';
                        num = false;
                    }
                    else if (matrix[a][b] != ' ' || matrix[a][b + 1] != ' ' || matrix[c][d] != ' ') {
                        std::cout << "This cell is already occupied!\n";
                    }
                }
            }

            //Вертикаль
                //Вертикаль (последняя координата сверху)
            else if (b == d && ((a - 2) == c || (a + 2) == c)) {
                if (b == d && (a - 2) == c) {
                    if (matrix[a][b] == ' ' && matrix[b][a - 1] == ' ' && matrix[c][d] == ' ') {
                        matrix[a][b] = '#';
                        matrix[a - 1][b] = '#';
                        matrix[c][d] = '#';
                        num = false;
                    }
                    else if (matrix[a][b] != ' ' || matrix[b][a - 1] != ' ' || matrix[c][d] != ' ') {
                        std::cout << "This cell is already occupied!\n";
                    }
                }

                //Вертикаль (последняя координата снизу)
                else if (b == d && (a + 2) == c) {
                    if (matrix[a][b] == ' ' && matrix[b][a + 1] == ' ' && matrix[c][d] == ' ') {
                        matrix[a][b] = '#';
                        matrix[a + 1][b] = '#';
                        matrix[c][d] = '#';
                        num = false;
                    }
                    else if (matrix[a][b] != ' ' || matrix[b][a + 1] != ' ' || matrix[c][d] != ' ') {
                        std::cout << "This cell is already occupied!\n";
                    }
                }
            }
            else {
                std::cout << "Coordinate error (3)\n";
            }
        }
    }

    //Четырехпалубгый
    std::cout << "We arrange four-deck ships.\n";
    for (int i = 0; i < 1; i++) {
        num = true;
        while (num) {
            std::cin >> a >> b;
            std::cin >> c >> d;
            while (a > 10 || b > 10 || c > 10 || d > 10) {
                std::cout << "Coordinate error (4)\n";
                std::cin >> a >> b;
                std::cin >> c >> d;
            }

            //Горизонталь
                //Горизонталь (последняя координата слева)
            if (a == c && ((b - 3) == d || (b + 3) == d)) {
                if (a == c && (b - 3) == d) {
                    if (matrix[a][b] == ' ' && matrix[a][b - 1] == ' ' && matrix[a][b - 2] == ' ' && matrix[c][d] == ' ') {
                        matrix[a][b] = '#';
                        matrix[c][b - 1] = '#';
                        matrix[c][b - 2] = '#';
                        matrix[c][d] = '#';
                        num = false;
                    }
                    else if (matrix[a][b] != ' ' || matrix[a][b - 1] != ' ' || matrix[a][b - 2] != ' ' || matrix[c][d] != ' ') {
                        std::cout << "This cell is already occupied!\n";
                    }
                }
                //Горизонталь (последняя координата справа)
                else if (a == c && (b + 3) == d) {
                    if (matrix[a][b] == ' ' && matrix[a][b + 1] == ' ' && matrix[a][b + 2] == ' ' && matrix[c][d] == ' ') {
                        matrix[a][b] = '#';
                        matrix[c][b + 1] = '#';
                        matrix[c][b + 2] = '#';
                        matrix[c][d] = '#';
                        num = false;
                    }
                    else if (matrix[a][b] != ' ' || matrix[a][b + 1] != ' ' || matrix[a][b + 2] != ' ' || matrix[c][d] != ' ') {
                        std::cout << "This cell is already occupied!\n";
                    }
                }
            }

            //Вертикаль
                //Вертикаль (последняя координата сверху)
            else if (b == d && ((a - 3) == c || (a + 3) == c)) {
                if (b == d && (a - 3) == c) {
                    if (matrix[a][b] == ' ' && matrix[b][a - 1] == ' ' && matrix[b][a - 2] == ' ' && matrix[c][d] == ' ') {
                        matrix[a][b] = '#';
                        matrix[a - 1][b] = '#';
                        matrix[a - 2][b] = '#';
                        matrix[c][d] = '#';
                        num = false;
                    }
                    else if (matrix[a][b] != ' ' || matrix[b][a - 1] != ' ' || matrix[b][a - 2] != ' ' || matrix[c][d] != ' ') {
                        std::cout << "This cell is already occupied!\n";
                    }
                }

                //Вертикаль (последняя координата снизу)
                else if (b == d && (a + 3) == c) {
                    if (matrix[a][b] == ' ' && matrix[b][a + 1] == ' ' && matrix[b][a + 2] == ' ' && matrix[c][d] == ' ') {
                        matrix[a][b] = '#';
                        matrix[a + 1][b] = '#';
                        matrix[a + 2][b] = '#';
                        matrix[c][d] = '#';
                        num = false;
                    }
                    else if (matrix[a][b] != ' ' || matrix[b][a + 1] != ' ' || matrix[b][a + 2] != ' ' || matrix[c][d] != ' ') {
                        std::cout << "This cell is already occupied!\n";
                    }
                }
            }
            else {
                std::cout << "Coordinate error (4)\n";
            }
        }
    }
}

//Выстрел
void shot(char matrix[][11],std::string player) {
    int a = 0;
    int b = 0;
    std::cout << "Shot.The "<<player<<" player: \n";
    std::cin >> a >> b;
    while (a > 10 || b > 10) {
        std::cout << "Coordinate shot error\n";
        std::cout << "Shot.The " << player << " player: \n";
        std::cin >> a >> b;
    }
    while (matrix[a][b] == 'X') {
        std::cout << "Coordinate shot error\n";
        std::cout << "Shot.The " << player << " player: \n";
        std::cin >> a >> b;
    }
    if(matrix[a][b] == '#'){
        std::cout<<"You are trapped!\n";
    }
    if (matrix[a][b] != '#'){
        std::cout<<"You didn't hit!\n";
    }
    matrix[a][b] = 'X';
}

//Проверка на победу
int result (char matrix[][11]) {
    int count = 0;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            matrix[i][j];
            if (matrix[i][j] == '#') {
                count++;
            }
        }
    }
    return count;
}

//Результат поля каждого игрока
void resultArena (char matrix[][11]) {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int count = 0;
    std::string playerOne = "first";
    std::string playerTwo = "Second";

    //Создаем матрицу
    char arenaPlayerOne[11][11]{ { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' },
                                  { '1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '8', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '9', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' } };

    char arenaPlayerTwo[11][11]{ { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' },
                                  { '1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '8', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '9', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                                  { '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' } };

    //Правила игры
    std::cout << "1.The coordinates should be arranged as follows: first specify the digit of the row, and then the digit of the column.\n";
    std::cout << "2.The coordinates of the field start from 1x1 and end with 10x10.\n";
    std::cout << "3.The installation of ships takes place by writing the coordinates, the beginning and the end of the ship (the exception is single-deck, they are set by introducing 1 coordinate (for example, 1 1).\n";
    std::cout << "4.Shots are fired using coordinates (for example 1 1 or 8 4).\n";
    std::cout << "5.Installing the ship diagonally is not allowed\n\n\n";

    //Заполняем кораблями поле первого игрока
    std::cout << "We fill the first player's field with ships\n";
    placement(arenaPlayerOne);

    //Заполняем кораблями поле Второго игрока
    std::cout << "We fill the second player's field with ships\n";
    placement(arenaPlayerTwo);

/////////////////////////////////Игрок 1////////////////////////////////////////

    for (int i = 0; i < 200; i++) {

        //Выстрел 1 игрока
        shot(arenaPlayerTwo, playerOne);

        //проверяем на победу 1 игрока
        count = result(arenaPlayerTwo);

        //Результат поля 1 игрока
        resultArena(arenaPlayerOne);

        if (count == 0) {
            std::cout << "The first player win!";
            break;
        }

/////////////////////////////////Игрок 2////////////////////////////////////////

        //Выстрел 2 игрока
        shot(arenaPlayerOne, playerTwo);

        //проверяем на победу 2 игрока
        count = result(arenaPlayerOne);

        //Результат поля 2 игрока
        resultArena(arenaPlayerTwo);
        if (count == 0) {
            std::cout << "The second player win!";
            break;
        }
    }
}