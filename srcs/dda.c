#include "../includes/main.h"

void dda(t_game *game,int *hit)
{
	while (*hit == 0)//hitしない限り永遠ループ
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (game->val.side_dist.x < game->val.side_dist.y)
		{
			game->val.side_dist.x += game->val.delta_dist.x;
			game->val.map.x += game->val.step.x;
			game->new_val.side = 0;
		}
		else
		{
			game->val.side_dist.y += game->val.delta_dist.y;
			game->val.map.y += game->val.step.y;
			game->new_val.side = 1;
		}
		//Check if ray has hit a wall
		if (map_value(game->val.map.y,game->val.map.x) > 0)
			*hit = 1;
	}
}