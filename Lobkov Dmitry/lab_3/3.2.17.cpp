/*Черный квадрат. В матрице a(m, n), состоящей из нулей и единиц,
найти квадрат заданного размера (квадратную подматрицу),
состоящий целиком из нулей. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

bool CheckingForZero(int **mas, int i, int j, int counter) {	//проверка на нули предположительно подходящей матрицы
	for (int length = i + counter; i < length; i++) {
		for (int width = j + counter, k = j; k < width; k++) {
			if (mas[i][k] == 1) {
				return false;
			}
		}
	}

	return true;
}

int main(){
	int m = 30, n = 30, dimension, counter = 0;		//размерность матрицы, размерность матрицы для поиска, счетчик
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	printf("Enter the dimension of the required square: ");
	scanf_s("%d", &dimension);
	int** mas = new int*[m];
	for (int i = 0; i < m; i++) {
		mas[i] = new int[n];
	}
	srand(time(NULL));

	for (int i = 0; i < m; i++) {	//заполнение матрицы рандомным образом (0 и 1)
		for (int j = 0; j < n; j++) {
			mas[i][j] = rand() % 2;
		}
	}

	for (int i = 0; i < m; i++) {		//вывод матрицы
		for (int j = 0; j < n; j++) {
			printf("  %d", mas[i][j]);
		}

		printf("\n");
	}

	for (int i = 0; i < m - (dimension - 1); i++) {		//нахождение подматриц необходимой размерность и их вывод
		for (int j = 0; j < n - (dimension - 1); j++) {
			if (!mas[i][j] && !mas[i][j + 1]) {
				for (int k = j; mas[i][k] == 0 && k < n; k++) {
					counter++;
				}

				if (counter >= dimension && CheckingForZero(mas, i, j, dimension)) {
					printf("\n\nmas[%d][%d]\n", i, j);
					for (int k = 0; k < m; k++) {
						for (int l = 0; l < n; l++) {
							if (j == l && k >= i && k < i + dimension) {
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
								for (int colorCounter = 0; colorCounter < dimension; colorCounter++, l++) {
									printf("  %d", mas[k][l]);
								}

								l--;
								SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
							}
							else printf("  %d", mas[k][l]);
						}

						printf("\n");
					}
				}

				counter = 0;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		delete[] mas[i];
	}

	delete[] mas;

	return 0;
}