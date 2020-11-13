#include "../includes/main.h"

void get_wallX(t_game *game,int *side,double *perpWallDist,double *wallX)
{

	//calculate value of wallX
	if (side == 0)
		(*wallX) = game->val.pos.y + (*perpWallDist) * game->val.ray_dir.y;
	else
		(*wallX) = game->val.pos.x + (*perpWallDist) * game->val.ray_dir.x;
	(*wallX) -= floor(*wallX);
}
