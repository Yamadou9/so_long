/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:54:52 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/11 10:51:05 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	free_all(data->map);
	free_all(data->map_bis);
	free_image(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, void *param)
{
	(void)param;
	ft_printf("tu appuie sur la touche : %d \n", keycode);
	if (keycode == 65307)
		return (1);
	return (0);
}

int	on_destroy(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!handle_keypress(keycode, param))
		return (0);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
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
	return (image);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	data.map = is_validber(av, &data);
	if (!data.map)
		return (write(2, "map no valid\n", 14), free(data.map), 0);
	data.map_bis = is_validber(av, &data);
	if (!data.map_bis)
		return (free_all(data.map), 0);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (free_all(data.map), free_all(data.map_bis), 0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 64 * data.largeur, 64 * data.longeur, "so_long");
	if (!data.win_ptr)
	{
		write(2, "fenetre non cree\n", 18);
		return (free_all(data.map), free_all(data.map_bis), 0);
	}
	initialisation(&data);
	if (!its_playable(&data, data.map_bis, data.perso.y, data.perso.x))
		return (write(2, "Map non playable\n", 17), close_window(&data), 0);
	mlx_key_hook(data.win_ptr, game, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
