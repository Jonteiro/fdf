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

void	my_mlx_pixel_put(s_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *) dest = color;
}

void	dda_line_draw(s_data *data, float x1, float y1, float x2, float y2)
{
	float	steps;
	float	x_inc;
	float	y_inc;

	if (x2 - x1 == 0 && y2 - y1 == 0)
	{
		my_mlx_pixel_put(data, round(x1), round(y1), 0x00ffffff);
		return ;
	}
	if (fabs(x2 - x1) > fabs(y2 - y1))
		steps = fabs(x2 - x1);
	else
		steps = fabs(y2 - y1);
	x_inc = (x2 - x1) / steps;
	y_inc = (y2 - y1) / steps;
	for (int i = 0; i <= steps; i++)
	{
		if (x1 >= 0 && x1 < data->win_width && y1 >= 0 && y1 < data->win_height)
			my_mlx_pixel_put(data, round(x1), round(y1), 0x00ffffff);
		x1 += x_inc;
		y1 += y_inc;
	}
}

void	draw_edges(s_data *data)
{
	int		x;
	int		y;
	s_point	*current;
	s_point	*right;
	s_point	*bottom;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			current = &data->map.points[y][x];
			if (x < data->map.width - 1)
			{
				right = &data->map.points[y][x + 1];
				dda_line_draw(data, current->x, current->y,
					right->x, right->y);
			}
			if (y < data->map.height - 1)
			{
				bottom = &data->map.points[y + 1][x];
				dda_line_draw(data, current->x, current->y,
					bottom->x, bottom->y);
			}
			x++;
		}
		y++;
	}
}
