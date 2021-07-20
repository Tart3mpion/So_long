#include "so_long.h"

int     check_format(char *str, char *ext)
{
	while(*str != '.')
		str++;
	if (ft_strcmp(str, ext) == 0)
		return (0);
	return (1);
}

void	get_file(t_data *data, int fd, int lvl)
{
	char *line;
	
	line = NULL;
	if (get_next_line(fd, &line) == 1)
		get_file(data, fd, lvl + 1);
	else
	{
		data->map = malloc(sizeof(char*) * (lvl + 2));
		data->map[lvl + 1] = NULL;
		data->map[lvl] = line;
	}
	data->map[lvl] = line;
}

int check_infos(t_data *d)
{
	int l;
	int c;

	l = 0;
	while (d->map[l])
	{
	c = 0;
		while(d->map[l][c])
		{
			check_inputs(d->map[l][c], d);
			if (d->map[l][c] == 'C')
				d->c += 1;
			if (d->map[l][c] == 'P')
				d->p += 1;
			if (d->map[l][c] == 'E')
				d->e += 1;
			c++;
		}
		l++; 
	}
	d->columns = c;
	d->row = l;
	return (0);
}

int check_inputs(char c, t_data *d)
{
	if (c != '0' && c != '1' && c != 'E' && c != 'P' && c != 'C')
		print_error(d, 2);
	return (0);
}
