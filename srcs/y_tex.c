#include "../includes/main.h"

void y_tex(t_game *game, int x, int y)
{
	int y_cnt;
	int index_1;
	int index_2;

	for (y_cnt = game->new_val.y.start; y_cnt < game->new_val.y.end; y_cnt++)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		game->val.tex.y = (int)(game->new_val.texPos) & (texHeight - 1);
		(game->new_val.texPos) += game->new_val.step;
		index_1 = game->new_val.texNum;
		index_2 = texHeight * game->val.tex.y + game->val.tex.x;
		if (index_1 < 0 || 8 <= index_1 || index_2 < 0 ||
								texHeight * texWidth <= index_2)
		{
			printf("ERROR : The index is bad value in y_tex function\n");
			break;
		}
		//textureを配列ではなくした
		game->new_val.color = game->new_val.texture[texHeight * game->val.tex.y + game->val.tex.x];
		// game->new_val.color = game->new_val.texture[game->new_val.texNum][texHeight * game->val.tex.y + game->val.tex.x];
		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if (game->new_val.side == 1)
			game->new_val.color = (game->new_val.color >> 1) & 8355711;
		game->new_val.buffer[y][x] = game->new_val.color;
	}
}