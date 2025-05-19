#include "../fdf.h"

int	get_width(char *line, s_map *map)
{
	char	**split;
	int		width;

	split = ft_split(line, ' ');
	width = 0;
	while (split[width])
		free(split[width++]);
	free(split);
	if (map->width == 0)
		map->width = width;
	else if (map->width != width)
		ft_error("MAP NOT SQUARE");
	return (width);
}

void	fill_matrix(s_map *map, char *line, int y)
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

void	read_map(s_data *data, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	data->map.height = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (data->map.height == 0)
			data->map.width = count_words(line, ' ');
		free(line);
		data->map.height++;
		line = get_next_line(fd);
	}
	close(fd);
	data->map.points = malloc(sizeof(s_point *) * data->map.height);
	fd = open(filename, O_RDONLY);
	for (int y = 0; (line = get_next_line(fd)); y++)
	{
		data->map.points[y] = malloc(sizeof(s_point) * data->map.width);
		if (!data->map.points[y])
			ft_error("Malloc failed");
		fill_matrix(&data->map, line, y);
		free(line);
	}
	close(fd);
}

// void	print_matrix(s_map *map)
// {
//     int	y;
// 	int	x;
// 	y = 0;
// 	while (y < map->height)
// 	{
//         x = 0;
// 		while (x < map->width)
// 		{
//             printf("point[%d][%d] = (%.2f, %.2f, %.2f)\n", y,
	// x, map->points[y][x].x, map->points[y][x].y, map->points[y][x].z);
// 			x++;
// 		}
// 		ft_printf("\n");
// 		y++;
// 	}
// }

// int	count_words(const char *str, char c)
// {
// 	int	count;
// 	int	in_word;

// 	in_word = 0;
// 	count = 0;
// 	if (!str)
// 		return (0);
// 	while (*str)
// 	{
// 		if (*str != c && !in_word)
// 		{
// 			in_word = 1;
// 			count++;
// 		}
// 		else if (*str == c)
// 		{
// 			in_word = 0;
// 		}
// 		str++;
// 	}
// 	return (count);
// }

// void	ft_free_split(char **split_arr)
// {
// 	int	i;

// 	if (!split_arr)
// 		return ;
// 	i = 0;
// 	while (split_arr[i])
// 		free (split_arr[i++]);
// 	free (split_arr);
// }