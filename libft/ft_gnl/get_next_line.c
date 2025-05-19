/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:17:46 by jsilveir          #+#    #+#             */
/*   Updated: 2025/05/03 13:36:14 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE + 1];
// 	char		*line;

// 	line = NULL;
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
// 	{
// 		line = ft_strjoin1(line, buffer);
// 		if (!line)
// 			return (NULL);
// 		clean_buffer(buffer);
// 		if (line[ft_strlen1(line) - 1] == '\n' )
// 			return (line);
// 	}
// 	return (line);
// }

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static size_t	pos;
	char		*line;
	ssize_t		bytes;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buf[pos])
		{
			line = ft_strjoin1(line, buf + pos);
			if (!line || !clean_buffer(buf, &pos))
				break ;
			if (line[ft_strlen1(line) - 1] == '\n')
				return (line);
		}
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			return (line);
		buf[bytes] = '\0';
		pos = 0;
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("../../test.fdf", O_RDONLY);
// 	if (fd <= 0)
// 	{
// 		printf("Error opening file\n");
// 		return (1);
// 	}
// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		if (line != NULL)
// 			printf("line - %s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
