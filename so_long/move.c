/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:39:21 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/05 13:33:25 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	replace_image(t_data *data, void *image, int y, int x)
{
	y = y * 64;
	x = x * 64;
	mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr, image, x, y);
}

int	move_right(t_data *data)
{
	int	y;
	int	x;

	x = data->perso.x;
	y = data->perso.y;
	if (data->map[y][x + 1] != '1')
	{
		data->map[y][x] = '0';
		data->map[y][x + 1] = 'P';
		data->perso.x += 1;
		replace_image(data, data->image.sol, data->perso.y, data->perso.x - 1);
		replace_image(data, data->image.droit, data->perso.y, data->perso.x);
		return (1);
	}
	return (0);
}

int	move_left(t_data *data)
{
	int	y;
	int	x;

	x = data->perso.x;
	y = data->perso.y;
	if (data->map[y][x - 1] != '1')
	{
		data->map[y][x] = '0';
		data->map[y][x - 1] = 'P';
		data->perso.x -= 1;
		replace_image(data, data->image.sol, data->perso.y, data->perso.x + 1);
		replace_image(data, data->image.left, data->perso.y, data->perso.x);
		return (1);
	}
	return (0);
}

int	move_down(t_data *data)
{
	int	y;
	int	x;

	x = data->perso.x;
	y = data->perso.y;
	if (data->map[y + 1][x] != '1')
	{
		data->map[y][x] = '0';
		data->map[y + 1][x] = 'P';
		data->perso.y += 1;
		replace_image(data, data->image.sol, data->perso.y - 1, data->perso.x);
		replace_image(data, data->image.face, data->perso.y, data->perso.x);
		return (1);
	}
	return (0);
}

int	move_up(t_data *data)
{
	int	y;
	int	x;

	x = data->perso.x;
	y = data->perso.y;
	if (data->map[y - 1][x] != '1')
	{
		data->map[y][x] = '0';
		data->map[y - 1][x] = 'P';
		data->perso.y -= 1;
		replace_image(data, data->image.sol, data->perso.y + 1, data->perso.x);
		replace_image(data, data->image.dos, data->perso.y, data->perso.x);
		return (1);
	}
	return (0);
}

int	game(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65363)
		move_right(data);
	if (keycode == 65361)
		move_left(data);
	if (keycode == 65364)
		move_down(data);
	if (keycode == 65362)
		move_up(data);
	return (0);
}
