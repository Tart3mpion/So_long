#include "so_long.h"

void	init_floor(t_data *d)
{
	d->floor.img = mlx_xpm_file_to_image(d->mlx, FLOOR,
			&(d->floor.width), &(d->floor.height));
	d->floor.addr = mlx_get_data_addr(d->floor.img, &(d->floor.bpp),
			&(d->floor.line_length), &(d->floor.endian));
}

void	init_wall(t_data *d)
{
	d->wall.img = mlx_xpm_file_to_image(d->mlx, WALL,
			&(d->wall.width), &(d->wall.height));
	d->wall.addr = mlx_get_data_addr(d->wall.img, &(d->wall.bpp),
			&(d->wall.line_length), &(d->wall.endian));
}

void	init_player(t_data *d)
{
	d->player.img = mlx_xpm_file_to_image(d->mlx, PLAYER,
			&d->player.width, &d->player.height);
	d->player.addr = mlx_get_data_addr(d->player.img, &d->player.bpp,
			&d->player.line_length, &d->player.endian);
}

void	init_collectible(t_data *d)
{
	d->coin.img = mlx_xpm_file_to_image(d->mlx, COIN,
			&d->coin.width, &d->coin.height);
	d->coin.addr = mlx_get_data_addr(d->coin.img, &d->coin.bpp,
			&d->coin.line_length, &d->coin.endian);
}

void	init_exit(t_data *d)
{
	d->exit.img = mlx_xpm_file_to_image(d->mlx, EXIT,
			&(d->exit.width), &(d->exit.height));
	d->exit.addr = mlx_get_data_addr(d->exit.img, &(d->exit.bpp),
			&(d->exit.line_length), &(d->exit.endian));
}
