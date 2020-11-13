#include "../includes/main.h"
#include "../../cub_git/mms/mlx.h"

void load_img(t_game *game)
{
	t_img other_img;
	int j;
	char *texture_name[8] = {"../trans_texture/xpm/bluestone.xpm", "../trans_texture/xpm/colorstone.xpm", "../trans_texture/xpm/eagle.xpm", "../trans_texture/xpm/greystone.xpm", "../trans_texture/xpm/mossy.xpm", "../trans_texture/xpm/purplestone.xpm", "../trans_texture/xpm/redbrick.xpm", "../trans_texture/xpm/wood.xpm"}; // "../trans_texture/xpm/barrel.xpm","../trans_texture/xpm/pillar.xpm",  "../trans_texture/xpm/greenlight.xpm",

	j = 0;
	while (texture_name[j])
	{
		other_img.img = mlx_xpm_file_to_image(game->mlx, texture_name[j], &other_img.img_width, &other_img.img_height);
		game->new_val.texture[j] = (int *)mlx_get_data_addr(other_img.img, &other_img.bpp, &other_img.size_l, &other_img.endian);
		j++;
	}
}