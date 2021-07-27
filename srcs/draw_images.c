#include "so_long.h"

int	draw_elements(t_data *d)
{
	char	*print_step;

	print_step = ft_itoa(d->step);
	find_player(d);
	draw_decor(d);
	draw_player(d);
	draw_flower(d);
	draw_exit(d);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img.img, 0, 0);
	mlx_string_put(d->mlx, d->mlx_win, 20, 20, PINK, print_step);
	free(print_step);
	return (1);
}

void	draw_decor(t_data *d)
{
	int	l;
	int	c;

	l = 0;
	d->img.l = 0;
	while (d->map[l])
	{
		d->img.c = 0;
		c = 0;
		while (d->map[l][c])
		{
			if (d->map[l][c] == '1')
				draw_square(d, &(d->wall));
			else if (d->map[l][c] == '0' || d->map[l][c] == 'C' ||
					d->map[l][c] == 'P')
				draw_square(d, &(d->floor));
			else
				d->img.c += SIZE;
			c++;
			d->img.l = l * SIZE;
		}
		l++;
		d->img.l = SIZE * l;
	}
}

void	draw_player(t_data *d)
{
	int	l;
	int	c;

	l = 0;
	d->img.l = 0;
	while (d->map[l])
	{
		d->img.c = 0;
		c = 0;
		while (d->map[l][c])
		{
			if (d->map[l][c] == 'P')
				draw_square(d, &(d->player));
			else
				d->img.c += SIZE;
			c++;
			d->img.l = l * SIZE;
		}
		l++;
		d->img.l = SIZE * l;
	}
}

void	draw_flower(t_data *d)
{
	int	l;
	int	c;

	l = 0;
	d->img.l = 0;
	while (d->map[l])
	{
		d->img.c = 0;
		c = 0;
		while (d->map[l][c])
		{
			if (d->map[l][c] == 'C')
				draw_square(d, &(d->coin));
			else
				d->img.c += SIZE;
			c++;
			d->img.l = l * SIZE;
		}
		l++;
		d->img.l = SIZE * l;
	}
}

void	draw_exit(t_data *d)
{
	int	l;
	int	c;

	l = 0;
	d->img.l = 0;
	while (d->map[l])
	{
		d->img.c = 0;
		c = 0;
		while (d->map[l][c])
		{
			if (d->map[l][c] == 'E')
				draw_square(d, &(d->exit));
			else
				d->img.c += SIZE;
			c++;
			d->img.l = l * SIZE;
		}
		l++;
		d->img.l = SIZE * l;
	}
}
