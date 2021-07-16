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
	draw_elements(d);	
	return (0);
}

int	ft_keyrelease(int keysym, t_data *d)
{
	if (keysym == D || keysym == A || keysym == W || keysym == S)
	{
		ft_putnbr_fd(d->step, 1);
		write(1, "\r", 1);
	}
	return (0);
}

// int keyhook(int keycode, t_data *d)
// {
// 	d->step += 1;
	
// 	printf("\n%d\n", keycode);
// 	return(1);
// }