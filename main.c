#include <stdio.h>
#include <stdlib.h>

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char player = 'X';

void print_board()
{
	printf(
		"     |     |     \n"
		"  %c  |  %c  |  %c  \n"
		"-----|-----|-----\n"
		"  %c  |  %c  |  %c  \n"
		"-----|-----|-----\n"
		"  %c  |  %c  |  %c  \n"
		"     |     |     \n"
		"\n",
		board[0], board[1], board[2],
		board[3], board[4], board[5],
		board[6], board[7], board[8]
	);
}

int has_won()
{
	return ((board[0] & board[1] & board[2]) == player ||
		(board[3] & board[4] & board[5]) == player ||
		(board[6] & board[7] & board[8]) == player ||
		(board[0] & board[3] & board[6]) == player ||
		(board[1] & board[4] & board[7]) == player ||
		(board[2] & board[5] & board[8]) == player ||
		(board[0] & board[4] & board[8]) == player ||
		(board[2] & board[4] & board[6]) == player);
}

void player_move()
{
	char input[80];
	int choice;

	while (1) {
		printf("Player %c: Input a number: ", player);

		if(!fgets(input, 80, stdin)) {
			fprintf(stderr, "Unexpected EOF\n");
			exit(EXIT_FAILURE);
		}
		choice = atoi(input);

		if (choice < 1 || choice > 9 || board[choice-1] != ' ') {
			continue;
		}
		else {
			board[choice-1] = player;
			break;
		}
	}
}

int main()
{
	int turn;
	for (turn = 0; turn < 9; turn++) {
		print_board();
		player_move();
		if (has_won()) {
			print_board();
			printf("%c has won this game! Congratulations!\n", player);
			return 0;
		}
		player = player == 'X' ? 'O' : 'X';
	}
	printf("The game was a tie!\n");
	return 0;
}
