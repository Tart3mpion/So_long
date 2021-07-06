#include "so_long.h"

int	keypress(int keysym, t_data *d)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(d->mlx, d->mlx_win);
	
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	printf("data: %p\n", data);
	return (0);
}