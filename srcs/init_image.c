#include "so_long.h"

int	init_image(t_data *d)
{
	memset(&d->img, 0, sizeof(d->img));
	d->img.heigth = d->row * SIZE;
	d->img.width = d->columns * SIZE;
	d->mlx = mlx_init();
	d->mlx_win = mlx_new_window(d->mlx, d->img.width, d->img.heigth, "Heloooooooo");
	d->img.img = mlx_new_image(d->mlx, d->img.width, d->img.heigth);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp, &d->img.line_length,
		&d->img.endian);
	return(0);
}

t_data	load_image(void *mlx, char *path)
{
	t_data	data;

	data.img = mlx_xpm_file_to_image(mlx, path, &(data.win.width), &(data.win.height));
	if (!data.img)
		return (data);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	return (data);
}

t_data init_wall(t_data *d)
{
	d->txt.wall = (t_txt *)malloc(sizeof(t_txt));
	if (!(d->txt->wall))
	{
		ft_putstr_fd("Error.\nAllocation error\n", 2);
		//free
	}
	d->txt->wall.img = load_image(d->mlx, )
}