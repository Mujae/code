#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 3

void initializeBoard(int board[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			board[i][j] = 0;
		}
	}
}

void displayBoard(int board[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0) {
				printf(" ");
			}
			else if (board[i][j] == 1) {
				printf("O");
			}
			else if (board[i][j] == -1) {
				printf("X");
			}
			printf("|");
		}
		printf("\n------\n");
	}
}

int checkFinished(int board[SIZE][SIZE])
{
	int result = 0;
	for (int i = 0; i < SIZE; i++)
	{
		int sum_row = 0;
		int sum_col = 0;
		int sum_diag = 0;
		for (int j = 0; j < SIZE; j++)
		{
			sum_row += board[i][j];
			sum_col += board[j][i];
			if (i == j) sum_diag += board[i][j];
		}
		if (sum_row == 3 || sum_col == 3 || sum_diag == 3) result = 1;
		else if (sum_row == -3 || sum_col == -3 || sum_diag == -3) result = 2;
	}

	if (result == 1) {
		printf("1번 승!\n");
	}
	else if (result == 2) {
		printf("2번 승!\n");
	}
	else if (result == 3) {
		printf("무승부!\n");
	}

	return result;
}

int checkValid(int board[SIZE][SIZE], int i, int j)
{
	if (board[i][j] != 0)
		return 0;
	return 1;
}

int main(void)
{
	int board[SIZE][SIZE];
	initializeBoard(board);	
	int turn = 1;

	while (1)
	{	
		while (1)
		{
			displayBoard(board);
			printf("%d번 차례다 어디에 둘래?\n", turn);
			int i, j;
			scanf("%d %d", &i, &j);
			if (checkValid(board, i, j)) {
				board[i][j] = turn == 1 ? 1:-1;
				break;
			}
			else {
				printf("거기 안됨");
			} 
		}

		if (checkFinished(board) > 0) {
			printf("계속하시겠습니까 ? 0 or 1\n");
			int keepgoing = 0;
			scanf("%d", &keepgoing);
			if (keepgoing == 1) {
				initializeBoard(board);
				turn = 1;
			}
			else {
				break;
			}
		}
		else {
			turn = turn == 1 ? 2 : 1;
			continue;
		}
	}
	return 0;
}