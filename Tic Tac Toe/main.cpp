# include <iostream>
# include <vector>
# include <string>

int main()
{
	int a;
	int b;
	int c = 0;
	int br = 0;
	int count = 0;
	int diagonalX = 0;
	int diagonalO = 0;
	char game[3][3]{ {' ',' ',' '},   //0
					  {' ',' ',' '},   //1
					  {' ',' ',' '} }; //2

//Запрос на ввод "Х"
	for (int i = 0; i < 9; i+=2) {
		for (int j = 0; j < 1; j++) {
			std::cout << "Go X.\n";
			std::cout << "Coordinates: \n";
			std::cin >> a >> b;

//Проверка на наличие занятых клеток
			while (game[a][b] == 'X' || game[a][b] == 'O') {
				std::cout << "Error\n";
				std::cout << "Go X.\n";
				std::cout << "Coordinates: \n";
				std::cin >> a >> b;
			}

//Проверка на выход за границы игрового поля
			while ((a > 2 && b > 2) || a > 2 || b > 2) {
				std::cout << "Error coordinates\n";
				std::cout << "Go X.\n";
				std::cout << "Coordinates: \n";
				std::cin >> a >> b;
			}
			game[a][b] = 'X';
		}
		std::cout << "\n";

//Вывод результатов
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << game[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "\n";

//Проверка позиций после "X"
		int horozontallyX = 0;
		int verticallyX = 0;
		br = 0;
		for (int i = 0; i < 3; i++) {
			horozontallyX = 0;
			verticallyX = 0;
			for (int k = 0; k < 3; k++) {

				if (game[i][k] == 'X') {
					horozontallyX++;
				}
				if (game[k][i] == 'X') {
					verticallyX++;
				}
				if (horozontallyX == 3) {
					std::cout << "X win.\n";
					br++;
					break;
				}
				if (verticallyX == 3) {
					std::cout << "X win.\n";
					br++;
					break;
				}
			}
		}

		if (br>0) {
			break;
		}

		std::cout << "\n";

		diagonalX = 0;

		for (int i = 0; i < 3; i++) {
			if (game[i][i] == 'X') {
				diagonalX++;
			}
		}
		if (diagonalX == 3) {
			std::cout << "X win.\n";
			break;
		}

		diagonalX = 0;
		c = 2;

		for (int i = 0; i < 3; i++) {
			if (game[i][c] == 'X') {
				diagonalX++;
			}
			c--;
		}
		if (diagonalX == 3) {
			std::cout << "X win.\n";
			break;
		}

		count++;
		if (count == 9) {
			std::cout << "No win.";
			break;
		}

//Запрос на ввод "O"
		for (int j = 0; j < 1; j++) {
			std::cout << "Go O.\n";
			std::cout << "Coordinates: \n";
			std::cin >> a >> b;

//Проверка на наличие занятых клеток
			while (game[a][b] == 'X' || game[a][b] == 'O') {
				std::cout << "Error\n";
				std::cout << "Go O.\n";
				std::cout << "Coordinates: \n";
				std::cin >> a >> b;
			}

//Проверка на выход за границы игрового поля
			while ((a > 2 && b > 2) || a > 2 || b > 2) {
				std::cout << "Error coordinates\n";
				std::cout << "Go O.\n";
				std::cout << "Coordinates: \n";
				std::cin >> a >> b;
			}
			game[a][b] = 'O';
		}
		std::cout << "\n";

//Вывод результатов
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << game[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "\n";

//Проверка позиций после "O"
		int horozontallyO = 0;
		int verticallyO = 0;
		br = 0;
		for (int i = 0; i < 3; i++) {
			horozontallyO = 0;
			verticallyO = 0;
			for (int k = 0; k < 3; k++) {
				if (game[i][k] == 'O') {
					horozontallyO++;
				}
				if (game[k][i] == 'O') {
					verticallyO++;
				}
				if (horozontallyO == 3) {
					std::cout << "O win.\n";
					br++;
					break;
				}
				if (verticallyO == 3) {
					std::cout << "O win.\n";
					br++;
					break;
				}
			}
		}

		if (br > 0) {
			break;
		}

		diagonalO = 0;

		for (int i = 0; i < 3; i++) {
			if (game[i][i] == 'O') {
				diagonalO++;
			}
		}
		if (diagonalO == 3) {
			std::cout << "O win.\n";
			break;
		}

		diagonalO = 0;
		c = 2;

		for (int i = 0; i < 3; i++) {
			if (game[i][c] == 'O') {
				diagonalO++;
			}
			c--;
		}
		if (diagonalO == 3) {
			std::cout << "O win.\n";
			break;
		}
		std::cout << "\n";

		count++;
		if (count == 9) {
			std::cout << "No win.";
			break;
		}
	}
}