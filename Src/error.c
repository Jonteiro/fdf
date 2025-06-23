/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:39:46 by jsilveir          #+#    #+#             */
/*   Updated: 2025/04/28 21:39:46 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_error(char *error)
{
	ft_printf("error: %s", error);
	exit(1);
}

void	ft_free_split(char **split_arr)
{
	int	i;

	if (!split_arr)
		return ;
	i = 0;
	while (split_arr[i])
		free (split_arr[i++]);
	free (split_arr);
}

int	count_words(const char *str, char c)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

void	ft_free_map(t_data *data, int last_allocated_row)
{
	int	i;

	if (data->map.points)
	{
		if (last_allocated_row == -1)
		{
			i = 0;
			while (i < data->map.height)
			{
				free(data->map.points[i]);
				i++;
			}
		}
		else
		{
			i = 0;
			while (i <= last_allocated_row)
			{
				free(data->map.points[i]);
				i++;
			}
		}
		free(data->map.points);
		data->map.points = NULL;
	}
}
