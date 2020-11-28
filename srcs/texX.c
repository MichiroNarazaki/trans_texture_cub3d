#include "../includes/main.h"

void get_texX(t_game *game)
{
	//x coordinate on the texture//game->val.tex.xがおかしいのはここが原因
	//ピクセル座標 = [[[割合]]] * 全体
	game->val.tex.x = (int)(game->new_val.wallX * (double)(texWidth));
	//textureが反対になるのを直している
	if (game->new_val.side == 0 && game->val.ray_dir.x > 0)
	{//
		game->val.tex.x = texWidth - game->val.tex.x - 1;
	}
	if (game->new_val.side == 1 && game->val.ray_dir.x < 0)
		game->val.tex.x = texWidth - game->val.tex.x - 1;
}
