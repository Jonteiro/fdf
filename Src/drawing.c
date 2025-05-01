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
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

void dda_line_draw(s_data *data, float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps;
    float x_inc;
    float y_inc;
    float x = x1;
    float y = y1;

    if (dx == 0 && dy == 0)
    {
        my_mlx_pixel_put(data, round(x), round(y), 0x00ffffff);
        return;
    }
    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    x_inc = dx / steps;
    y_inc = dy / steps;
    for (int i = 0; i <= steps; i++)
    {
        if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_height)
            my_mlx_pixel_put(data, round(x), round(y), 0x00ffffff);
        x += x_inc;
        y += y_inc;
    }
}