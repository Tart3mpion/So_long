/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:57:13 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/07/02 15:24:01 by ldes-cou@st      ###   ########.fr       */
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

	// data = (t_data *)malloc(sizeof(t_data));
	// if (data == NULL)
	// 	exit (0);
	
	line = NULL;
	if (get_next_line(fd, &line) == 1)
		get_file(data, fd, lvl + 1);
	else
	{
		//printf("");
	//puts("2");
		data->map = malloc(sizeof(char*) * (lvl + 2));
		data->map[lvl + 1] = NULL;
		data->map[lvl] = line;
	}
	data->map[lvl] = line;
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
