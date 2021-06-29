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
    int i;
    int j;

    i = 0;
    j = 0;
    //infos->p = 1;
    //if (map[1][3])
    //printf ("j == %s\n", map[j]);
    printf ("map == %c\n", map[1][3]);
    return (0);
}
/*is_there_other_char*/
/*is_there_enough_infos*/
/*is_map_rectangular*/
/*is_map_closed*/
