#include "../includes/main.h"

void main_hook_init(t_game *game)
{

	game->val.dir.x = -1; //initial direction vector
	game->val.dir.y = 0;
	game->val.pos.x = 5; //x and y start position
	game->val.pos.y = 5;
	game->val.plane.x = 0.0; //the 2d raycaster version of camera plane
	game->val.plane.y = 0.66;
}

void main_hook(t_game *game)
{
	int w = WIDTH;
	int h = HEIGHT;
	int x;
	double perpWallDist;
	int hit;  //was there a wall hit?
	int side; //was a NS or a EW wall hit?
	double cameraX;
	double frameTime;
	int lineHeight;
	t_start_end y;

	/*new-------------(start)*/
	// double wallX; //where exactly the wall was hit
	/*new-------------(end)*/

	x = 0;
	for (x = 0; x < w; x++)
	{
		//線の位置と方向の計算
		cameraX = -(2 * x / (double)w - 1); //x-coordinate in camera space
		game->val.ray_dir.x = game->val.dir.x + game->val.plane.x * cameraX;
		game->val.ray_dir.y = game->val.dir.y + game->val.plane.y * cameraX;
		//which box of the map we're in
		game->val.map.x = (int)(game->val.pos.x);
		game->val.map.y = (int)(game->val.pos.y);

		//ＸＹ側から次のＸＹ側までの長さ
		game->val.delta_dist.x = (game->val.ray_dir.y == 0) ? 0 : ((game->val.ray_dir.x == 0) ? 1 : fabs(1 / game->val.ray_dir.x));
		game->val.delta_dist.y = (game->val.ray_dir.x == 0) ? 0 : ((game->val.ray_dir.y == 0) ? 1 : fabs(1 / game->val.ray_dir.y));
		hit = 0;
		//calculate step and initial sideDist
		cal_and_init(&game->val);
		//perform DDA
		dda(&game->val, &side, &hit);
		if (side == 0)
			perpWallDist = (game->val.map.x - game->val.pos.x + (1 - game->val.step.x) / 2) / game->val.ray_dir.x;
		else
			perpWallDist = (game->val.map.y - game->val.pos.y + (1 - game->val.step.y) / 2) / game->val.ray_dir.y;

		/***************************************************************/
		//Calculate height of line to draw on screen
		lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		y.start = -lineHeight / 2 + h / 2;
		if (y.start < 0)
			y.start = 0;
		y.end = lineHeight / 2 + h / 2;
		if (y.end >= h)
			y.end = h - 1;
		/*=============================================*/
		/*↑same as trans_src/main_hook.c*/
		/*=============================================*/
		//texturing calculations
		game->new_val.texNum = map_value(game->val.map.y, game->val.map.x) - 1; //1 subtracted from it so that texture 0 can be used!

		get_wallX(game, &side, &perpWallDist);

		get_texX(game, &side);
		game->new_val.step = 1.0 * texHeight / lineHeight;
		game->new_val.texPos = (y.start - h / 2 + lineHeight / 2) * game->new_val.step;
		y_tex(game, x, &y);
	}

	frameTime = 0.1;
	//speed modifiers
	game->val.move_speed = frameTime * 5.0; //the constant value is in squares/second
	game->val.rot_speed = frameTime * 3.0;	//the constant value is in radians/second

	buff(game, w, h);
}