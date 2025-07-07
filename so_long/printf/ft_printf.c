/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:18:45 by ydembele          #+#    #+#             */
/*   Updated: 2025/05/21 16:38:26 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	ft_putstr(char *s, int count)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (count + 6);
	}
	while (s[i])
		write(1, &s[i++], 1);
	count += i;
	return (count);
}

int	is_format(char c, char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (c == format[i])
			return (1);
		i++;
	}
	return (0);
}

int	print_format(va_list ar, int count, char signe)
{
	void	*vide;

	if (signe == 's')
		count = ft_putstr(va_arg(ar, char *), count);
	else if (signe == 'c')
		count = ft_putchar(va_arg(ar, int), count);
	else if (signe == 'd' || signe == 'i')
		count = ft_putnbr(va_arg(ar, int), count);
	else if (signe == 'u')
		count = ft_put_unsigned(va_arg(ar, unsigned int), count);
	else if (signe == 'x')
		count = ft_print_hexa(va_arg(ar, int), count, "0123456789abcdef");
	else if (signe == 'X')
		count = ft_print_hexmaj(va_arg(ar, int), count, "0123456789ABCDEF");
	else if (signe == 'p')
	{
		vide = va_arg(ar, void *);
		if (!vide)
			return (ft_putstr("(nil)", count));
		write(1, "0x", 2);
		count = ft_print_pointer(vide, count) + 2;
	}
	return (count);
}

int	ft_printf(const char	*s, ...)
{
	int			i;
	int			count;
	va_list		ar;

	if (!s || s == NULL)
		return (-1);
	i = 0;
	count = 0;
	va_start(ar, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] && is_format(s[i + 1], "cspdiuxX"))
		{
			count = print_format(ar, count, s[i + 1]);
			i++;
		}
		else if (s[i] == '%' && s[i + 1] && s[i + 1] == '%')
			count = ft_putchar(s[i++], count);
		else
			count = ft_putchar(s[i], count);
		i++;
	}
	va_end(ar);
	return (count);
}
// int	main()
// {
// 	char	*ko;
// 	char c = 'd';
// 	unsigned int		n = 44444445;
// 	char *s;
// 	int d = 77;

// 	s = "bonjour";
// 	ko = "oul";
// 	printf("%d", ft_printf(NULL));
// 	printf("%d", printf(NULL));
// 	// printf(" NULL %s NULL \n", (char *)NULL);
// 	// ft_printf(" NULL %s NULL \n", (char *)NULL);

// }
