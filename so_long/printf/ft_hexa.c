/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:25:08 by ydembele          #+#    #+#             */
/*   Updated: 2025/05/21 16:24:34 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

char	*ft_strdup(char *s)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_print_hexa(int nb, int count, char *base)
{
	unsigned int			n;

	n = (unsigned int)nb;
	if (n < 16)
	{
		write(1, &base[n], 1);
		count++;
	}
	else
	{
		count = ft_print_hexa(n / 16, count, base);
		count = ft_print_hexa(n % 16, count, base);
	}
	return (count);
}

int	ft_print_unsig(unsigned long nb, int count, char *base)
{
	if (nb >= 16)
		count = ft_print_unsig(nb / 16, count, base);
	write(1, &base[nb % 16], 1);
	return (count + 1);
}

int	ft_print_hexmaj(int nb, int count, char *base)
{	
	unsigned int	n;

	n = (unsigned int)nb;
	if (n < 16)
	{
		write(1, &base[n], 1);
		count++;
	}
	else
	{
		count = ft_print_hexmaj(n / 16, count, base);
		count = ft_print_hexmaj(n % 16, count, base);
	}
	return (count);
}

int	ft_print_pointer(void *nb, int count)
{
	unsigned long			n;

	n = (unsigned long)nb;
	count = ft_print_unsig(n, count, "0123456789abcdef");
	return (count);
}
