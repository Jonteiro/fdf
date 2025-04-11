/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:04:10 by josilvei          #+#    #+#             */
/*   Updated: 2025/04/03 15:05:32 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int	value;
	int	sign;

	value = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
		value++;
	}
	if (value > 1)
		return (0);
	value = 0;
	while ((*nptr != '\0') && ft_isdigit(*nptr))
	{
		if (*nptr >= '0' && *nptr <= '9')
			value = value * 10 + (*nptr - '0');
		nptr++;
	}
	return (value * sign);
}
