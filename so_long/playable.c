/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:07:57 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/07 18:53:57 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**is_validber(char **av, t_data *data);
char	**put_in_ber(char *fichier, int longeur);

void	its_playable(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'E' || map[x][y] == 'O')
		return ;
	map[x][y] = 'O';
	its_playable(map, x + 1, y);
	its_playable(map, x - 1, y);
	its_playable(map, x, y + 1);
	its_playable(map, x, y - 1);
}


// int	main(int ac, char **av)
// {
// 	char **map;

// 	(void)ac;
// 	map = put_in_ber(av[1], 9);
// 	its_playable(map, 1, 1);
// 	return (0);
// }
