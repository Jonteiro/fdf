/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:26:57 by jsilveir          #+#    #+#             */
/*   Updated: 2025/05/30 14:28:04 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uns_putnbr_base(unsigned long n, char *base)
{
	char			c;
	unsigned long	baselen;
	int				count;

	count = 0;
	baselen = ft_strlen(base);
	if (baselen < 2)
		return (0);
	if (n >= baselen)
		count += ft_uns_putnbr_base((n / baselen), base);
	c = (base[n % baselen]);
	count += write(1, &c, 1);
	return (count);
}

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

int	ft_put_nbr_base(unsigned int nbr, char *base)
{
	unsigned int	result;
	size_t			len;
	char			c;

	result = 0;
	len = ft_strlen(base);
	if (nbr >= len)
	{
		result += ft_put_nbr_base(nbr / len, base);
		result += ft_put_nbr_base(nbr % len, base);
	}
	else
	{
		c = base[nbr];
		result += write(1, &c, 1);
	}
	return (result);
}

int	ft_putchar_fd1(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
