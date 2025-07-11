/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:07:57 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/11 10:21:47 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	extend_playeur(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'E' || map[x][y] == 'O')
		return ;
	map[x][y] = 'O';
	extend_playeur(map, x + 1, y);
	extend_playeur(map, x - 1, y);
	extend_playeur(map, x, y + 1);
	extend_playeur(map, x, y - 1);
}

int	its_playable(t_data *data, char **map, int x, int y)
{
	int	i;

	i = 0;
	(void)data;
	extend_playeur(map, x, y);
	while (map[i])
	{
		if (count(map[i], 'C') != 0)
			return (0);
		i++;
	}
	if (map[data->exit_y + 1][data->exit_x] != 'O'
		&& map[data->exit_y - 1][data->exit_x] != 'O'
		&& map[data->exit_y][data->exit_x + 1] != 'O'
		&& map[data->exit_y][data->exit_x - 1] != 'O')
		return (0);
	return (1);
}
