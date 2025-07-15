/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:38:12 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/15 18:45:24 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 65363 || keycode == 'd')
		data->keys.d = 1;
	if (keycode == 65361 || keycode == 'a')
		data->keys.a = 1;
	if (keycode == 65364 || keycode == 's')
		data->keys.s = 1;
	if (keycode == 65362 || keycode == 'w')
		data->keys.w = 1;
	if (keycode == 65307)
		close_window(data, 0);
	return (1);
}

int	key_release(int keycode, t_data *data)
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
}
