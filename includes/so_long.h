#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"

#define PINK 0x55660033
#define GREEN 0x55225747
#define BLUE 0x550E203E
#define	ORANGE 0x55E1703E
#define	YELLOW	0x00FCAC00
#define	SIZE 50

// # define WIDTH (d->columns *1000)
// # define HEIGHT (d->row *1000)

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

/*get_next-line*/
char	*stock_str(char *buf, char *str);
char	*stock_line(char *str, char **line);
int		get_next_line(int fd, char **line);

/*display*/
int		draw_square(t_data *data, int color);
void	render_background(t_img *img, int color);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
int		init_map(t_data *d);
void	draw_map(t_data *data);

#endif