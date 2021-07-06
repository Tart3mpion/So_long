#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

#define PINK 0x55660033
#define GREEN 0x55225747
#define BLUE 0x550E203E
#define	ORANGE 0x55E1703E
#define	YELLOW	0x00FCAC00
#define	SIZE 100

/*KEYS*/
#define W 119
#define S 115
#define A 65361
#define D 65363

/*TEXTURES*/
#define PLAYER "textures/player.xpm"
#define WALL "textures/wall.xpm"
#define EXIT "textures/exit.xpm"
#define COIN "textures/collectible.xpm"


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
}				t_txt;

typedef struct	s_data
{
	char	p;
	char	c;
	char	e;
	char	**map;
	int		columns;
	int		row;
	void	*mlx;
	void	*mlx_win;
	//int		width;
	//t_rgb   rgb;
	t_img   img;
	t_txt	wall;
	t_txt	player;
	t_txt	coin;
	t_txt	exit;
}				t_data;

int		main(int ac, char **argv);

/*error management*/
void	get_file(t_data *data, int fd, int lvl);
int		check_format(char *str, char *ext);
int		check_infos(t_data *infos);
int		check_inputs(char c, t_data *infos);
int		is_map_valid(t_data *infos);
void	print_error(t_data *infos, int error);
int		is_rectangular(t_data *infos);
int		is_closed(t_data *infos);
int		check_column(t_data *infos);
int		check_row(t_data *infos);

/*init_images*/
int		init_image(t_data *d);
t_data	load_image(void *mlx, char *path);



/*init_textures*/
void 	init_text(t_data *d);
void 	init_wall(t_data *d);
void	init_player(t_data *d);
void	init_coin(t_data *d);
void	init_exit(t_data *d);

/*get_next-line*/
char	*stock_str(char *buf, char *str);
char	*stock_line(char *str, char **line);
int		get_next_line(int fd, char **line);

/*display*/
t_data	load_image(void *mlx, char *path);
int		draw_square(t_data *data, int color);
void	background(t_img *img, int color);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	img_pix_put(t_img *img, int x, int y, int color);

void	draw_map(t_data *data);
void	render_frame(t_data *data);
void	so_long_loop(t_data *d);

/*hooks*/
int	keyrelease(int keysym, void *data);
int	keypress(int keysym, t_data *d);

/*exit_clean*/
void	exit_clean(t_data *data);
#endif