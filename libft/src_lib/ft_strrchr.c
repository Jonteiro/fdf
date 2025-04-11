/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:01:07 by josilvei          #+#    #+#             */
/*   Updated: 2025/04/03 15:05:32 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int		i;
	char	*a;

	a = (char *)src;
	i = ft_strlen(src);
	while (i >= 0)
	{
		if (a[i] == (char)c)
			return (a + i);
		i--;
	}
	return (NULL);
}
