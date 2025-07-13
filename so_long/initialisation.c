/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:51:30 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/13 14:37:34 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nb_collect(char **map)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

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
			sol = recup_image(ber[x][y], &data, x, y);
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, sol, j, i);
			j += 64;
			y++;
		}
		x++;
		i += 64;
	}
}

void	pos_door(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while ((*data).map[i])
	{
		j = 0;
		while ((*data).map[i][j])
		{
			if (((*data).map[i][j]) == 'E')
			{
				(*data).exit_y = i;
				(*data).exit_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	*p_image(t_data *data, char *image)
{
	int		x;
	int		y;
	void	*img;

	x = 64;
	y = 64;
	img = mlx_xpm_file_to_image((*data).mlx_ptr, image, &x, &y);
	if (!img)
		return (0);
	return (img);
}

int	initialisation(t_data *data)
{
	pos_perso(data);
	pos_door(data);
	if (!init_image(data) || !init_image2(data)
		|| !init_image3(data) || !init_image4(data))
	{
		write(2, "Chargement d’image échoué\n", 30);
		exit(1);
		return (0);
	}
	data->nb_pas = 0;
	data->collect = nb_collect(data->map);
	put_sol(*data, data->longeur, data->largeur, data->map);
	if (!its_playable(data, (*data).map_bis, (*data).perso.y, (*data).perso.x))
		return (write(2, "Map non playable\n", 17), close_window(data, 0), 0);
	return (1);
}
