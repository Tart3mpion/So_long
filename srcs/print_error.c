#include "so_long.h"

int		is_rectangular(t_data *d)
{
	int c;
	int l;

	l = 0;
	while (d->map[l])
    {
    	c = 0;
        while(d->map[l][c])
		{
			c++;
		}
		if (c != d->columns)
			return (1);
		l++;
    }
	return (0);
}

int		is_closed(t_data *d)
{
	if (check_row(d))
		return (1);
	if (check_column(d))
		return (1);
	return (0);
}

int check_row(t_data *d)
{
	int l;
	int c;

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

int check_column(t_data *d)
{
	int l;
	int c;

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

void print_error(t_data *d, int error)
{
	if (error == 1)
		printf("Error\nmissing infos");
	else if (error == 2)
		printf("Error\nwrong character");
	else
		printf("Error\nmap is invalid!");
	free(d->map);
	//free(d);
	exit(1);
}