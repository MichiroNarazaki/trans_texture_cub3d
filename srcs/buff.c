#include "../includes/main.h"

void buff(t_game *game, int w, int h)
{

	draw_buffer(game);
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (x < 0 || WIDTH <= x || y < 0 || HEIGHT <= y)
			{
				printf("ERROR : The index is bad value in buff function\n");
				break;
			}
			game->new_val.buffer[y][x] = 0; //clear the buffer instead of cls()
		}
	}
}