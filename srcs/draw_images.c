/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:04:08 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/08/03 15:10:58 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_putnbr_fd(d->step, 0);
	write(0, "\r", 1);
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
