#include "so_long.h"

int draw_rectangle(t_img *img)
{
	void	*mlx;
    void	*mlx_win;
    int     width;
    int     heigth;

    width = ((HEIGHT / 3) * 2);
    heigth = ((HEIGHT / 3) * 2); 
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
    img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
	    &img->endian);
    img->c = HEIGHT / 3;
    img->l = HEIGHT / 3;
    while (img->c < width)
    {
        my_mlx_pixel_put(img, img->c, img->l, 0x00FFFF000);
        img->c++;
    }
    while(img->l < heigth)
    {
        my_mlx_pixel_put(img, img->c, img->l, 0x00FFFF00);
        img->l++;
    }
    while (img->c > HEIGHT / 3)
    {
        my_mlx_pixel_put(img, img->c, img->l, 0x00FFFF00);
        img->c--;
    }
    while(img->l > HEIGHT / 3)
    {
        my_mlx_pixel_put(img, img->c, img->l, 0x00FFFF00);
        img->l--;
    }
    while(img->l < heigth)
    {
        my_mlx_pixel_put(img, img->c, img->l, 0x000000FF);
        img->l++;
        img->c++;
    }
    img->c = img->c = HEIGHT / 3;
    while(img->c < heigth)
    {
        my_mlx_pixel_put(img, img->c, img->l, 0x000000FF);
        img->l--;
        img->c++;
    }

    mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
    mlx_loop(mlx);
    return(0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}