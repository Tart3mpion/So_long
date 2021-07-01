/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:57:13 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/07/01 14:23:31 by ldes-cou@st      ###   ########.fr       */
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

char    **get_file(int fd, int lvl)
{
    char *line;
    char **infos;

    line = NULL;
    if (get_next_line(fd, &line) == 1)
        infos = get_file(fd, lvl + 1);
    else
    {
        infos = malloc(sizeof(char*) * (lvl + 2));
        infos[lvl + 1] = NULL;
        infos[lvl] = line;
        return (infos);
    }
    infos[lvl] = line;
    return (infos);
}

int check_infos(char **map, t_data *infos)
{
    int l;
    int c;

    l = 0;
    while (map[l])
    {
    c = 0;
        while(map[l][c])
        {
            check_inputs(map[l][c], map);
            if (map[l][c] == 'C')
                infos->c += 1;
            if (map[l][c] == 'P')
                infos->p += 1;
            if (map[l][c] == 'E')
                infos->e += 1;
            c++;
        }
        l++; 
    }
    infos->columns = c;
    infos->row = l;
    if (infos->c < 1 || infos->p < 1 || infos->e < 1)
        print_error(map, 1);
    return (0);
}

int check_inputs(char c, char **map)
{
    if (c != '0' && c != '1' && c != 'E' && c != 'P' && c != 'C')
        print_error(map, 2);
    return (0);
}
