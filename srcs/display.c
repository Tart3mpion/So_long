#include "so_long.h"

int	draw_map(t_data *d)
{
	int c;
	int l;

	l = 0;
	
	//write(1, "step", 5);
	//printf("d->step == %i\n", d->step);
	//background(&d->img, GREEN);
	find_player(d);
	// printf("d->map[d->x][d->y] == %c\n", d->map[d->x][d->y]);
	// printf("coordonnees player ==> %i-%i\n", d->x, d->y);
	while (d->map[l])
	{
		d->img.c = 0;

		c = 0;
		while (d->map[l][c])
		{
			printf("img->line_length ==%i\n", d->wall.line_length);
			if (d->map[l][c] == '1')
				draw_square(d, get_pixel(&d->wall, d->txt.x, d->txt.y));	//printf("d->map[l][c] ==> %c\n", d->map[l][c]);
			else if (d->map[l][c] == '0')
				draw_square(d, get_pixel(&d->floor, d->txt.x, d->txt.y);
			else if (d->map[l][c] == 'P')
				draw_square(d, get_pixel(&d->player, d->txt.x, d->txt.y));
			else if (d->map[l][c] == 'C')
				draw_square(d, get_pixel(&d->coin, d->txt.x, d->txt.y));
			//else
				//draw_square(d, ORANGE);
			c++;
			d->img.l = l * SIZE;
		}
		l++;
		d->img.l = SIZE * l;
	}
	
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img.img, 0, 0);
	return(1);
}

// void background(t_data *data)
// {

// }
void	background(t_img *img, int color)
{
	int	i;
	int	j;
	i = 0;
	while (i < img->heigth)
	{
		j = 0;
		while (j < img->width)
			img_pix_put(img, j++, i, color);//get_color(floor)
		++i;
	}
}

int	get_pixel(t_txt *img, int x, int y)
{
	printf("img->line_length ==%i\n", img->line_length);
	return (*(int *)(img->addr + (y * img->line_length + (x * \
						(img->bpp / 8)))));

}


int draw_square(t_data *d, int x, int y) //faire une fonction draw_text
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
			d->txt.x++;
		}
		d->img.l++;
		d->txt.y++;
	}
	return(0);
}
// int get_color()

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


