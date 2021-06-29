#include "so_long.h"

int main(int ac, char **argv)
{
    char **map;
    int fd;
    t_data infos;

    fd = 1;
    if ((ac < 2) || (check_format(argv[1], ".ber")))
        printf("Error\nyou need to add a map with a .ber extension");
    fd = open(argv[1], O_RDONLY);
    map = get_file(fd, 0);
    memset(&infos, 0, sizeof(infos));
    
    for (int i = 0; map[i]; i++)
    {
        printf("\n%d - %s\n", i, map[i]);
    }
   is_map_valid(map, &infos);
    
    /*open window*/
    /*draw minimap*/
    /*play*/
    /*add sprites*/
    /*configure exit*/

    return (0);
}

int is_map_valid(char **map, t_data *infos)
{
    check_infos(map, infos);
    if (is_rectangular(map, infos) || is_closed(map))
        print_error(map, 3);
    return (0);
}