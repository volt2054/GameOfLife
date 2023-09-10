#include <iostream>

const int WIDTH = 3;
const int HEIGHT = 3;

int countNeighbours(bool game[WIDTH+2][HEIGHT+2], int x, int y) {
	
	int neighbours = 0;
	
/*	
	if i had square 1,1 id have to check 0,0 0,1 0,2 1,0 1,2 2,0 2,1 2,2
	where the first number = x and second = y
	x-1 from y-1 to y+1
	x y-1 y+1
	x+1 y-1 y+1
*/

	if (game[x - 1][y - 1]) neighbours += 1;
	if (game[x - 1][y]) neighbours += 1;
	if (game[x - 1][y + 1]) neighbours += 1;
	if (game[x][y - 1]) neighbours += 1;
	if (game[x][y + 1]) neighbours += 1;
	if (game[x + 1][y - 1]) neighbours += 1;
	if (game[x + 1][y]) neighbours += 1;
	if (game[x + 1][y + 1]) neighbours += 1;

	return neighbours;
}

void printFrame(bool game[WIDTH+2][HEIGHT+2]) {
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			std::cout << game[x][y] << " ";
		}
		std::cout << "\n";
	}
}

void nextTick(bool game[WIDTH+2][HEIGHT+2]) {

	bool future[WIDTH][HEIGHT];

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			int neighbours = countNeighbours(game, i, j);
			if (neighbours == 2 && game[i][j]) future[i][j] = true;
			else {
				future[i][j] = false;
			}
			if (neighbours == 3) future[i][j] = true;
			else {
				future[i][j] = false;
			}
		}
	}

	for (int a = 0; a < WIDTH; a++) {
		for (int b = 0; b < HEIGHT; b++) {
			game[a][b] = future[a][b];
		}
	}
}

int main() {

	const int TICKS = 100;

	bool game[WIDTH+2][HEIGHT+2];

	for (int i = 0; i < WIDTH+2; i++) {
		for (int j = 0; j < HEIGHT+2; j++) {
			game[i][j] = false;
		}
	}

	printFrame(game);
	std::cin.get();

	game[0][0] = true;
	game[0][1] = true;
	game[1][0] = true;
	game[1][1] = true;

	
	printFrame(game);
	std::cin.get();

	nextTick(game);

	printFrame(game);
	std::cin.get();


	std::cin.get();

}

