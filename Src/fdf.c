/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:36:03 by jsilveir          #+#    #+#             */
/*   Updated: 2025/04/21 13:46:46 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../fdf.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

int ft_killwindow(t_data *img){
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(0);	
}

int ft_is_esc( int keycode, t_data *img){
	printf("key: %d\n", keycode);
	if(keycode == 65307)
		ft_killwindow(img);
	return(0);
}

void	ft_hooks(t_data img){
	mlx_hook(img.mlx_win, 17, 0L, ft_killwindow, &img);
	mlx_hook(img.mlx_win, 02, 1L<<0, ft_is_esc, &img);
	
}


int main(void){

	t_data	img;
	int x = 0;
	int y = 0;
	
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "LeWindow James");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	while (x < 1920)
	{
		while(y < 1080)
		{
			// while (x < 256 && y < 256)
			// {
			// 	my_mlx_pixel_put(&img, x, y, (0x00000000 + 1000000 *));
			// }
			if(x == y)
				my_mlx_pixel_put(&img, x, y, 0x00ffffff);
			if(((x > 1000 && x < 1020) || (x > 1200 && x < 1220)) && (y > 200 && y < 400))
				my_mlx_pixel_put(&img, x, y, 0x0036CD36);
			if((x > 800) && (x <1400) && (y > 550) && (y <580))
				my_mlx_pixel_put(&img, x, y, 0x0036CD36);
			if((((x > 800) && (x < 830)) || (((x  > 1370) && (x < 1400)))) && ((y >= 530) && (y <= 550)))
				my_mlx_pixel_put(&img, x, y, 0x0036CD36);
			
			y++;
		}
		y = 0;
		x++;
	}
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	ft_hooks(img);
	mlx_loop(img.mlx);
}
