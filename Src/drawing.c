/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:36:46 by jsilveir          #+#    #+#             */
/*   Updated: 2025/05/01 14:36:46 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

static void	draw_pixels(t_data *data, float x, float y, t_linestruct *dd)
{
	int	i;

	i = -1;
	while (++i <= dd->steps)
	{
		if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_height)
			my_mlx_pixel_put(data, round(x), round(y), 0x00ffffff);
		x += dd->x_inc;
		y += dd->y_inc;
	}
}

void	dda_line_draw(t_data *data, t_point start, t_point end)
{
	t_linestruct	dd;
	float		current_x;
	float		current_y;

	if (end.x - start.x == 0 && end.y - start.y == 0)
	{
		my_mlx_pixel_put(data, round(start.x), round(start.y), 0x00ffffff);
		return ;
	}
	dd.steps = fabs(end.x - start.x);
	if (fabs(end.y - start.y) > dd.steps)
		dd.steps = fabs(end.y - start.y);
	dd.x_inc = (end.x - start.x) / dd.steps;
	dd.y_inc = (end.y - start.y) / dd.steps;
	current_x = start.x;
	current_y = start.y;
	draw_pixels(data, current_x, current_y, &dd);
}

static void	draw_connections(t_data *data, int y, int x)
{
	t_point	c;
	t_point	r;
	t_point	b;

	c = data->map.points[y][x];
	if (x < data->map.width - 1)
	{
		r = data->map.points[y][x + 1];
		dda_line_draw(data, c, r);
	}
	if (y < data->map.height - 1)
	{
		b = data->map.points[y + 1][x];
		dda_line_draw(data, c, b);
	}
}

void	draw_edges(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
			draw_connections(data, y, x);
	}
}
