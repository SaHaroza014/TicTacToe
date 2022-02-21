#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 100


int main()
{
	int row = 0, col = 0; //retci i stupci za dimenzije arraya
	char board[N][N];
	char bzvz;//za unos znaka 'x' izmedju, kad se unosi broj redaka i stupaca
	char first_sign;//unos tko prvi igra, igrac X ili igrac O
	int num_win;//unos znamenke, koja govori koliko je potrebno povezati istih znakova za pobjedu, pr. 3x X u stupcu
				//pobjedjuje se samo ako se spoje okomito stupci. Ne gleda se vodoravno i okomito

	while ((row < 3 || row > 10) || (col < 3 || col > 10)) {
		scanf(" %d%c%d", &row, &bzvz, &col);
		if ((row < 3 || row > 10) || (col < 3 || col > 10)) {
			printf("Nedozvoljena dimenzija polja!\n");
		}
	}

	int turns = row * col; //koliko imamo poteza prije nego se cijeli array ispuni

	scanf(" %d", &num_win); //koliko je znakova potrebno spojiti u stupcu (okomito) za pobjedu
	scanf(" %c", &first_sign); //koji znak/igrac je prvi na potezu

	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= col; ++j) {
			board[i][j] = '-';
		}
	}

	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= col; ++j) {
			printf(" %2c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	if (first_sign == 'X') {
		int k = 0;
		while (k < turns) {
			k++;
			int a = 0, b = 0;
			scanf(" %d %d", &a, &b);
			board[a][b] = 'X';
			scanf(" %d %d", &a, &b);
			board[a][b] = 'O';
			for (int i = 1; i <= row; i++) {
				for (int j = 1; j <= col; j++) {
					printf("%2c", board[i][j]);
				}
				printf("\n");
			} printf("\n");
			/*if ((board[1][1] == 'X' && board[2][1] == 'X' && board[3][1] == 'X') || (board[1][2] == 'X' && board[2][2] == 'X' && board[3][3] == 'X') || (board[1][3] == 'X' && board[2][3] == 'X' && board[3][3] == 'X')) {
				printf("Pobjednik je igrac X");
				k = turns;//zaustavlja poteze da se ne odvijaju nepotrebno
			} *///< Kako raspisati uvjet za pobjednika kada je matrica vecih dimenzija, primjerice 8x8. Ide li uvjet kroz zasebnu petlju?
			int counterX = 0;
			int counterO = 0;
			for (int j = 1; j <= (col+1); ++j) {
				if (counterX == num_win) {
					k = turns;
					printf("Pobjednik je igrac X!\n");
					counterX = 0;
					j = (col + 1) + 1;
				}
				if (counterO == num_win) {
					k = turns;
					printf("Pobjednik je igrac O!\n");
					counterO = 0;
				}
				else {
					counterX = 0;
					counterO = 0;
				}
				for (int i = 1; i <= row; ++i) {
					if (board[i][j] == 'X') {
						counterX++;
					}
					if (board[i][j] == 'O') {
						counterO++;
					}
				}
			}
		}
	}
	else {
		int k = 0;
		while (k < turns) {
			k++;
			int a = 0, b = 0;
			scanf(" %d %d", &a, &b);
			board[a][b] = 'O';
			scanf(" %d %d", &a, &b);
			board[a][b] = 'X';
			for (int i = 1; i <= row; i++) {
				for (int j = 1; j <= col; j++) {
					printf("%2c", board[i][j]);
				}
				printf("\n");
			} printf("\n");
			int counterO = 0;
			int counterX = 0;
			for (int j = 1; j <= (col+1); ++j) {
				if (counterO == num_win) {
					printf("Pobjednik je igrac O!\n");
					k = turns;
					counterO = 0;
					j = (col + 1) + 1;
				}
				if (counterX == num_win) {
					printf("Pobjednik je igrac X!\n");
					k = turns;
					counterX = 0;
				}
				else {
					counterO = 0;
					counterX = 0;
				} 
				for (int i = 1; i <= row; ++i) {
					if (board[i][j] == 'X') {
						counterX++;
					}
					if (board[i][j] == 'O') {
						counterO++;
					}
				}
			}
		}
	}


	return 0;
}
