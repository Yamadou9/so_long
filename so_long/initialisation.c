/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:51:30 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/05 12:15:24 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sol(t_data data, int longeur, int largeur, char **ber)
{
	void	*sol;
	int		i;
	int		j;
	int		x;
	int		y;

	x = 0;
	i = 0;
	while (i < 64 * longeur)
	{
		j = 0;
		y = 0;
		while (j < 64 * largeur)
		{
			sol = recup_image(ber[x][y], data);
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, sol, j, i);
			j += 64;
			y++;
		}
		x++;
		i += 64;
	}
}

void	pos_perso(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while ((*data).map[i])
	{
		j = 0;
		while ((*data).map[i][j])
		{
			if (((*data).map[i][j]) == 'P')
			{
				(*data).perso.y = i;
				(*data).perso.x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_image(t_data *data)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	data->image.sol = mlx_xpm_file_to_image((*data).mlx_ptr, "image/sol.xpm", &x, &y);
	data->image.face = mlx_xpm_file_to_image((*data).mlx_ptr, "image/face.xpm", &x, &y);
}

void	initialisation(t_data *data)
{
	pos_perso(data);
	init_image(data);
}
