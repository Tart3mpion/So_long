#include "so_long.h"

void	exit_clean(t_data *data)
{
	mlx_destroy_display(d->mlx);
	free(d->mlx);
}