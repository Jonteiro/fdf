/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:18:05 by jsilveir          #+#    #+#             */
/*   Updated: 2025/04/28 22:01:08 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_point
{
	float x;
	float y;
	float z;
} s_point;

typedef struct s_map
{
	int		ang[3];
	int		height;
	int		width;
	s_point	**points;
}			s_map;

typedef struct	s_data {
	void 	*mlx;
	void 	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	s_map 	map;
}				s_data;

# define X 0
# define Y 1
# define Z 2

void	my_mlx_pixel_put(s_data *data, int x, int y, int color);
void	map_format(char *file);
int		ft_killwindow(void *param);
int 	ft_is_esc(int keycode, void *param);
void	isometric(s_map *map);
void	ft_hooks(s_data *img);
int		is_number(char *str);
void 	ft_error(char *error);
void	map_format(char *file);
int		get_height(char *filename);
int		get_width(char *filename);
void 	fill_matrix(s_map *map, char *line, int y);

#endif