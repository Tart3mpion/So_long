#include "so_long.h"

int	init_image(t_data *d)
{
	//puts("hhhhhhh");
	//printf("d->step == %i\n", d->step);
	//memset(&d->img, 0, sizeof(d->img));
	d->img.heigth = d->row * SIZE;
	d->img.width = d->columns * SIZE;
	d->mlx = mlx_init();
	d->mlx_win = mlx_new_window(d->mlx, d->img.width, d->img.heigth, "Heloooooooo");
	d->img.img = mlx_new_image(d->mlx, d->img.width, d->img.heigth);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp, &d->img.line_length,
		&d->img.endian);
	init_text(d);
	background(&d->img, GREEN);
	draw_map(d);
	//mlx_loop_hook(d->mlx_win, mlx_put_image_to_window, d);
	//mlx_hook(d->mlx_win, KeyPress, KeyPressMask, &ft_keypress, d);
	//mlx_hook(d->mlx_win, KeyRelease, KeyReleaseMask, &ft_keyrelease, d);
	mlx_hook(d->mlx_win, 02, 1L<<0, ft_keypress, d);
	mlx_hook(d->mlx_win, KeyRelease, KeyReleaseMask, &ft_keyrelease, d);
	mlx_hook(d->mlx_win, 17, 1L<<17, exit_clean, d);
	//mlx_key_hook(d->mlx_win, keyhook, d);
	mlx_loop_hook(d->mlx_win, draw_map, d);
	mlx_loop(d->mlx);
	//exit_clean(d);
	return(1);
}

void init_text(t_data *d)
{
	//memset(&d->txt, 0, sizeof(t_txt));
	init_wall(d);
	//printf("&d->wall.width = %p\n", &d->wall.width);
	init_player(d);
	init_coin(d);
	//init_exit(d);
}

void init_wall(t_data *d)
{

	d->wall.img = mlx_xpm_file_to_image(d->mlx, WALL, &(d->wall.width), &(d->wall.height));
	d->wall.addr = mlx_get_data_addr(d->wall.img, &(d->wall.bpp),
		&(d->wall.line_length), &(d->wall.endian));
}

void init_player(t_data *d)
{
	d->player.img = mlx_xpm_file_to_image(d->mlx, PLAYER, &d->player.width, &d->player.height);
	d->player.addr = mlx_get_data_addr(d->player.img, &d->player.bpp,
		&d->player.line_length, &d->player.endian);
	
}

void init_coin(t_data *d)
{
	d->coin.img = mlx_xpm_file_to_image(d->mlx, COIN, &d->coin.width, &d->coin.height);
	d->coin.addr = mlx_get_data_addr(d->coin.img, &d->coin.bpp,
		&d->coin.line_length, &d->coin.endian);
}

void init_exit(t_data *d)
{
	d->exit.img = mlx_xpm_file_to_image(d->mlx, EXIT, &(d->exit.width), &(d->exit.height));
	d->exit.addr = mlx_get_data_addr(d->exit.img, &(d->exit.bpp),
		&(d->exit.line_length), &(d->exit.endian));
	
}



