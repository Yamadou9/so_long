/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:38:12 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/18 18:12:46 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	key_release(int keycode, t_data *data)
{
	if (keycode == 65363 || keycode == 'd')
		data->keys.d = 0;
	if (keycode == 65361 || keycode == 'a')
		data->keys.a = 0;
	if (keycode == 65364 || keycode == 's')
		data->keys.s = 0;
	if (keycode == 65362 || keycode == 'w')
		data->keys.w = 0;
	if (keycode == 65307)
		close_window(data, 0);
	return (1);
}*/

// int	key_press(int keycode, t_data *data)
// {
// 	int		moved;

// 	moved = 0;
// 	if (keycode == 65363 || keycode == 'd')
// 		moved = move_right(data);
// 	if (keycode == 65361 || keycode == 'a')
// 		moved = move_left(data);
// 	if (keycode == 65364 || keycode == 's')
// 		moved = move_down(data);
// 	if (keycode == 65362 || keycode == 'w')
// 		data->keys.w = 1;
// 	if (keycode == 65307)
// 		moved = move_up(data);
// 	if (moved == 1)
// 	{
// 		data->nb_pas++;
// 		ft_printf("Nombres de pas : %d\n", data->nb_pas);
// 		ft_putnbrimage(*data, data->nb_pas, len_nb(data->nb_pas) - 1);
// 	}
// 	return (1);
// }

/*int	game(void *param)
{
	t_data	*data;
	int		moved;

	moved = 0;
	data = (t_data *)param;
	if (data->move_delay++ != 9999)
		return (0);
	data->move_delay = 0;
	if ((*data).keys.d == 1)
		moved = move_right(data);
	if ((*data).keys.a == 1)
		moved = move_left(data);
	if ((*data).keys.s == 1)
		moved = move_down(data);
	if ((*data).keys.w == 1)
		moved = move_up(data);
	if (moved == 1)
	{
		data->nb_pas++;
		ft_printf("Nombres de pas : %d\n", data->nb_pas);
		ft_putnbrimage(*data, data->nb_pas, len_nb(data->nb_pas) - 1);
	}
	return (0);
}*/
