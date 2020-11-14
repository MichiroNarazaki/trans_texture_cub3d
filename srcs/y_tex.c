#include "../includes/main.h"

void y_tex(t_game *game, int x,t_start_end *y)
{
	int y_cnt;
	int index_1;
	int index_2;

	y_cnt = 0;
	while (y_cnt < y->start)
	{
		game->new_val.buffer[x][y_cnt] = CYAN;
		y_cnt++;
	}
	// printf("game->new_val.y.start : %d\n",game->new_val.y.start);
	while (y_cnt < y->end)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		game->val.tex.y = (int)(game->new_val.texPos) & (texHeight - 1);
		(game->new_val.texPos) += game->new_val.step;
		index_1 = game->new_val.texNum;
		index_2 = (texHeight * game->val.tex.y) + game->val.tex.x;
		if (index_1 < 0 || 8 <= index_1 || index_2 < 0 ||
			texHeight * texWidth <= index_2)
		{
			printf("ERROR : The index is bad value in y_tex function\n");
			break;
		}
		game->new_val.color = game->new_val.texture[index_1][index_2];
		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if (game->new_val.side == 1)
			game->new_val.color = (game->new_val.color >> 1) & 8355711;
		game->new_val.buffer[x][y_cnt] = game->new_val.color;
		y_cnt++;
	}
	while(y_cnt < HEIGHT)
	{
		game->new_val.buffer[x][y_cnt] = OLIVE;
		y_cnt++;
	}
}