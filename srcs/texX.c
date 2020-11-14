#include "../includes/main.h"

void get_texX(t_game *game, int *side)
{
	//x coordinate on the texture//game->val.tex.xがおかしいのはここが原因
	//ピクセル座標 = [[[割合]]] * 全体
	game->val.tex.x = (int)(game->new_val.wallX * (double)(texWidth));
	//textureが反対になるのを直している
	if (*side == 0 && game->val.ray_dir.x > 0)
	{//
		// if (game->new_val.texNum == 6)
		// 	printf("game->val.tex.x : %d\n",game->val.tex.x);
		game->val.tex.x = texWidth - game->val.tex.x - 1;
	}
	if (*side == 1 && game->val.ray_dir.x < 0)
		game->val.tex.x = texWidth - game->val.tex.x - 1;
}

// void get_texX(t_game *game, int *side)
// {
// 		//x coordinate on the texture
// 		game->val.tex.x = (int)(game->new_val.wallX * (double)(texWidth));
// 		//textureが反対になるのを直している
// 		if (*side == 0 && game->val.ray_dir.x > 0)
// 			game->val.tex.x = texWidth - game->val.tex.x - 1;
// 		if (*side == 1 && game->val.ray_dir.x < 0)
// 			game->val.tex.x = texWidth - game->val.tex.x - 1;
// }