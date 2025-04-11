/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:24:41 by josilvei          #+#    #+#             */
/*   Updated: 2025/04/03 15:05:32 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_str(long num, int i, int sign)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

int	get_i(long num, int sign)
{
	int	i;

	if (sign == -1)
		i = 2;
	else
		i = 1;
	while ((num / 10) > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
	{
	int		i;
	int		sign;
	long	num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = -1;
		num = (long)(-n);
	}
	else
	{
		sign = 1;
		num = (long)(n);
	}
	i = get_i(num, sign);
	return (get_str(num, i, sign));
}
