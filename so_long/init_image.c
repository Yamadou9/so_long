/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:52:37 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/13 14:38:16 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_destroy_image(data->mlx_ptr, data->image.chiffre_0);
	mlx_destroy_image(data->mlx_ptr, data->image.chiffre_1);
	mlx_destroy_image(data->mlx_ptr, data->image.chiffre_2);
	mlx_destroy_image(data->mlx_ptr, data->image.chiffre_3);
	mlx_destroy_image(data->mlx_ptr, data->image.chiffre_4);
	mlx_destroy_image(data->mlx_ptr, data->image.chiffre_5);
	mlx_destroy_image(data->mlx_ptr, data->image.chiffre_6);
	mlx_destroy_image(data->mlx_ptr, data->image.chiffre_7);
	mlx_destroy_image(data->mlx_ptr, data->image.chiffre_8);
	mlx_destroy_image(data->mlx_ptr, data->image.chiffre_9);
}

void	init_imagenull(t_data *data)
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
	data->image.trou = NULL;
	data->image.chiffre_0 = NULL;
	data->image.chiffre_1 = NULL;
	data->image.chiffre_2 = NULL;
	data->image.chiffre_3 = NULL;
	data->image.chiffre_4 = NULL;
	data->image.chiffre_5 = NULL;
	data->image.chiffre_6 = NULL;
	data->image.chiffre_7 = NULL;
	data->image.chiffre_8 = NULL;
	data->image.chiffre_9 = NULL;
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
	data->image.collect = p_image(data, "image/coll.xpm");
	if (!data->image.collect)
		return (free_image(data), 0);
	data->image.door = p_image(data, "image/door_open.xpm");
	if (!data->image.door)
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
	return (1);
}

int	init_image3(t_data *data)
{
	data->image.trou = p_image(data, "image/trou.xpm");
	if (!data->image.trou)
		return (free_image(data), 0);
	data->image.door_close = p_image(data, "image/door_close.xpm");
	if (!data->image.door_close)
		return (free_image(data), 0);
	data->image.boule = p_image(data, "image/fromage.xpm");
	if (!data->image.boule)
		return (free_image(data), 0);
	data->image.chiffre_0 = p_image2(data, "image/0.xpm");
	if (!data->image.chiffre_0)
		return (free_image(data), 0);
	data->image.chiffre_1 = p_image2(data, "image/1.xpm");
	if (!data->image.chiffre_1)
		return (free_image(data), 0);
	data->image.chiffre_2 = p_image2(data, "image/2.xpm");
	if (!data->image.chiffre_2)
		return (free_image(data), 0);
	return (1);
}

int	init_image4(t_data *data)
{
	data->image.chiffre_3 = p_image2(data, "image/3.xpm");
	if (!data->image.chiffre_3)
		return (free_image(data), 0);
	data->image.chiffre_4 = p_image2(data, "image/4.xpm");
	if (!data->image.chiffre_4)
		return (free_image(data), 0);
	data->image.chiffre_5 = p_image2(data, "image/5.xpm");
	if (!data->image.chiffre_5)
		return (free_image(data), 0);
	data->image.chiffre_6 = p_image2(data, "image/6.xpm");
	if (!data->image.chiffre_6)
		return (free_image(data), 0);
	data->image.chiffre_7 = p_image2(data, "image/7.xpm");
	if (!data->image.chiffre_7)
		return (free_image(data), 0);
	data->image.chiffre_8 = p_image2(data, "image/8.xpm");
	if (!data->image.chiffre_8)
		return (free_image(data), 0);
	data->image.chiffre_9 = p_image2(data, "image/9.xpm");
	if (!data->image.chiffre_9)
		return (free_image(data), 0);
	return (1);
}
