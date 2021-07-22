#include "so_long.h"

int	init_image(t_data *d)
{
	d->img.heigth = d->row * SIZE;
	d->img.width = d->columns * SIZE;
	d->mlx = mlx_init();
	d->mlx_win = mlx_new_window(d->mlx, d->img.width,
			d->img.heigth, "Prismarine palace");
	d->img.img = mlx_new_image(d->mlx, d->img.width,
			d->img.heigth);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp,
			&d->img.line_length, &d->img.endian);
	init_text(d);
	draw_elements(d);
	mlx_hook(d->mlx_win, 02, 1L << 0, ft_keypress, d);
	mlx_hook(d->mlx_win, 17, 1L << 17, exit_clean, d);
	mlx_loop_hook(d->mlx_win, draw_elements, d);
	mlx_loop(d->mlx);
	return (1);
}

void	init_text(t_data *d)
{
	init_floor(d);
	init_wall(d);
	init_player(d);
	init_collectible(d);
	init_exit(d);
}
