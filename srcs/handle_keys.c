#include "so_long.h"

int	ft_keypress(int keysym, t_data *d)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(d->mlx, d->mlx_win);
	if (keysym == W)
		move_forward(d);
	if (keysym == S)
		move_backward(d);
	if (keysym == A)
		move_left(d);
	if (keysym == D)
		move_right(d);
	//printf("Keypress: %d\n", keysym);
	//fga .
	ft_putchar_fd(d->step, 1);
	draw_map(d);
	return (0);
}

int	ft_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	printf("data: %p\n", data);
	return (0);
}

int keyhook(int keycode, t_data *d)
{
	d->step += 1;
	printf("hello %d\n", keycode);
	return(1);
}