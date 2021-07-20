#include "so_long.h"

int	ft_keypress(int keysym, t_data *d)
{
	if (keysym == XK_Escape)
		exit_clean(d);
	if (keysym == W)
		move_forward(d);
	if (keysym == S)
		move_backward(d);
	if (keysym == A)
		move_left(d);
	if (keysym == D)
		move_right(d);
	draw_elements(d);	
	write(1, "@@@@@@@@@@@", 10);
	return (0);
}
