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
    is_map_valid(&d);
    init_image(&d);
    close(fd);
    if (d.map)
        free(d.map);
    
    return (0);
}

int is_map_valid(t_data *d)
{
    check_infos(d);
    if (is_rectangular(d) || is_closed(d))
        print_error(d, 3);
    if (d->c < 1 || d->p < 1 || d->e < 1)
		print_error(d, 1);
    return (0);
}