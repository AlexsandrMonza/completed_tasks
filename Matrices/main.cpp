# include <iostream>
# include <vector>

//Записывем матрицы
void newMatrix(int matrix[][4], int a) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << "Enter number (matrix 1): \n";
			std::cin >> matrix[i][j];
		}
	}
}

//Проверяем матрицу на равенство
bool comparison(int matrixOne[][4], int matrixTwo[][4]) {
	int a = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (matrixOne[i][j] != matrixTwo[i][j]) {
				std::cout << "No";
				return false;
				break;
			}
		}
	}
	return true;
}

//Если матрицы равны
void reMatrix(int matrixOne[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i != j) {
				matrixOne[i][j] = 0;
			}
		}
	}
}

int main()
{
	bool c=true;
	int a=0;
	int matrixOne[4][4];
	int matrixTwo[4][4];

	//Заполняем первую матрицу
	std::cout << "Input matrix 1!\n";
	newMatrix(matrixOne,a);

	//Заполняем вторую матрицу
	std::cout << "Input matrix 2!\n";
	newMatrix(matrixTwo, a);

	//Проверяем матрицу на равенство
	c = comparison(matrixOne, matrixTwo);

	//Если матрицы равны
	if (c) {
		reMatrix(matrixOne);

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				std::cout << matrixOne[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
}