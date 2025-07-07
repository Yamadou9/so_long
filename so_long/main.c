/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:54:52 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/07 18:58:01 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
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

void	*wall(int x, int y, t_data data)
{
	void	*wall;
	int		i;
	int		j;
	
	i = 64;
	j = 64;
	if (x == 0 && y == 0)
		wall = mlx_xpm_file_to_image(data.mlx_ptr, "image/chg.xpm", &i, &j);
	else if (x == 0 && y == data.largeur - 1)
		wall = mlx_xpm_file_to_image(data.mlx_ptr, "image/chd.xpm", &i, &j);
	else if (x == data.longeur - 1 && y == 0)
		wall = mlx_xpm_file_to_image(data.mlx_ptr, "image/cbg.xpm", &i, &j);
	else if (x == data.longeur - 1 && y == data.largeur - 1)
		wall = mlx_xpm_file_to_image(data.mlx_ptr, "image/cbd.xpm", &i, &j);
	else if (x == 0)
		wall = mlx_xpm_file_to_image(data.mlx_ptr, "image/mh.xpm", &i, &j);
	else if (x == data.longeur - 1)
		wall = mlx_xpm_file_to_image(data.mlx_ptr, "image/mb.xpm", &i, &j);
	else if (y == 0)
		wall = mlx_xpm_file_to_image(data.mlx_ptr, "image/mg.xpm", &i, &j);
	else if (y == data.largeur - 1)
		wall = mlx_xpm_file_to_image(data.mlx_ptr, "image/md.xpm", &i, &j);
	else
		wall = mlx_xpm_file_to_image(data.mlx_ptr, "image/soljaune.xpm", &i, &j);
	return (wall);
}

void	*recup_image(char c, t_data data, int x, int y)
{
	void	*image;
	int		x_fond;
	int		y_fond;
	
	x_fond = 64;
	y_fond = 64;
	if (c == '0')
		image = mlx_xpm_file_to_image(data.mlx_ptr, "image/sol.xpm", &x_fond, &y_fond);
	else if (c == '1')
		image = wall(x, y, data);
	else if (c == 'P')
		image = mlx_xpm_file_to_image(data.mlx_ptr, "image/face.xpm", &x_fond, &y_fond);
	else if (c == 'C')
		image = mlx_xpm_file_to_image(data.mlx_ptr, "image/boule.xpm", &x_fond, &y_fond);
	else if (c == 'E')
	{
		image = mlx_xpm_file_to_image(data.mlx_ptr, "image/door_close.xpm", &x_fond, &y_fond);
	}
	return (image);
			
}

int	main(int ac, char **av)
{
	t_data	data;
	
	(void)ac;
	data.map = is_validber(av, &data);
	if (!data.map)
		return (0);
	data.map_bis = put_in_ber(av[1], len(data.map[0]));
	if (!data.map_bis)
		return (0);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 64 * (len(data.map[0])), 64 * is_rectangle(av[1]), "yo");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 0);
	initialisation(&data);
	// printf
	//its_playable(data.map_bis, data.perso.x, data.perso.y);
	put_sol(data, data.longeur, data.largeur, data.map);
	mlx_key_hook(data.win_ptr, game, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
 	mlx_loop(data.mlx_ptr);
	return (0);
}
	