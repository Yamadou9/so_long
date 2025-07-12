/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:39:21 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/12 18:15:49 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_data *data)
{
	int	c;

	if (data->map[data->perso.y][data->perso.x + 1] == '1')
		return (0);
	if (data->map[data->perso.y][data->perso.x + 1] == 'E')
	{
		if (data->collect == 0)
			return (close_window(data, 1), 1);
	}
	data->map[data->perso.y][data->perso.x] = '0';
	c = data->map[data->perso.y][data->perso.x + 1];
	data->map[data->perso.y][data->perso.x + 1] = 'P';
	data->perso.x += 1;
	put_img(data, data->image.sol, data->perso.y, data->perso.x - 1);
	if (c == 'C')
	{
		put_img(data, data->image.collect, data->perso.y, data->perso.x);
		data->collect--;
		if (data->collect == 0)
			put_img(data, data->image.door, data->exit_y, data->exit_x);
	}
	else
		put_img(data, data->image.droit, data->perso.y, data->perso.x);
	return (1);
}

int	move_left(t_data *data)
{
	int	c;

	if (data->map[data->perso.y][data->perso.x - 1] == '1')
		return (0);
	if (data->map[data->perso.y][data->perso.x - 1] == 'E')
	{
		if (data->collect == 0)
			return (close_window(data, 1), 1);
	}
	data->map[data->perso.y][data->perso.x] = '0';
	c = data->map[data->perso.y][data->perso.x - 1];
	data->map[data->perso.y][data->perso.x - 1] = 'P';
	data->perso.x -= 1;
	put_img(data, data->image.sol, data->perso.y, data->perso.x + 1);
	if (c == 'C')
	{
		put_img(data, data->image.collect, data->perso.y, data->perso.x);
		data->collect--;
		if (data->collect == 0)
			put_img(data, data->image.door, data->exit_y, data->exit_x);
	}
	else
		put_img(data, data->image.left, data->perso.y, data->perso.x);
	return (1);
}

int	move_down(t_data *data)
{
	int	c;

	if (data->map[data->perso.y + 1][data->perso.x] == '1')
		return (0);
	if (data->map[data->perso.y + 1][data->perso.x] == 'E')
	{
		if (data->collect == 0)
			return (close_window(data, 1), 1);
	}
	data->map[data->perso.y][data->perso.x] = '0';
	c = data->map[data->perso.y + 1][data->perso.x];
	data->map[data->perso.y + 1][data->perso.x] = 'P';
	data->perso.y += 1;
	put_img(data, data->image.sol, data->perso.y - 1, data->perso.x);
	if (c == 'C')
	{
		put_img(data, data->image.collect, data->perso.y, data->perso.x);
		data->collect--;
		if (data->collect == 0)
			put_img(data, data->image.door, data->exit_y, data->exit_x);
	}
	else
		put_img(data, data->image.face, data->perso.y, data->perso.x);
	return (1);
}

int	move_up(t_data *data)
{
	int	c;

	if (data->map[data->perso.y - 1][data->perso.x] == '1')
		return (0);
	if (data->map[data->perso.y - 1][data->perso.x] == 'E')
	{
		if (data->collect == 0)
			return (close_window(data, 1), 1);
	}
	data->map[data->perso.y][data->perso.x] = '0';
	c = data->map[data->perso.y - 1][data->perso.x];
	data->map[data->perso.y - 1][data->perso.x] = 'P';
	data->perso.y -= 1;
	put_img(data, data->image.sol, data->perso.y + 1, data->perso.x);
	if (c == 'C')
	{
		put_img(data, data->image.collect, data->perso.y, data->perso.x);
		data->collect--;
		if (data->collect == 0)
			put_img(data, data->image.door, data->exit_y, data->exit_x);
	}
	else
		put_img(data, data->image.dos, data->perso.y, data->perso.x);
	return (1);
}

int	game(int keycode, void *param)
{
	t_data	*data;
	int		moved;

	moved = 0;
	data = (t_data *)param;
	if (keycode == 65363 || keycode == 'd')
		moved = move_right(data);
	if (keycode == 65361 || keycode == 'a')
		moved = move_left(data);
	if (keycode == 65364 || keycode == 's')
		moved = move_down(data);
	if (keycode == 65362 || keycode == 'w')
		moved = move_up(data);
	if (keycode == 65307)
		close_window(data, 0);
	if (moved == 1)
	{
		data->nb_pas++;
		ft_printf("Nombres de pas : %d\n", data->nb_pas);
	}
	return (0);
}
