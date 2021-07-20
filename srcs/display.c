#include "so_long.h"

int	draw_elements(t_data *d)
{
	int c;
	int l;

	l = 0;
	draw_floor(d);
	while (d->map[l])
	{
		d->img.c = 0;
		c = 0;
		while (d->map[l][c])
		{
			if (d->map[l][c] == 'P')
				draw_square(d, &(d->player));
			else if (d->map[l][c] == 'C')
				draw_square(d, &(d->coin));
			else if (d->map[l][c] == 'E')
				draw_square(d, &(d->exit));
			else
				d->img.c += SIZE;
			c++;
			d->img.l = l * SIZE;
		}
		l++;
		d->img.l = SIZE * l;
	}
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img.img, 0, 0);
	return(1);
}

void	draw_floor(t_data *d)
{
	int l;
	int c;

	l = 0;
	d->img.l = 0;
	while (d->map[l])
	{
		d->img.c = 0;
		c = 0;
		while (d->map[l][c])
		{
			if (d->map[l][c] == '1')
				draw_square(d, &(d->wall));
			else if (d->map[l][c] == '0' || d->map[l][c] == 'C' || d->map[l][c] == 'P')
				draw_square(d, &(d->floor));
			else
				d->img.c += SIZE;
			c++;
			d->img.l = l * SIZE;
		}
		l++;
		d->img.l = SIZE * l;
	}
}

int	get_color(t_txt *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->line_length + (x * \
						(img->bpp / 8)))));
}


int draw_square(t_data *d, t_txt *img)
{
	int c;
	int	l;

	l = d->img.l;
	c = d->img.c;

	img->y = 0;
	while(d->img.l < SIZE + l)
	{
		d->img.c = c;
		img->x = 0;
		while (d->img.c < SIZE + c)
		{
			if (get_color(img, img->x, img->y) != (int)BLACK)
				my_mlx_pixel_put(&d->img, d->img.c, d->img.l, get_color(img, img->x, img->y));
			d->img.c++;
			img->x++;
		}
		d->img.l++;
		img->y++;	
	}
	return(0);
}


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
