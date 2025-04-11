/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:20:57 by jsilveir          #+#    #+#             */
/*   Updated: 2025/04/03 14:47:56 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr_base(int n, char *base);
int		ft_putstr_fd1(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_putchar_fd1(char c, int fd);
int		ft_print_pointer(void	*lepointer);
int		ft_uns_putnbr_base(unsigned long n, char *base);
int		ft_put_nbr_base(unsigned int nbr, char *base);
char	*ft_strrchr(const char *src, int c);

#endif