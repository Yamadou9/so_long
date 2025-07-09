/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:48:06 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/08 17:42:12 by ydembele         ###   ########.fr       */
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

int count_lines(char *fichier)
{
	int		fd;
	int		count = 0;
	char	*line;

	fd = open(fichier, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
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

char	**put_in_ber(char *fichier)
{
	char	**ber;
	int		fd;
	int		i = 0;
	int		total_lines = count_lines(fichier);

	ber = malloc(sizeof(char *) * (total_lines + 1));
	if (!ber)
		return (0);
	fd = open(fichier, O_RDONLY);
	while (i < total_lines)
	{
		ber[i] = get_next_line(fd);
		if (!ber[i])
			break ;
		i++;
	}
	ber[i] = NULL;
	close(fd);
	return (ber);
}

int	other(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'C' && line[i] != 'P' && line[i] != 'E'
			&& line[i] != '\n' && line[i] != '\0')
			return (1);
		i++;
	}
	return (0);
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
	int		c_other;

	c_other = 0;
	count_p = 0;
	count_e = 0;
	count_c = 0;
	fd = open(ber, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		c_other += other(line);
		count_e += count(line, 'E');
		count_p += count(line, 'P');
		count_c += count(line, 'C');
		free(line);
	}
	close(fd);
	if (count_c >= 1 && count_e == 1 && count_p == 1 && c_other == 0)
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
	ber = put_in_ber(av[1]);
	if (!ber)
		return (0);
	data->largeur = len(ber[0]);
	if (!valid_count(av[1]))
		return (free_all(ber), NULL);
	if (!data->longeur)
		return (free_all(ber), NULL);
	if (!is_lockup(ber, data->longeur))
		return (free_all(ber), NULL);
	return (ber);
}
