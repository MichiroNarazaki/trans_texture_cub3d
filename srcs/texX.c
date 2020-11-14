#include "../includes/main.h"

void get_texX(t_game *game, int *side)
{
		//x coordinate on the texture
		game->val.tex.x = (int)(game->new_val.wallX * (double)(texWidth));
		if (*side == 0 && game->val.ray_dir.x > 0)
			game->val.tex.x = texWidth - game->val.tex.x - 1;
		if (*side == 1 && game->val.ray_dir.y < 0)
			game->val.tex.x = texWidth - game->val.tex.x - 1;

}