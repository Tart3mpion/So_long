#include "so_long.h"


void	draw_map(t_data *d)
{
	int c;
	int l;

	l = 0;
	init_map(d);
	background(&d->img, GREEN);
	while (d->map[l])
	{
		d->img.c = 0;
		c = 0;
		while (d->map[l][c])
		{
			if (d->map[l][c] == '1')
				draw_square(d, PINK);	//printf("d->map[l][c] ==> %c\n", d->map[l][c]);
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
	}
	render_frame(d);
	exit_clean(d);
}
void render_frame(t_data *data)
{
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img.img, 0, 0);
	mlx_loop_hook(d->mlx_win, &mlx_put_image_to_window, &d);
	mlx_hook(d->mlx_win, KeyPress, KeyPressMask, &keypress, &d);
	mlx_hook(d->mlx_win, KeyRelease, KeyReleaseMask, &keyrelease, &d);
	mlx_loop(d->mlx);
}

void	render_background(t_img *img, int color)

{
	int	i;
	int	j;
	i = 0;
	while (i < img->heigth)
	{
		j = 0;
		while (j < img->width)
			img_pix_put(img, j++, i, color);
		++i;
	}
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
			img_pix_put(&d->img, d->img.c, d->img.l, color);
			d->img.c++;
		}
		d->img.l++;
	}
	return(0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)

			*pixel++ = (color >> i) & 0xFF;
		else

			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}


