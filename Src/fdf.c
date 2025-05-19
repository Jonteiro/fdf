/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:20:40 by jsilveir          #+#    #+#             */
/*   Updated: 2025/05/14 15:42:01 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_killwindow(void *param)
{
	s_data	*img;

	img = (s_data *)param;
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

int	ft_is_esc(int keycode, void *param)
{
	s_data	*img;

	img = (s_data *)param;
	if (keycode == 65307)
		ft_killwindow(img);
	return (0);
}

void	ft_hooks(s_data *img)
{
	mlx_hook(img->mlx_win, 17, 0L, ft_killwindow, img);
	mlx_hook(img->mlx_win, 02, 1L << 0, ft_is_esc, img);
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

int	main(int ac, char **av)
{
	s_data	data;

	if (ac != 2)
		ft_error("1 ARGUMENT PLEASE");
	data.win_width = WIN_WIDTH;
	data.win_height = WIN_HEIGHT;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIN_WIDTH,
			WIN_HEIGHT, "LeWindow James");
	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	read_map(&data, av[1]);
	isometric(&data.map);
	draw_edges(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	ft_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
// ft_memset(&data, 0, sizeof(data));
