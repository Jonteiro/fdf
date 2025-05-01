/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:21:00 by jsilveir          #+#    #+#             */
/*   Updated: 2025/04/30 12:34:35 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_spec(int c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

int	check_spec(va_list args, char format)
{
	int	length;

	length = 0;

	if (format == 'c')
		length += ft_putchar_fd1(va_arg(args, int), 1);
	if (format == 's')
		length += ft_putstr_fd1(va_arg(args, char *), 1);
	if (format == 'p')
		length += ft_print_pointer(va_arg(args, void *));
	if (format == 'd' || format == 'i')
		length += ft_putnbr_base(va_arg(args, long int), "0123456789");
	if (format == 'u')
		length += ft_uns_putnbr_base(va_arg(args, unsigned int), "0123456789");
	if (format == 'x')
		length += ft_put_nbr_base(va_arg(args, unsigned int),
				"0123456789abcdef");
	if (format == 'X')
		length += ft_put_nbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	if (format == '%')
		length += ft_putchar_fd1('%', 1);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_is_spec(*format))
				length += check_spec(args, *format);
		}
		else
			length += ft_putchar_fd1(*format, 1);
		format++;
	}
	va_end(args);
	return (length);
}

/* int main(){
 	ft_printf("-------------------ft_printf-------------------\n");
	ft_printf("\n%d\n", ft_printf("testing %d", 42));

	printf("\n\n-------------------original-------------------\n");
	ft_printf("\n%d\n", ft_printf("testing %d", 42));

} */