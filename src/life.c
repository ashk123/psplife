// Actual GameOfLife Algorithm Code

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "rect.h"
#include "var.h"
#include "life.h"

char playGround[ROW][COL];

void UpdateLifeMap() {
	srand(time(NULL));
	for (int x = 0; x < ROW; x++)
		for (int y = 0; y < COL; y++)
			playGround[x][y] = rand() < RAND_MAX / 10 ? 1 : 0;
}


void Evolution() {
	char new_play_ground[COL][ROW];
	for (int x = 0; x < ROW; x++) {
		for (int y = 0; y < COL; y++) {
			int lives = 0;
			for (int xd = x - 1; xd <= x + 1; xd++) {
				for (int yd = y - 1; yd <= y + 1; yd++) {
					if (playGround[(xd + ROW) % ROW][(yd + COL) % COL]) {
						lives++;
						//drawRect(x, y, 5, 5, 0xFF123487);
					}
				}
			}
			if (playGround[x][y]) lives--;
			new_play_ground[x][y] = (lives==3 || (lives==2 && playGround[x][y]));
		}
	}
	for (int x = 0; x < ROW; x++) 
		for (int y = 0; y < COL; y++)
				playGround[x][y] = new_play_ground[x][y];
}

void
draw(void) {
	int position = 0;
	//drawRect(0, 0, 50, 50);
	//drawRect(50, 0, 50, 50);
	//drawRect(100, 0, 50, 50);

	/* Make a frame for life's board*/
	for (int c = 7; c <= ROW; c++) {
		for (int c2 = 2; c2 <= COL; c2++) {
			if ((c2 == 2) || 
				(c == 7) ||
				(c == ROW) ||
				(c2 == COL)){
				drawRect(c * 7, c2 * 7, 5, 5, 0x123786F3);
			}
		}
	}
	for (int x = 8; x < ROW; x++){
		for (int y = 3; y < COL; y++){
			if (playGround[x][y] == 1) {
				drawRect(x * 7, y * 7, 5, 5, WHITE);
			} else {
				drawRect(x * 7, y * 7, 5, 5, BLACK);
			}
	 	}
	}
	
}
