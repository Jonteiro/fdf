/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:18:05 by jsilveir          #+#    #+#             */
/*   Updated: 2025/05/05 20:11:34 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define _USE_MATH_DEFINES
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define SCALE 45
# define Z_SCALE 10
# define ANGLE 0.523599  // 30 deg in rad

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
	int 	win_width;
    int 	win_height;
	s_map 	map;
}				s_data;

# define X 0
# define Y 1
# define Z 2

void 	ft_error(char *error);
void	dda_line_draw(s_data *data, float x1, float y1, float x2, float y2);
void	my_mlx_pixel_put(s_data *data, int x, int y, int color);
void	map_format(char *file);
int		ft_killwindow(void *param);
int 	ft_is_esc(int keycode, void *param);
void	isometric(s_map *map);
void	ft_hooks(s_data *img);
int		is_number(char *str);
void	map_format(char *file);
// int		get_height(int fd);
int		get_width(char *line, s_map *map);
void 	fill_matrix(s_map *map, char *line, int y);
void 	read_map(s_data *data, char *filename);
int 	count_words(const char *str, char c);
void	ft_free_split(char **split_arr);
void	isometric(s_map *map);
void	print_matrix(s_map *map);
s_point matrix_multiply(float mat[3][3], s_point point);
void    draw_edges(s_data *data);
#endif