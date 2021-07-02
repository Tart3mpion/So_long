#include "so_long.h"

int		is_rectangular(t_data *infos)
{
	int c;
	int l;

	l = 0;
	while (infos->map[l])
    {
    	c = 0;
        while(infos->map[l][c])
		{
			c++;
		}
		if (c != infos->columns)
			return (1);
		l++;
    }
	return (0);
}

int		is_closed(t_data *infos)
{
	if (check_row(infos))
		return (1);
	if (check_column(infos))
		return (1);
	return (0);
}

int check_row(t_data *infos)
{
	int l;
	int c;

	l = 0;
	c = 0;
	while (infos->map[l][c])
	{
		if (infos->map[l][c] != '1')
			return (1);
		c++;
	}
	l = infos->row - 1;
	c = 0;
	while (infos->map[l][c])
	{	
		if (infos->map[l][c] != '1')
			return (1);
		c++;
	}
	return (0);
}

int check_column(t_data *infos)
{
	int l;
	int c;

	l = 0;
	c = 0;
	while (infos->map[l])
	{
		if (infos->map[l][c] != '1')	
			return (1);
		l++;
	}
	c = infos->columns - 1;
	l = 0;
	while (l < infos->row)
	{
		if (infos->map[l][c] != '1')
			return (1);
		l++;
	}
	return (0);
}

void print_error(t_data *infos, int error)
{
	if (error == 1)
		printf("Error\nmissing infos");
	else if (error == 2)
		printf("Error\nwrong character");
	else
		printf("Error\nmap is invalid!");
	free(infos->map);
	free(infos);
	exit(1);
}