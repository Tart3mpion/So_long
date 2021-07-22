#include "so_long.h"
void	find_player(t_data *d)
{
	d->x = 0;
	while (d->map[d->x])
	{
		d->y = 0;
		while (d->map[d->x][d->y])
		{
			if (d->map[d->x][d->y] == 'P')
				return ;
			d->y++;
		}
		d->x++;
	}
}

int	check_position(t_data *d, int x, int y)
{
	if (d->map[x][y] == 'C')
		d->c--;
	if (d->map[x][y] == '1')
		return (1);
	if (d->map[x][y] == 'E')
	{
		if (d->c > 0)
			return (1);
		else
		{
			draw_elements(d);
			mlx_string_put(d->mlx, d->mlx_win, 200, 200, YELLOW, "CONGRATULATIONS");
			exit_clean(d);//chercher comment ouvrir la porte ==>initialiser la textures porte ouverte
		}
	}
	d->map[x][y] = 'P';
	return (0);
}
