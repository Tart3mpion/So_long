#include "so_long.h"

int		is_rectangular(char **map, t_data *infos)
{
	int c;
	int l;

	l = 0;
	while (map[l])
    {
    	c = 0;
        while(map[l][c++])
		printf("infos->columns ==%i\n", infos->columns);
		printf("c == %i\n", c);
		if (c != infos->columns)
			return (1);
        l++; 
    }
	return (0);
}

int		is_closed(char **map, t_data *infos)
{
	if (check_row(map, infos) != 0)
		return (1);
	if (check_column(map, infos) != 0)
		return (1);
	return (0);
}

int check_row(char **map, t_data *infos)
{
	int l;
	int c;

	l = 0;
	c = 0;
	while (map[l][c])
	{
		printf("row ==> %c\n", map[l][c]);
		if (map[l][c] != '1')
			return (1);
		c++;
	}
	l = infos->row;
	c = 0;
	while (map[l][c])
	{
		printf("lastrow ==>%c", map[l][c]);
		if (map[l][c] != '1')/*last_*/
			return (1);
		c++;
	}
	return (0);
}

int check_column(char **map, t_data *infos)
{
	int l;
	int c;

	l = 0;
	c = 0;
	while (l < (infos->row - 1))
	{
		if (map[l][c] != '1')
		printf("column ==>%c", map[l][c]);
			return (1);
		l++;
	}
	c = infos->columns;
	while (l < (infos->row - 1))
	{
		if (map[l][c] != '1')/*last_row*/
		printf("lastcolumn ==>%c", map[l][c]);
			return (1);
		l++;
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
	else
		printf("Error\nmap is invalid!");
	free(map);
	exit(1);
}