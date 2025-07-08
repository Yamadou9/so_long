/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:51:30 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/08 17:34:29 by ydembele         ###   ########.fr       */
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
				(*data).exit_x = j;
				(*data).exit_y = i;
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

void	free_image(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.face);
	mlx_destroy_image(data->mlx_ptr, data->image.droit);
	mlx_destroy_image(data->mlx_ptr, data->image.left);
	mlx_destroy_image(data->mlx_ptr, data->image.dos);
	mlx_destroy_image(data->mlx_ptr, data->image.sol);
	mlx_destroy_image(data->mlx_ptr, data->image.cointbd);
	mlx_destroy_image(data->mlx_ptr, data->image.cointhg);
	mlx_destroy_image(data->mlx_ptr, data->image.cointhd);
	mlx_destroy_image(data->mlx_ptr, data->image.cointbg);
	mlx_destroy_image(data->mlx_ptr, data->image.mur_haut);
	mlx_destroy_image(data->mlx_ptr, data->image.mur_gauche);
	mlx_destroy_image(data->mlx_ptr, data->image.mur_droit);
	mlx_destroy_image(data->mlx_ptr, data->image.mur_bas);
	mlx_destroy_image(data->mlx_ptr, data->image.collect);
	mlx_destroy_image(data->mlx_ptr, data->image.door);
	mlx_destroy_image(data->mlx_ptr, data->image.boule);
	mlx_destroy_image(data->mlx_ptr, data->image.trou);
	mlx_destroy_image(data->mlx_ptr, data->image.door_close);
}


void init_imagenull(t_data *data)
{
	data->image.face = NULL;
	data->image.droit = NULL;
	data->image.left = NULL;
	data->image.dos = NULL;
	data->image.collect = NULL;
	data->image.door = NULL;
	data->image.sol = NULL;
	data->image.mur_bas = NULL;
	data->image.mur_gauche = NULL;
	data->image.mur_haut = NULL;
	data->image.mur_droit = NULL;
	data->image.cointbd = NULL;
	data->image.cointbg = NULL;
	data->image.cointhd = NULL;
	data->image.cointhg = NULL;
	data->image.boule = NULL;
	data->image.door_close = NULL;
}

int	init_image(t_data *data)
{
	init_imagenull(data);
	data->image.sol = p_image(data, "image/sol.xpm");
	if (!data->image.sol)
		return (free_image(data), 0);
	data->image.face = p_image(data, "image/face.xpm");
	if (!data->image.face)
		return (free_image(data), 0);
	data->image.droit = p_image(data, "image/p_droit.xpm");
	if (!data->image.droit)
		return (free_image(data), 0);
	data->image.left = p_image(data, "image/left.xpm");
	if (!data->image.left)
		return (free_image(data), 0);
	data->image.dos = p_image(data, "image/dos.xpm");
	if (!data->image.dos)
		return (free_image(data), 0);
	data->image.collect = p_image(data, "image/collect.xpm");
	if (!data->image.collect)
		return (free_image(data), 0);
	data->image.door = p_image(data, "image/door_open.xpm");
	if (!data->image.door)
		return (free_image(data), 0);
	data->image.boule = p_image(data, "image/boule.xpm");
	if (!data->image.boule)
		return (free_image(data), 0);
	return (1);
}

int	init_image2(t_data *data)
{
	data->image.mur_bas = p_image(data, "image/mb.xpm");
	if (!data->image.mur_bas)
		return (free_image(data), 0);
	data->image.mur_droit = p_image(data, "image/md.xpm");
	if (!data->image.mur_droit)
		return (free_image(data), 0);
	data->image.mur_gauche = p_image(data, "image/mg.xpm");
	if (!data->image.mur_gauche)
		return (free_image(data), 0);
	data->image.mur_haut = p_image(data, "image/mh.xpm");
	if (!data->image.mur_haut)
		return (free_image(data), 0);
	data->image.cointbd = p_image(data, "image/cbd.xpm");
	if (!data->image.cointbd)
		return (free_image(data), 0);
	data->image.cointbg = p_image(data, "image/cbg.xpm");
	if (!data->image.cointbg)
		return (free_image(data), 0);
	data->image.cointhd = p_image(data, "image/chd.xpm");
	if (!data->image.cointhd)
		return (free_image(data), 0);
	data->image.cointhg = p_image(data, "image/chg.xpm");
	if (!data->image.cointhg)
		return (free_image(data), 0);
	data->image.trou = p_image(data, "image/trou.xpm");
	if (!data->image.trou)
		return (free_image(data), 0);
	data->image.door_close = p_image(data, "image/door_close.xpm");
	if (!data->image.door_close)
		return (free_image(data), 0);
	return (1);
}

void	initialisation(t_data *data)
{
	pos_perso(data);
	pos_door(data);
	if (!init_image(data) || !init_image2(data))
	{
		ft_printf("Erreur : chargement d’image échoué\n");
		exit(1);
	}
	data->collect = nb_collect(data->map);
}

