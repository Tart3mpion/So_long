#include "so_long.h"

void	exit_clean(t_data *d)
{
	
	mlx_destroy_image(d->mlx, d->img.img);
	mlx_destroy_window(d->mlx, d->mlx_win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	free(d);
	exit (0);
}