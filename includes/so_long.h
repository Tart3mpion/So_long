#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		c;
	int		l;

}				t_img;

typedef struct	s_data
{
	char p;
	char c;
	char e;
	int columns;
	int row;
	//t_rgb   rgb;
	t_img   img;
}				t_data;




int		main(int ac, char **argv);

/*error management*/
char	**get_file(int fd, int lvl);
int		check_format(char *str, char *ext);
int		check_infos(char **map, t_data *infos);
int		check_inputs(char c, char **map);
int		is_map_valid(char **map, t_data *infos);
void	print_error(char **map, int error);
int		is_rectangular(char **map, t_data *infos);
int		is_closed(char **map, t_data *infos);
int		check_column(char **map, t_data *infos);
int		check_row(char **map, t_data *infos);

/*get_next-line*/
char	*stock_str(char *buf, char *str);
char	*stock_line(char *str, char **line);
int		get_next_line(int fd, char **line);

/*display*/
int		draw_rectangle(t_img *img);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif