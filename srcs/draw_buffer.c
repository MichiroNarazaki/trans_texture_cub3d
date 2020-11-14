#include "../includes/main.h"

void draw_buffer(t_game *game)
{
	int x;
	int y;
	int index;

	y = 1;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			index = x + (y - 1) * WIDTH;
			if (index < 0 || WIDTH * HEIGHT <= index)
			{
				printf("Error : The index is bad value in draw_buffer function. \n");
				printf("Error : index == %d \n", index);
				break;
			}
			if (x < 0 || WIDTH <= x || y < 0 || HEIGHT <= y)
			{
				printf("Error : The index is bad value in draw_buffer function. \n");
				printf("Error : x  == %d y  == %d \n", x,y);
				break;
			}
			game->img.data[index] = game->new_val.buffer[x][y];
			x++;
		}
		y++;
	}
}
