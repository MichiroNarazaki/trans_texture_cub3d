#include "path/to/mms/mlx.h"
#include "../includes/main.h"

int g_key_flag = 1;

void g_key_0(void)
{
	g_key_flag = 0;
}
void g_key_1(void)
{
	g_key_flag = 1;
}
int is_g_key(void)
{
	return (g_key_flag);
}

int ft_close(t_game *game)
{
	exit(0);
}
void window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "mlx 42");
}

void img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

int main_loop(t_game *game)
{
	if (g_key_flag == 1) //g_key_flagって何?
	{
		//	描画する
		main_hook(game);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	}
	g_key_flag = 0;
	return (0);
}

int main()
{
	t_game game;

	window_init(&game);
	img_init(&game);
	load_img(&game);
	main_hook_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 1, &ft_close, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
