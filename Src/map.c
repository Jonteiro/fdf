/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:55:45 by jsilveir          #+#    #+#             */
/*   Updated: 2025/04/25 12:55:45 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	get_dimensions(t_data *data, char *filename)
{
	int		fd;
	char	*line;
	int		width;

	data->map.width = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening file");
	data->map.height = 0;
	line = get_next_line(fd);
	while (line)
	{
		width = count_words(line, ' ');
		if (width == 0)
			ft_error("Empty line in map");
		if (data->map.width == 0)
			data->map.width = width;
		else if (width != data->map.width)
			clean_exit(data, data->map.height, fd, line);
			// ft_error("MAP NOT SQUARE");
		free(line);
		data->map.height++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	clean_exit(t_data *data, int y, int fd, char *line)
{
	if (line)
		free(line);
	if (data->map.points)
		ft_free_map(data, y);
	if (fd >= 0)
		close(fd);
	ft_error("MAP NOT SQUARE");
}

void	read_map(t_data *data, char *filename)
{
	int		fd;
	char	*line;
	int		y;

	get_dimensions(data, filename);
	data->map.points = malloc(sizeof(t_point *) * data->map.height);
	if (!data->map.points)
		ft_error("Malloc failed");
	fd = open(filename, O_RDONLY);
	y = -1;
	line = get_next_line(fd);
	while (++y < data->map.height && line)
	{
		data->map.points[y] = malloc(sizeof(t_point) * data->map.width);
		if (!data->map.points[y] || get_width(line, &data->map)
			!= data->map.width)
			clean_exit(data, y, fd, line);
		fill_matrix(&data->map, line, y);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
}

int	get_width(char *line, t_map *map)
{
	int	width;

	width = count_words(line, ' ');
	if (map->width == 0)
		map->width = width;
	return (width);
}

void	fill_matrix(t_map *map, char *line, int y)
{
	char	**nums;
	int		x;

	nums = ft_split(line, ' ');
	x = 0;
	while (x < map->width)
	{
		map->points[y][x].x = x;
		map->points[y][x].y = y;
		map->points[y][x].z = (float)ft_atoi(nums[x]);
		free(nums[x]);
		x++;
	}
	free(nums);
}
