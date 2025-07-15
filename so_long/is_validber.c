/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:48:06 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/15 19:57:34 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_malloc/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

char	**put_in_ber(char *fichier)
{
	char		**ber;
	int			fd;
	char		*total;
	char		*line;

	total = NULL;
	fd = open(fichier, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		total = ft_strjoin(total, line);
		if (!total)
			return (free(line), NULL);
		free(line);
	}
	close(fd);
	ber = ft_split(total, '\n');
	if (!ber)
		return (free(total), NULL);
	return (free(total), ber);
}

int	is_rectangle(char **ber)
{
	int		size;
	int		longueur;
	int		i;

	i = 0;
	longueur = 0;
	size = len(ber[i]);
	while (ber[i])
	{
		if (size != len(ber[i]))
			return (0);
		longueur++;
		i++;
	}
	return (longueur);
}

int	valid_count(char **ber)
{
	int		count_p;
	int		count_e;
	int		count_c;
	int		c_other;
	int		i;

	i = 0;
	c_other = 0;
	count_p = 0;
	count_e = 0;
	count_c = 0;
	while (ber[i])
	{
		c_other += other(ber[i]);
		count_e += count(ber[i], 'E');
		count_p += count(ber[i], 'P');
		count_c += count(ber[i], 'C');
		i++;
	}
	if (count_c >= 1 && count_e == 1 && count_p == 1 && c_other == 0)
		return (1);
	return (0);
}

int	is_lockup(t_data *data, char **ber, int longr)
{
	int		i;

	i = 0;
	while (ber[i])
	{
		if (i == 0 || i == longr - 1)
		{
			if (count(ber[i], '1') != len(ber[i]))
				return (0);
		}
		else
		{
			if (ber[i][0] != '1' || ber[i][data->largeur - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int is_validber(char **av, t_data *data)
{

	if (ft_strcmp(".ber", av[1] + len(av[1]) - 4))
		return (0);
	(*data).map = put_in_ber(av[1]);
	if (!(*data).map)
		return (0);
	data->longeur = is_rectangle((*data).map);
	if (!data->longeur)
		return (free_all((*data).map), 0);
	data->largeur = len((*data).map[0]);
	if (!valid_count((*data).map))
		return (free_all((*data).map), 0);
	if (!data->longeur)
		return (free_all((*data).map), 0);
	if (!is_lockup(data, (*data).map, data->longeur))
		return (free_all((*data).map), 0);
	pos_perso(data);
	pos_door(data);
	(*data).map_bis = put_in_ber(av[1]);
	if (!its_playable(data, (*data).map_bis, (*data).perso.y, (*data).perso.x))
		return (write(2, "Map\n", 4), free_all((*data).map_bis), free_all((*data).map), 0);
	return (1);
}
