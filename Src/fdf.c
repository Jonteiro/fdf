/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:20:40 by jsilveir          #+#    #+#             */
/*   Updated: 2025/04/28 21:53:21 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"


void	my_mlx_pixel_put(s_data *data, int x, int y, int color)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

int ft_killwindow(void *param)
{
    s_data *img = (s_data *)param;
    
    if (img)
    {
        if (img->img && img->mlx)
            mlx_destroy_image(img->mlx, img->img);
        if (img->mlx_win && img->mlx)
            mlx_destroy_window(img->mlx, img->mlx_win);
        if (img->mlx)
        {
            mlx_destroy_display(img->mlx);
            free(img->mlx);
        }
    }
    exit(0);
    return (0);
}
/*
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(0);

*/


int ft_is_esc(int keycode, void *param)
{
	s_data *img = (s_data *)param;
    printf("key: %d\n", keycode);
    if(keycode == 65307) // ESC
        ft_killwindow(img);
    return(0);
}

	// printf("key: %d\n", keycode);
	// if(keycode == 65307)
	// 	ft_killwindow(img);
	// return(0);

/* void	isometric(t_map *map)
{
	map->ang[X] = 30;
	map->ang[Y] = 330;
	map->ang[Z] = 45;
} */

void	ft_hooks(s_data *img)
{
	mlx_hook(img->mlx_win, 17, 0L, ft_killwindow, &img);
	mlx_hook(img->mlx_win, 02, 1L<<0, ft_is_esc, &img);
	
}

int	is_number(char *str)
{
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str != ' ' && *str != '\t' && *str != '\n')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void read_map(s_data *data, char *filename)
{
	int	fd;
	char *line;
	char **big;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Cant read map");
	line = get_next_line(fd);
	if (!line)
		ft_error("Map is empty");
	big = ft_split(line, ' ');
	while (big[data->map.width])
	{
		free(big[data->map.width]);
		data->map.width++;
	}
	while (line)
	{
		free(line);
		data->map.height++;
		line = get_next_line(fd);
	}
	free(line);
	free(big);
	close (fd);
}


int main(void){

	s_data	img = {0};
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
	ft_hooks(&img);
	mlx_loop(img.mlx);
	return (0);
}

/*
First you have to convert all your three-dimensional points (x,y,z) into two-dimensional points (x,y).


Once this is done, place the points on your screen (one point = one pixel).


Code an algorithm that connects the points together and draw all the pixels that connect them.
*/