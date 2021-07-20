#include "so_long.h"
void	find_player(t_data *d)
{
	d->x = 0;
	while(d->map[d->x])
	{
		d->y = 0;
		while(d->map[d->x][d->y])
		{
			if (d->map[d->x][d->y] == 'P')
				return;
			d->y++;
		}
		d->x++;
	}
	//printf("d->map[d->x][d->y] == %c\n", d->map[d->x][d->y]);
}
int check_position(t_data *d, int x, int y)
{
	
	if (d->map[x][y] == 'C')
		d->c--;
	if (d->map[x][y] == '1')
		return (1);
	if (d->map[x][y] == 'E')
	{
		if (d->c > 0)
		{
			write(1, "There are still collectibles to eat !!\r", 38);
			return(1);
		}
		else
		{
			//background(&d->img, BLACK);
			//mlx_put_image_to_window(d->mlx, d->mlx_win, d->img.img, 0, 0);
			write(1, "GG you ate it all", 17);
			//exit(0);
			exit_clean(d);
		}
	}
	d->map[x][y] ='P';
	write(1, &d->step, 3);
	return (0);
}
void move_forward(t_data *d)
{
	//puts("1");
	if (check_position(d, d->x - 1, d->y))
		return;
	//if (check_position(d, d->x - 1, d->y) == 2)
	d->map[d->x][d->y] = '0';
	//draw_square(d, &(d->exit));
	d->x -= 1;
	if (d->map[d->x - 1][d->y] != '1')
		d->step ++;
	ft_putnbr_fd(d->step, 1);
	write(1, "\r", 1);
}

void move_backward(t_data *d)
{
	if (check_position(d, d->x + 1, d->y))
		return;
	d->map[d->x][d->y] = '0';
	//draw_square(d, &(d->floor));
	d->x += 1;
	if (d->map[d->x - 1][d->y] != '1')
		d->step ++;
	ft_putnbr_fd(d->step, 1);
	write(1, "\r", 1);
}

void move_left(t_data *d)
{
	if (check_position(d, d->x, d->y - 1))
		return;
	d->map[d->x][d->y] = '0';
	d->y -= 1;
	if (d->map[d->x - 1][d->y] != '1')
		d->step ++;
	ft_putnbr_fd(d->step, 1);
	write(1, "\r", 1);
}

void move_right(t_data *d)
{
	if (check_position(d, d->x, d->y + 1))
		return;
	d->map[d->x][d->y] = '0';
	d->y += 1;
	if (d->map[d->x - 1][d->y] != '1')
		d->step ++;
	ft_putnbr_fd(d->step, 1);
	write(1, "\r", 1);
}