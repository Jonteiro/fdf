/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:25:00 by josilvei          #+#    #+#             */
/*   Updated: 2025/04/03 15:05:32 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		little_len;
	const char	*p = big;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (*big == '\0' || *little == '\0' || len == 0)
		return (NULL);
	while (*p != '\0' && len-- >= little_len)
	{
		if (ft_strncmp(p, little, little_len) == 0)
			return ((char *)p);
		p++;
	}
	return (NULL);
}
