#include "so_long.h"

int		is_rectangular(char **map, t_data *infos)
{
	int c;
	int l;

	l = 0;
	while (map[l])
    {
    c = 0;
        while(map[l][c])
		{
			c++;
			printf("c ==>%i\n", c);
		}
		if (c != infos->columns)
			return (1);
        l++; 
    }
	return (0);
}

int		is_closed(char **map)
{
	if (check_first_row(map))
		return (1);
	if (check_first_column(map))
		return (1);
	return (0);
}

int check_first_row(char **map)
{
	int l;
	int c;

	l = 0;
	c = 0;
	while (map[l][c])
	{
		if (map[l][c] != 1)
			return (1);
		c++;
	}
	while (map[l])
	{
		if (map[l][c] != 1)/*last_*/
			return (1);
		l++;
	}
	return (0);
}

int check_first_column(char **map)
{
	int l;
	int c;

	l = 0;
	c = 0;
	while (map[l])
	{
		if (map[l][c] != 1)
			return (1);
		l++;
	}
	while (map[l][c])
	{
		if (map[l][c] != 1)/*last_row*/
			return (1);
		c++;
	}
	return (0);
}

void print_error(char **map, int error)
{
	//printf("ici\n");
	if (error == 1)
		printf("Error\nmissing infos");
	else if (error == 2)
		printf("Error\nwrong character");
	free(map);
	exit(1);
}