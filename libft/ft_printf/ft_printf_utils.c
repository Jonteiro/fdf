/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:24:01 by jsilveir          #+#    #+#             */
/*   Updated: 2025/04/30 12:30:21 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr_fd1(char *s, int fd)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putnbr_base(int n, char *base)
{
	char	c;
	int		baselen;
	int		count;

	count = 0;
	baselen = ft_strlen(base);
	if (baselen < 2)
		return (0);
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		if (n == -2147483648)
		{
			ft_putnbr_base(-(n / baselen), base);
			ft_putnbr_base(-(n % baselen), base);
			return (11);
		}
		n *= -1;
	}
	if (n >= baselen)
		count += ft_putnbr_base((n / baselen), base);
	c = (base[n % baselen]);
	count += write(1, &c, 1);
	return (count);
}

int	ft_print_pointer(void *lepointer)
{
	unsigned long	addr;
	int				length;

	if (!lepointer)
		return (ft_putstr_fd1("(nil)", 1));
	addr = (unsigned long)lepointer;
	if ((long)lepointer < 0)
		addr = ~((unsigned long)(-((long)lepointer))) + 1;
	length = ft_putstr_fd1("0x", 1);
	length += ft_uns_putnbr_base(addr, "0123456789abcdef");
	return (length);
}
