/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:57:13 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/07/13 15:33:53 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		//printf("data->map[lvl] == %s\n", data->map[lvl]);
	}
	data->map[lvl] = line;
}
void	print_map(t_data *infos)
{
	
	for (int i = 0; infos->map[i]; i++)
    {
        printf("\n%d - %s\n", i, infos->map[i]);
    }
}

int check_infos(t_data *infos)
{
	int l;
	int c;

	l = 0;
	while (infos->map[l])
	{
	c = 0;
		while(infos->map[l][c])
		{
			check_inputs(infos->map[l][c], infos);
			if (infos->map[l][c] == 'C')
				infos->c += 1;
			if (infos->map[l][c] == 'P')
				infos->p += 1;
			if (infos->map[l][c] == 'E')
				infos->e += 1;
			c++;
		}
		l++; 
	}
	infos->columns = c;
	infos->row = l;
	if (infos->c < 1 || infos->p < 1 || infos->e < 1)
		print_error(infos, 1);
	return (0);
}

int check_inputs(char c, t_data *infos)
{
	if (c != '0' && c != '1' && c != 'E' && c != 'P' && c != 'C')
		print_error(infos, 2);
	return (0);
}
