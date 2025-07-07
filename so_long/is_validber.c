/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:48:06 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/07 18:57:43 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_malloc/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	**put_in_ber(char *fichier, int longeur)
{
	char	**ber;
	int		fd;
	int		i;

	i = 0;
	ber = malloc(sizeof(char *) * longeur + 1);
	if (!ber)
		return (0);
	fd = open(fichier, O_RDONLY);
	while (1)
	{
		ber[i] = get_next_line(fd);
		if (!ber[i])
			break ;
		i++;
	}
	ber[i] = NULL;
	return (ber);
}

int	count(char *line, int c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	is_rectangle(char *ber)
{
	char	*line;
	int		size;
	int		fd;
	int		longueur;

	longueur = 1;
	fd = open(ber, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	size = ft_len(line, 0);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (size != ft_len(line, 0))
			return (free(line), 0);
		free(line);
		longueur++;
	}
	return (longueur);
}

int	valid_count(char *ber)
{
	char	*line;
	int		fd;
	int		count_p;
	int		count_e;
	int		count_c;

	count_p = 0;
	count_e = 0;
	count_c = 0;
	fd = open(ber, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count_e += count(line, 'E');
		count_p += count(line, 'P');
		count_c += count(line, 'C');
		free(line);
	}
	if (count_c >= 1 && count_e == 1 && count_p == 1)
		return (1);
	return (0);
}

int	is_lockup(char **ber, int longr)
{
	int		i;

	i = 0;
	while (ber[i])
	{
		if (i == 0 || i == longr)
		{
			if (count(ber[i], '1') != len(ber[i]))
				return (0);
		}
		else
		{
			if (ber[i][0] != '1' || ber[i][len(ber[i]) - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

char	**is_validber(char **av, t_data *data)
{
	char	**ber;

	data->longeur = is_rectangle(av[1]);
	ber = put_in_ber(av[1], data->longeur);
	data->largeur = len(ber[0]);
	if (!ber)
		return (0);
	if (!data->longeur)
		return (0);
	if (!valid_count(av[1]))
		return (0);
	if (!is_lockup(ber, data->longeur))
		return (0);
	return (ber);
}

// int	main(int ac, char **av)
// {
// 	char *res;
// 	int fd = open(av[1], O_RDONLY);
// 	int i = 0;

// 	(void)ac;
// 	while (i < 49)
// 	{
// 		res = get_next_line(fd);
// 		printf("%s", res);
// 		free(res);
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	char *caca;
// 	caca = "1000001";
// 	printf("%d", count(caca + ft_len(caca, 0) - 1, '1'));
// }