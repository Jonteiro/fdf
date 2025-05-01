/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:20:40 by jsilveir          #+#    #+#             */
/*   Updated: 2025/05/01 14:40:11 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
		ft_memset(img, 0, sizeof(s_data));
	}
    exit(0);
    return (0);
}

int ft_is_esc(int keycode, void *param)
{
	s_data *img = (s_data *)param;
    // printf("key: %d\n", keycode);
    if(keycode == 65307) // ESC
        ft_killwindow(img);
    return(0);
}

void	ft_hooks(s_data *img)
{
	mlx_hook(img->mlx_win, 17, 0L, ft_killwindow, img);
	mlx_hook(img->mlx_win, 02, 1L<<0, ft_is_esc, img);
	
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


void    print_matrix(s_map *map){

	printf("map width = %d\n", map->width);
	printf("map height = %d\n", map->height);
    for(int i = 0; i < map->width; i++){
        for(int j = 0; j < map->height; j++){
            printf("matrix[%d][%d] = %f ", i, j, map->points[i][j].z);
        }   
    }
}


int main(int ac, char **av){

	if(ac != 2)
		ft_error("1 ARGUMENT PLEASE");
	s_data	data = {0};
	data.win_width = WIN_WIDTH;
    data.win_height = WIN_HEIGHT;
	int x = 0;
	int y = 0;
	
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "LeWindow James");
	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	
	if(av[1][0] == 'Z')
	{
		while (x < 1920)
		{
			while(y < 1080)
			{
				if(x == y)
				my_mlx_pixel_put(&data, x, y, 0x00ffffff);
				if(((x > 1000 && x < 1020) || (x > 1200 && x < 1220)) && (y > 200 && y < 400))
				my_mlx_pixel_put(&data, x, y, 0x0036CD36);
				if((x > 800) && (x <1400) && (y > 550) && (y <580))
				my_mlx_pixel_put(&data, x, y, 0x0036CD36);
				if((((x > 800) && (x < 830)) || (((x  > 1370) && (x < 1400)))) && ((y >= 530) && (y <= 550)))
				my_mlx_pixel_put(&data, x, y, 0x0036CD36);
				
				y++;
			}
			y = 0;
			x++;
		}
		dda_line_draw(&data, 0, 0, 500, 500);
		dda_line_draw(&data, 500, 0, 500, 500);
		dda_line_draw(&data, 0, 500, 500, 500);
		dda_line_draw(&data, 500, 500, 0, 500);
		dda_line_draw(&data, 600, 700, 400, 800);
		dda_line_draw(&data, 960, 540, 1920, 1080);
	}
	else {
		// int fd = open(av[1], O_RDONLY);
		// if (fd == -1)
       	// 	ft_error("Failed to open file");
		// char *line = get_next_line(fd);
		// ft_printf("First line: %s\n", line);
		// free(line);
		// close(fd);
		read_map(&data, av[1]);
		print_matrix(&data.map);
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	ft_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}

// void dda_line_draw(s_data *data, float x1, float y1, float x2, float y2)

/*
First you have to convert all your three-dimensional points (x,y,z) into two-dimensional points (x,y).


Once this is done, place the points on your screen (one point = one pixel).


Code an algorithm that connects the points together and draw all the pixels that connect them.
*/

// 1920 / 2 = 960
// 1080 / 2 = 540