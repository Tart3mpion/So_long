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
			write(1, "GG you ate it all", 17);
			exit_clean(d);
		}
	}
	d->map[x][y] = 'P';
	return (0);
}
