#include "so_long.h"

int	is_rectangular(t_data *d)
{
	int	c;
	int	l;

	l = 0;
	while (d->map[l])
	{
		c = 0;
		while (d->map[l][c])
		{
			c++;
		}
		if (c != d->columns)
			return (1);
		l++;
	}
	return (0);
}

int	is_closed(t_data *d)
{
	if (check_row(d))
		return (1);
	if (check_column(d))
		return (1);
	return (0);
}

int	check_row(t_data *d)
{
	int	l;
	int	c;

	l = 0;
	c = 0;
	while (d->map[l][c])
	{
		if (d->map[l][c] != '1')
			return (1);
		c++;
	}
	l = d->row - 1;
	c = 0;
	while (d->map[l][c])
	{	
		if (d->map[l][c] != '1')
			return (1);
		c++;
	}
	return (0);
}

int	check_column(t_data *d)
{
	int	l;
	int	c;

	l = 0;
	c = 0;
	while (d->map[l])
	{
		if (d->map[l][c] != '1')
			return (1);
		l++;
	}
	c = d->columns - 1;
	l = 0;
	while (l < d->row)
	{
		if (d->map[l][c] != '1')
			return (1);
		l++;
	}
	return (0);
}

void	print_error(t_data *d, int error)
{
	if (error == 1)
		write(1, "Error\nInfos are missing", 24);
	else if (error == 2)
		write(1, "Error\nWrong input", 18);
	else if (error == 3)
		write(1, "Error\nMap is invalid!", 20);
	else if (error == 4)
		write(1, "Error\nThere are too many players", 32);
	else if (error == 5)
		write(1, "Error\nyou need to add a map with a .ber extension", 50);
	else
		write(1, "Error\nThere is no file with that name", 37);
	if (d->map)
		free(d->map);
	exit(1);
}
