#include "so_long.h"
void	find_player(t_data *d)
{
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
			background(&d->img, BLACK);
			//exit_clean(d);
			write(1, "GG you ate it all", 17);
			exit(0);
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
	d->x -= 1;
	d->step ++;
}

void move_backward(t_data *d)
{
	if (check_position(d, d->x + 1, d->y))
		return;
	d->map[d->x][d->y] = '0';
	d->x += 1;
	d->step ++;
}

void move_left(t_data *d)
{
	if (check_position(d, d->x, d->y - 1))
		return;
	d->map[d->x][d->y] = '0';
	d->y -= 1;
	d->step ++;
}

void move_right(t_data *d)
{
	if (check_position(d, d->x, d->y + 1))
		return;
	d->map[d->x][d->y] = '0';
	d->y += 1;
	d->step ++;
}