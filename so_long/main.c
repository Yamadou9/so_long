/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:54:52 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/05 13:11:23 by ydembele         ###   ########.fr       */
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

// int	move_right(int keycode, void *param)
// {
// 	t_data	*data;

// 	data = (t_data *)param;
// 	if (data->map[data->perso.y][data->perso.x + 1] != '1' && keycode == 65363)
// 	{
// 		data->perso.x += 1;
// 		data->map[data->perso.y][data->perso.x] = 'P';
// 		data->map[data->perso.y][data->perso.x - 1] = '0';
// 		replace_image(data, data->image.sol, data->perso.y, data->perso.x - 1);
// 		replace_image(data, data->image.face, data->perso.y, data->perso.x);
// 		return (1);
// 	}
// 	return (0);
// }

void	*recup_image(char c, t_data data)
{
	void	*image;
	int		x_fond;
	int		y_fond;
	
	x_fond = 64;
	y_fond = 64;
	if (c == '0')
		image = mlx_xpm_file_to_image(data.mlx_ptr, "image/sol.xpm", &x_fond, &y_fond);
	else if (c == '1')
		image = mlx_xpm_file_to_image(data.mlx_ptr, "image/soljaune.xpm", &x_fond, &y_fond);
	else if (c == 'P')
		image = mlx_xpm_file_to_image(data.mlx_ptr, "image/face.xpm", &x_fond, &y_fond);
	else if (c == 'C')
		image = mlx_xpm_file_to_image(data.mlx_ptr, "image/sol_death_door_1.xpm", &x_fond, &y_fond);
	else if (c == 'E')
		image = mlx_xpm_file_to_image(data.mlx_ptr, "image/1.xpm", &x_fond, &y_fond);
	return (image);
			
}

int	main(int ac, char **av)
{
	t_data	data;
	
	(void)ac;
	data.map = is_validber(av);
	if (!data.map)
		return (0);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 64 * (len(data.map[0])), 64 * is_rectangle(av[1]), "yo");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 0);
	put_sol(data, is_rectangle(av[1]), len(data.map[0]), data.map);
	initialisation(&data);
	mlx_key_hook(data.win_ptr, game, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	// mlx_key_hook(data.win_ptr, on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
	