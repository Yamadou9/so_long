/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:18:21 by ydembele          #+#    #+#             */
/*   Updated: 2025/05/18 18:17:37 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int count)
{
	write(1, &c, 1);
	return (count + 1);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr(long long n, int count)
{
	if (n == LLONG_MIN)
	{
		write(1, "-9223372036854775808", 20);
		count += 20;
		return (count);
	}
	if (n < 0)
	{
		count = ft_putchar('-', count);
		n = n * -1;
	}
	if (n < 10)
		count = ft_putchar(n + 48, count);
	else
	{
		count = ft_putnbr(n / 10, count);
		count = ft_putnbr(n % 10, count);
	}
	return (count);
}

int	ft_put_unsigned(unsigned int nb, int count)
{
	if (nb < 10)
		count = ft_putchar(nb + 48, count);
	else
	{
		count = ft_put_unsigned(nb / 10, count);
		count = ft_put_unsigned(nb % 10, count);
	}
	return (count);
}
