/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:17:42 by jsilveir          #+#    #+#             */
/*   Updated: 2025/05/30 14:27:41 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i + (s[i] == '\n'));
}

char	*ft_strjoin1(char *line, char *buf_part)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen1(buf_part);
	new = malloc(ft_strlen1(line) + len + 1);
	if (!new)
		return (free(line), NULL);
	i = 0;
	j = 0;
	while (line && line[i])
		new[j++] = line[i++];
	i = 0;
	while (i < len)
		new[j++] = buf_part[i++];
	new[j] = '\0';
	free(line);
	return (new);
}

int	clean_buffer(char *buffer, size_t *pos)
{
	size_t	len;

	len = ft_strlen1(buffer + *pos);
	if (buffer[*pos + len] == '\n')
	{
		*pos += len + 1;
		return (0);
	}
	*pos += len;
	return (1);
}

// size_t	ft_strlen1(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s[i])
// 		return (0);
// 	while (s[i] && s[i] != '\n')
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin1(char *line, char *buf)
// {
// 	char	*new;
// 	size_t	i;
// 	size_t	j;
// 	size_t	len;

// 	len = ft_strlen1(buf);
// 	new = malloc(ft_strlen1(line) + len + 1);
// 	if (!new)
// 		return (free(line), NULL);
// 	i = 0;
// 	j = 0;
// 	while (line && line[i])
// 		new[j++] = line[i++];
// 	i = 0;
// 	while (buf[i] && i < len)
// 		new[j++] = buf[i++];
// 	new[j] = '\0';
// 	free(line);
// 	return (new);
// }

// void	clean_buffer(char *buffer)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	len;

// 	len = ft_strlen1(buffer);
// 	i = len;
// 	j = 0;
// 	while (buffer[i])
// 		buffer[j++] = buffer[i++];
// 	while (j < BUFFER_SIZE + 1)
// 		buffer[j++] = '\0';
// }
