#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
//place the example code below here:

#define texWidth 64
#define texHeight 64

#define KEY_ESC 65307
#define KEY_W 126 //上
#define KEY_A 123 //左
#define KEY_S 125 //下
#define KEY_D 124 //右

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17 //Exit program key code


#define	BLACK		0x00000000
#define	RED			0x00FF0000
#define	GREEN		0x0000FF00
#define	BLUE		0x000000FF
#define	CYAN		0x0000FFFF
#define	MAFENTA		0x00FF00FF
#define	YELLOW		0x00FFFF00
#define	WHITE		0x00FFFFFF
#define	GRAY		0x00808080
#define	GREY		0x00C0C0C0
#define	MAROON		0x00800000
#define	DARKGREEN	0x00008000
#define	NAVY		0x00000080
#define	TEAL		0x00008080
#define	PURPLE		0x00800080
#define	OLIVE		0x00808000
#define TILE_SIZE 32
#define COLS 24
#define ROWS 24
#define WIDTH COLS *TILE_SIZE
#define HEIGHT ROWS *TILE_SIZE


typedef struct s_int_xy
{
	int x;
	int y;
} t_int_xy;

typedef struct s_xy
{
	double x;
	double y;
} t_xy;

typedef struct s_start_end
{
	int start;
	int end;
} t_start_end;

typedef struct s_new_val
{
	int texNum;
	double texPos;
	double step;
	int side;//was a NS or a EW wall hit?
	int *texture[8];
	int buffer[WIDTH][HEIGHT];
	int color;
	double wallX;
}t_new_val;

typedef struct s_val
{
	t_xy pos;
	t_xy dir;
	t_xy plane;
	t_xy ray_dir;
	t_xy side_dist;			//現在位置から次のx側またはy側までの線の長さ
	t_xy delta_dist;
	t_int_xy step;	//what direction to step in x or y-direction (either +1 or -1)
	t_int_xy map;
	double move_speed;
	double rot_speed;
	t_int_xy tex;
	double wallX;
} t_val;

typedef struct s_img
{
	int img_width;
	int img_height;
	void *img;
	int *data; //imgの本体
	int size_l;
	int bpp;
	int endian;
} t_img;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_img img;
	t_val val;
	t_new_val new_val;
} t_game;

void cal_and_init(t_val *val);
int ret_color(t_val *val);
void dda(t_game *game,int *hit);
int deal_key(int key_code, t_game *game);
void main_hook(t_game *game);
int	map_value(int y, int x);
void ver_line(t_img *img, int x, t_start_end *y, int color);
void g_key_0(void);
void g_key_1(void);
int is_g_key(void);
void	main_hook_init(t_game *game);
/*new↓*/
void buff(t_game *game,int w,int h);
void draw_buffer(t_game *game);
void get_texX(t_game *game);
void get_wallX(t_game *game,double *perpWallDist);
void y_tex(t_game *game,int x,t_start_end *y);
void load_img(t_game *game);


