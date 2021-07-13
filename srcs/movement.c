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
	printf("d->map[d->x][d->y] == %c\n", d->map[d->x][d->y]);
}
int check_position(t_data *d, int x, int y)
{
	if (d->map[x][y] == 'C')
	{
		d->map[x][y] = '0';
		d->c--;
		return (2);
	}
	if (d->map[x][y] == '1')
		return (1);
	if (d->map[x][y] == 'E')
	{
		if (d->c > 0)
		{
			printf("There are still collectibles to eat !!");
			return(1);
		}
		else
		{
			d->map[x][y] = 'P';
			exit_clean(d);
			printf("GG you ate it all");
		}
	}
	else
		d->map[x][y] ='P';
	return (0);
}
void move_forward(t_data *d)
{
	puts("1");
	if (check_position(d, d->x - 1, d->y))
			return;
	d->map[d->x][d->y] = '0';
	d->x -= 1;
}

void move_backward(t_data *d)
{
	if (check_position(d, d->x + 1, d->y))
		return;
	d->map[d->x][d->y] = '0';
	d->x += 1;
}

void move_left(t_data *d)
{
	if (check_position(d, d->x, d->y - 1))
		return;
	d->map[d->x][d->y] = '0';
	d->y -= 1;
}

void move_right(t_data *d)
{
	if (check_position(d, d->x, d->y + 1))
		return;
	d->map[d->x][d->y] = '0';
	d->y += 1;
}