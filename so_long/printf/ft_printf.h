/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:09:46 by ydembele          #+#    #+#             */
/*   Updated: 2025/05/21 16:38:35 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "stddef.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>

int		ft_print(void *n, char *base, int count);
int		ft_itoa(int n, char *base, int count);
int		ft_putnbr(long long d, int count);
int		ft_putnbr(long long d, int count);
int		ft_itoavoid(void *n, char *base, int count);
int		ft_putstr(char *s, int count);
int		ft_putchar(int c, int count);
int		is_format(char c, char *format);
int		ft_printf(const char	*s, ...);
int		ft_print_hexmaj(int nb, int count, char *base);
int		ft_print_hexa(int nb, int count, char *base);
char	*ft_strdup(char *s);
int		ft_print_pointer(void *nb, int count);
int		ft_put_unsigned(unsigned int nb, int count);
size_t	ft_strlen(char *str);

#endif
