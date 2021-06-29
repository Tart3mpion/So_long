#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
    char p;
    char c;
    char e;
    int columns;
    int row;
}               t_data;


int     main(int ac, char **argv);

/*error management*/
char    **get_file(int fd, int lvl);
int     check_format(char *str, char *ext);
int     check_infos(char **map, t_data *infos);
int     check_inputs(char c, char **map);
int     is_map_valid(char **map, t_data *infos);
void    print_error(char **map, int error);
int		is_rectangular(char **map, t_data *infos);
int     is_closed(char **map);
int     check_first_column(char **map);
int     check_first_row(char **map);

/*get_next-line*/
char	*stock_str(char *buf, char *str);
char	*stock_line(char *str, char **line);
int     get_next_line(int fd, char **line);

#endif