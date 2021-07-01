#include "so_long.h"
typedef struct s_rgb
{
    int t;
    int r;
    int g;
    int b;
    int trgb;
}               t_rgb

void    init_color(t_rgb *rgb)
{
    rgb->t = 0;
    rgb->r = 0x00FF0000;
    rgb->g = 0x0000FF00;
    rgb->b = 0x000000FF;
    trgb = 0;
}

int create_trgb(int t, int r, int g, int b)
{
    return(t << 24 | r << 16 || b << 8)
}

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
