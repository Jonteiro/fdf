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

int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	height = 0;
	if (fd < 0)
		ft_error("Could not open file");
	while ((line = get_next_line(fd)))
	{
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	int		fd;
	char	*line;
	char	**split;
	int		width;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || !(line = get_next_line(fd)))
		ft_error("Could not open file");
	split = ft_split(line, ' ');
	width = 0;
	while (split[width])
		free(split[width++]);
	free(split);
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(s_map *map, char *line, int y)
{
	char	**nums;
	int		x;

	x = -1;
	nums = ft_split(line, ' ');
	if (!nums)
		ft_error("Memory error");
	while (++x < map->width)
	{
		map->points[y][x].z = ft_atoi(nums[x]);
		free(nums[x]);
	}
	if (x != map->width)
		(ft_error("Invalid line"), free(nums));

	free(nums);
}


void	read_map(s_data *data, char *filename)
{
	int		fd;
	char	*line;
	int		y;

	data->map.width = get_width(filename);
	data->map.height = get_height(filename);
	fd = open(filename, O_RDONLY);
	data->map.points = malloc(sizeof(s_point *) * data->map.height);
	y = -1;
	while (++y < data->map.height)
	{
		line = get_next_line(fd);
		if (count_words(line, ' ') != data->map.width)
			(ft_error("Invalid map"), free(line));
		data->map.points[y] = malloc(sizeof(s_point) * data->map.width);
		fill_matrix(&data->map, line, y);
		free(line);
	}
	close(fd);
}

int count_words(const char *str, char c)
{
    int count = 0;
    int in_word = 0;

    if (!str)
        return (0);
        
    while (*str) {
        if (*str != c && !in_word) {
            in_word = 1;
            count++;
        } else if (*str == c) {
            in_word = 0;
        }
        str++;
    }
    return (count);
}
