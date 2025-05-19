/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:21:05 by jsilveir          #+#    #+#             */
/*   Updated: 2025/05/08 15:21:05 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../fdf.h>
#include <math.h>

void	rotation_x(s_map *map)
{
	float	radian;
	float	rot_mat[3][3];
	int		y;
	int		x;

	radian = map->ang[X] * (M_PI / 180);
	rot_mat[0][0] = 1;
	rot_mat[0][1] = 0;
	rot_mat[0][2] = 0;
	rot_mat[1][0] = 0;
	rot_mat[1][1] = cos(radian);
	rot_mat[1][2] = -sin(radian);
	rot_mat[2][0] = 0;
	rot_mat[2][1] = sin(radian);
	rot_mat[2][2] = cos(radian);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			map->points[y][x] = matrix_multiply(rot_mat, map->points[y][x]);
	}
}

void	rotation_y(s_map *map)
{
	float	radian;
	float	rot_mat[3][3];
	int		y;
	int		x;

	radian = map->ang[Y] * (M_PI / 180);
	rot_mat[0][0] = cos(radian);
	rot_mat[0][1] = 0;
	rot_mat[0][2] = sin(radian);
	rot_mat[1][0] = 0;
	rot_mat[1][1] = 1;
	rot_mat[1][2] = 0;
	rot_mat[2][0] = -sin(radian);
	rot_mat[2][1] = 0;
	rot_mat[2][2] = cos(radian);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			map->points[y][x] = matrix_multiply(rot_mat, map->points[y][x]);
	}
}

void	rotation_z(s_map *map)
{
	float	radian;
	float	rot_mat[3][3];
	int		y;
	int		x;

	radian = map->ang[Z] * (M_PI / 180);
	rot_mat[0][0] = cos(radian);
	rot_mat[0][1] = -sin(radian);
	rot_mat[0][2] = 0;
	rot_mat[1][0] = sin(radian);
	rot_mat[1][1] = cos(radian);
	rot_mat[1][2] = 0;
	rot_mat[2][0] = 0;
	rot_mat[2][1] = 0;
	rot_mat[2][2] = 1;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			map->points[y][x] = matrix_multiply(rot_mat, map->points[y][x]);
	}
}

s_point	matrix_multiply(float mat[3][3], s_point p)
{
	s_point	result;

	result.x = mat[0][0] * p.x + mat[0][1] * p.y + mat[0][2] * p.z;
	result.y = mat[1][0] * p.x + mat[1][1] * p.y + mat[1][2] * p.z;
	result.z = mat[2][0] * p.x + mat[2][1] * p.y + mat[2][2] * p.z;
	return (result);
}

void	isometric(s_map *map)
{
	int	x;
	int	y;

	map->ang[X] = 30;
	map->ang[Y] = 330;
	map->ang[Z] = 45;
	rotation_x(map);
	rotation_y(map);
	rotation_z(map);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			map->points[y][x].x = map->points[y][x].x
				* SCALE + WIN_WIDTH * 0.5;
			map->points[y][x].y = map->points[y][x].y
				* SCALE + WIN_HEIGHT * 0.1;
		}
	}
}
