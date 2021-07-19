#include "so_long.h"

int	exit_clean(t_data *d)
{
	if (d->mlx)
	{
		mlx_destroy_image(d->mlx, d->img.img);
		mlx_destroy_window(d->mlx, d->mlx_win);
		mlx_destroy_display(d->mlx);
		//free(d->mlx);
	}
	if (d->map)
		free_map(d);
	// if  (d)
	// 	free(d);
	exit(1);
	return(1);
}

int free_map(t_data *d)
{
	int i;

	i = 0;
	while (d->map[i])
	{
		free(d->map[i]);
		d->map[i] = NULL;
		i++;
	}
	free(d->map);
	return (0);
}