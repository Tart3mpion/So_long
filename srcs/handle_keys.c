/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:04:26 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/08/03 15:04:27 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
}

void	move_forward(t_data *d)
{
	if (check_position(d, d->x - 1, d->y))
		return ;
	d->map[d->x][d->y] = '0';
	d->x -= 1;
	d->step ++;
}

void	move_backward(t_data *d)
{
	if (check_position(d, d->x + 1, d->y))
		return ;
	d->map[d->x][d->y] = '0';
	d->x += 1;
	d->step ++;
}

void	move_left(t_data *d)
{
	if (check_position(d, d->x, d->y - 1))
		return ;
	d->map[d->x][d->y] = '0';
	d->y -= 1;
	d->step ++;
}

void	move_right(t_data *d)
{
	if (check_position(d, d->x, d->y + 1))
		return ;
	d->map[d->x][d->y] = '0';
	d->y += 1;
	d->step ++;
}
