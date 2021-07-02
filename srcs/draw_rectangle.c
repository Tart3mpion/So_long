#include "so_long.h"

int	init_map(t_data *d)
{
	memset(&d->img, 0, sizeof(d->img));
	d->img.heigth = d->row * SIZE;
	d->img.width = d->columns * SIZE;
	d->mlx = mlx_init();
	d->mlx_win = mlx_new_window(d->mlx, d->img.width, d->img.heigth, "Heloooooooo");
	d->img.img = mlx_new_image(d->mlx, d->img.width, d->img.heigth);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bits_per_pixel, &d->img.line_length,
		&d->img.endian);
	return(0);
}
void	draw_map(t_data *d)
{
	int c;
	int l;

	l = 0;
	init_map(d);
	while (d->map[l])
	{
		d->img.c = 0;
		c = 0;
		while (d->map[l][c])
		{
			printf("c ==> %i\n", c);
			printf("d->img.c==> %i\n", d->img.c);
			if (d->map[l][c] == '1')
			{
				draw_square(d, PINK);
				//printf("d->map[l][c] ==> %c\n", d->map[l][c]);
			}
			else if (d->map[l][c] == '0')
				draw_square(d, GREEN);
			else if (d->map[l][c] == 'P')
				draw_square(d, BLUE);
			else if (d->map[l][c] == 'C')
				draw_square(d, YELLOW);
			else
				draw_square(d, ORANGE);
			c++;
			d->img.l = l * SIZE;
		}
		l++;
		d->img.l = SIZE * l;
		printf("img.l ==> %i\n", d->img.l);
		
	}
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img.img, 0, 0);
	mlx_loop(d->mlx);
}
int draw_square(t_data *d, int color)
{
	
	int c;
	int	l;

	l = d->img.l;
	c = d->img.c;
	while(d->img.l < SIZE + l)
	{
		d->img.c = c;
		while (d->img.c < SIZE + c)
		{
			my_mlx_pixel_put(&d->img, d->img.c, d->img.l, color);
			d->img.c++;
		}
		d->img.l++;
	}
	return(0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}