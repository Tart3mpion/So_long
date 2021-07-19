#include "so_long.h"

int main(int ac, char **argv)
{
    int fd;
    t_data d;

    if ((ac < 2) || (check_format(argv[1], ".ber")))
        printf("Error\nyou need to add a map with a .ber extension");
    fd = open(argv[1], O_RDONLY);
    memset(&d, 0, sizeof(t_data));
    get_file(&d, fd, 0);
    printf("infos->columns == %d\n", d.columns);
	printf("infos->row == %d\n", d.row);
    //print_map(&infos);
    is_map_valid(&d);
    init_image(&d);
    close(fd);
    if (d.map)
        free(d.map);
    
    return (0);
}

int is_map_valid(t_data *infos)
{
    check_infos(infos);
    //printf("is_closed(map, infos) %i\n", is_closed(map, infos));
    if (is_rectangular(infos) || is_closed(infos))
        print_error(infos, 3);
    return (0);
}