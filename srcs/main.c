#include "so_long.h"

int main(int ac, char **argv)
{
    int fd;
    t_data infos;

    if ((ac < 2) || (check_format(argv[1], ".ber")))
        printf("Error\nyou need to add a map with a .ber extension");
    fd = open(argv[1], O_RDONLY);
    memset(&infos, 0, sizeof(t_data));
    printf("infos->columns == %d\n", infos.columns);
	printf("infos->row == %d\n", infos.row);
    get_file(&infos, fd, 0);
    print_map(&infos);
    is_map_valid(&infos);
    init_image(&infos);
    printf("player coordonnees == %d%d\n", infos.x, infos.y);
    close(fd);
    free(infos.map);
    printf("you made %d steps", infos.step);
    //faire une fonction qui free tout
    /*faire une fonction qui pqrse les textures en fonctions de la carte*/
    /*draw floor && wall*/
    /*draw_player*/
    /*play*/
    /*add sprites*/
    /*configure exit*/
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