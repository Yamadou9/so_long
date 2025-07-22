/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:54:52 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/21 18:38:23 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data, int success)
{
	free_all(data->map);
	free_all(data->map_bis);
	free_image(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	if (success == -1)
		ft_printf("\n\n  FENETRE FERMEE\n\n");
	else if (success == 'R')
		ft_printf("\n\nLE RENARD A PRIS T'ES FROMAGE\n\n");
	else if (success == 'E')
		ft_printf("Nombres de pas : %d\n\n  FELICITATIONS\n\n", data->nb_pas + 1);
	else
		ft_printf("\n\n  FENETRE FERMEE\n\n");
	exit(0);
	return (0);
}

void	*wall(int x, int y, t_data *data)
{
	void	*wall;

	if (x == 0 && y == 0)
		wall = data->image.cointhg;
	else if (x == 0 && y == (*data).largeur - 1)
		wall = data->image.cointhd;
	else if (x == (*data).longeur - 1 && y == 0)
		wall = data->image.cointbg;
	else if (x == (*data).longeur - 1 && y == (*data).largeur - 1)
		wall = data->image.cointbd;
	else if (x == 0)
		wall = data->image.mur_haut;
	else if (x == (*data).longeur - 1)
		wall = data->image.mur_bas;
	else if (y == 0)
		wall = data->image.mur_gauche;
	else if (y == (*data).largeur - 1)
		wall = data->image.mur_droit;
	else
		wall = data->image.trou;
	return (wall);
}

void	*recup_image(char c, t_data *data, int x, int y)
{
	void	*image;

	if (c == '0')
		image = data->image.sol;
	else if (c == '1')
		image = wall(x, y, data);
	else if (c == 'P')
		image = data->image.face;
	else if (c == 'C')
		image = data->image.boule;
	else if (c == 'E')
		image = data->image.door_close;
	else if (c == 'R')
		image = data->image.renard;
	return (image);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		d;
	int		l;

	if (ac != 2)
		return (0);
	if (!is_validber(av, &data))
		return (0);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		write(2, "Mlx\n", 4);
		return (free_all(data.map), free_all(data.map_bis), 0);
	}
	d = 64 * data.largeur;
	l = 64 * data.longeur;
	data.win_ptr = mlx_new_window(data.mlx_ptr, d, l, "so_long");
	if (!data.win_ptr)
		return (perror("win"), free_all(data.map), free_all(data.map_bis), 0);
	if (!initialisation(&data))
		return (close_window(&data, 0), 0);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
