#include "so_long.h"

int	get_color(t_txt *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->line_length + (x * \
						(img->bpp / 8)))));
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	draw_square(t_data *d, t_txt *img)
{
	int	c;
	int	l;

	l = d->img.l;
	c = d->img.c;
	img->y = 0;
	while (d->img.l < SIZE + l)
	{
		d->img.c = c;
		img->x = 0;
		while (d->img.c < SIZE + c)
		{
			if (get_color(img, img->x, img->y) != (int)BLACK)
				my_mlx_pixel_put(&d->img, d->img.c, d->img.l,
					get_color(img, img->x, img->y));
			d->img.c++;
			img->x++;
		}
		d->img.l++;
		img->y++;
	}
	return (0);
}
