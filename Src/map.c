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

int get_height(char *filename)
{
	int fd;
    int height;
    char *line;
	
    fd = open(filename, O_RDONLY);
    if (fd < 0)
	ft_error("Could not open file");
    height = 0;
    line = get_next_line(fd);
    while (line)
    {
		height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (height);
}

int get_width(char *filename)
{
	int fd;
    int width;
    char *line;
    char **split;
	
    fd = open(filename, O_RDONLY);
    if (fd < 0)
	ft_error("Could not open file");
    line = get_next_line(fd);
    if (!line)
	ft_error("Empty file");
    split = ft_split(line, ' ');
    width = 0;
    while (split[width])
    {
		free(split[width]);
        width++;
    }
    free(split);
    free(line);
    close(fd);
    return (width);
}

void fill_matrix(s_map *map, char *line, int y)
{
	char **nums;
    int x;
	
    nums = ft_split(line, ' ');
    x = 0;
    while (nums[x])
    {
		map->points[y][x].x = x;
        map->points[y][x].y = y;
        map->points[y][x].z = ft_atoi(nums[x]);
        free(nums[x]);
        x++;
    }
    free(nums);
}

void	map_parse(char *file)
{
	char		**map_row;
	char		*line;
	char		*temp;
	int			fd;
	static int	max_width;
	int			width;

	fd = fd_check(file);
	line = get_next_line(fd);
	while (line)
	{
		temp = line;
		map_row = ft_split(temp, ' ');
		free(temp);
		if (!map_row)
			return ;
		line = get_next_line(fd);
		free_map(map_row);
	}
	close (fd);
	if(max_width != 0 && width != max_width)
		ft_error("Map not rectangular");
}

void dda_line_draw(int x1, int x2, int y1, int y2, s_map map)
{
	float x,y,x1,y1,x2,y2,dx,dy,step;
	int i,gd=DETECT,gm;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	printf("Enter the value of x1 and y1 : ");
	scanf("%f%f",&x1,&y1);
	printf("Enter the value of x2 and y2: ");
	scanf("%f%f",&x2,&y2);

	dx=abs(x2-x1);
	dy=abs(y2-y1);

	if(dx>=dy)
		step=dx;
	else
		step=dy;

	dx=dx/step;
	dy=dy/step;

	x=x1;
	y=y1;

	i=1;
	while(i<=step)
	{
				my_mlx_pixel_put(&img, x, y, 0x00ffffff);
		x=x+dx;
		y=y+dy;
		i=i+1;
		delay(100);
	}

	closegraph();
}