  #ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

#define PINK 0xFF660033
#define GREEN 0x55225747
#define BLUE 0xFF0E203E
#define	ORANGE 0x55E1703E
#define	YELLOW	0xFFFCAC00
#define	BLACK 0xFF000000
#define	SIZE 40


/*KEYS*/
#define W 119
#define S 115
#define A 97
#define D 100
#define ESC 65307

/*TEXTURES*/
#define PLAYER "textures/player.xpm"
#define WALL "textures/wall.xpm"
#define EXIT "textures/exit.xpm"
#define COIN "textures/collectible.xpm"
#define FLOOR "textures/floor.xpm"

typedef struct	s_img
{
	void	*img;
	char	*data;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		c;
	int		l;
	int		heigth;
	int		width;
}				t_img;

typedef struct	s_txt
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
    int		height;
	int		x;
	int		y;
}				t_txt;

typedef struct	s_data
{
	char	p;
	char	c;
	char	e;
	char	**map;
	int		columns;
	int		row;
	int		x;
	int		y;
	void	*mlx;
	void	*mlx_win;
	int		step;
	//int		width;
	//t_rgb   rgb;
	t_img   img;
	t_txt	txt;
	t_txt	wall;
	t_txt	player;
	t_txt	coin;
	t_txt	floor;
	t_txt	exit;
}				t_data;

int		main(int ac, char **argv);

/*error management*/
void	get_file(t_data *data, int fd, int lvl);
int		check_format(char *str, char *ext);
int		check_infos(t_data *d);
int		check_inputs(char c, t_data *d);
int		is_map_valid(t_data *d);
void	print_error(t_data *d, int error);
int		is_rectangular(t_data *d);
int		is_closed(t_data *d);
int		check_column(t_data *d);
int		check_row(t_data *d);

/*init_images*/
int		init_image(t_data *d);
t_data	load_image(void *mlx, char *path);

/*init_textures*/
void 	init_text(t_data *d);
void 	init_wall(t_data *d);
void	init_player(t_data *d);
void	init_coin(t_data *d);
void	init_exit(t_data *d);
void	init_floor(t_data *d);

/*get_next-line*/
char	*stock_str(char *buf, char *str);
char	*stock_line(char *str, char **line);
int		get_next_line(int fd, char **line);

/*display*/
void	print_map(t_data *d);
//t_data	load_image(void *mlx, char *path);
int		draw_square(t_data *data, t_txt *img);
//void	background(t_img *img, int color);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
//void 	draw_decor(t_data *d);
//void 	draw_elements(t_data *d);
void	draw_floor(t_data *d);
void	draw_wall(t_data *d);
int		draw_elements(t_data *d);
int		get_color(t_txt *img, int x, int y);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);


/*actions*/
void	find_player(t_data *d);
void	move_player(t_data *d);
int		check_position(t_data *d, int x, int y);
void	move_right(t_data *d);
void	move_left(t_data *d);
void	move_backward(t_data *d);
void	move_forward(t_data *d);

/*hooks*/
int	ft_keyrelease(int keysym, t_data *data);
int	ft_keypress(int keysym, t_data *d);
int keyhook(int keycode, t_data *d);

/*exit_clean*/
int	exit_clean(t_data *data);
int free_map(t_data *d);
#endif