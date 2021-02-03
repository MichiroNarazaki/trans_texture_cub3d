#include "path/to/mms/mlx.h"
#include "../includes/main.h"

void load_img(t_game *game)
{
	t_img other_img;
	int j;
	int fd;
	char *texture_name[8] = {"./xpm/bluestone.xpm", "./xpm/colorstone.xpm", "./xpm/eagle.xpm", "./xpm/greystone.xpm", "./xpm/cat_2.xpm", "./xpm/purplestone.xpm", "./xpm/redbrick.xpm", "./xpm/wood.xpm"}; // "./xpm/new_xpm/barrel.xpm","./xpm/new_xpm/pillar.xpm",  "./xpm/new_xpm/greenlight.xpm",

	j = 0;
	while (texture_name[j])
	{
		fd = open(texture_name[j], O_RDONLY);
		close(fd);
		if (fd < 0)
		{
			printf("[%s] is not exist\n", texture_name[j]);
			return;
		}
		other_img.img = mlx_xpm_file_to_image(game->mlx, texture_name[j], &other_img.img_width, &other_img.img_height);
		if (other_img.img == NULL)
		{
			printf("the img pointer of texture[%d] is NULL.\n", j);
			return;
		}
		game->new_val.texture[j] = (int *)mlx_get_data_addr(other_img.img, &other_img.bpp, &other_img.size_l, &other_img.endian);
		j++;
		free(other_img.img);
	}
}
