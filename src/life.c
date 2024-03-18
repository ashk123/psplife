// Actual GameOfLife Algorithm Code

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "rect.h"
#include "colors.h"
#include "life.h"

char playGround[512][512];

void UpdateLifeMap()
{
	srand(time(NULL));
	for (int x = 0; x < ROW; x++)
		for (int y = 0; y < COL; y++)
			playGround[x][y] = rand() < RAND_MAX / 10 ? 1 : 0;
}

void Evolution()
{
	char new_play_ground[512][512];
	for (int x = 0; x < ROW; x++)
	{
		for (int y = 0; y < COL; y++)
		{
			int lives = 0;
			for (int xd = x - 1; xd <= x + 1; xd++)
			{
				for (int yd = y - 1; yd <= y + 1; yd++)
				{
					if (playGround[(xd + ROW) % ROW][(yd + COL) % COL])
					{
						lives++;
						// drawRect(x, y, 5, 5, 0xFF123487);
					}
				}
			}
			if (playGround[x][y])
				lives--;
			new_play_ground[x][y] = (lives == 3 || (lives == 2 && playGround[x][y]));
		}
	}
	for (int x = 0; x < ROW; x++)
		for (int y = 0; y < COL; y++)
			playGround[x][y] = new_play_ground[x][y];
}

void draw(void)
{
	int position = 0;
	// drawRect(0, 0, 50, 50);
	// drawRect(50, 0, 50, 50);
	// drawRect(100, 0, 50, 50);

	/* Make a frame for life's board*/
	for (int c = 0; c <= ROW; c++)
	{
		for (int c2 = 0; c2 <= COL; c2++)
		{
			if ((c2 == 0) ||
				(c == 0) ||
				(c == ROW) ||
				(c2 == COL))
			{
				drawRect(c * (CSIZE + CPAD), c2 * (CSIZE + CPAD), CSIZE, CSIZE, 0x123786F3);
			}
		}
	}
	// drawRect(ROW - 1 * 7, COL * 7, CSIZE, CSIZE, 0x123786F3);
	for (int x = 1; x < ROW; x++)
	{
		for (int y = 1; y < COL; y++)
		{
			if (playGround[x][y] == 1)
			{
				drawRect(x * (CSIZE + CPAD), y * (CSIZE + CPAD), CSIZE, CSIZE, WHITE);
			}
			else
			{
				drawRect(x * (CSIZE + CPAD), y * (CSIZE + CPAD), CSIZE, CSIZE, BLACK);
			}
		}
	}
}
