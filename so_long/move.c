/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:39:21 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/08 13:24:24 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_data *data, void *image, int y, int x)
{
	y = y * 64;
	x = x * 64;
	mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr, image, x, y);
}

int	move_right(t_data *data)
{
	int	c;

	if (data->map[data->perso.y][data->perso.x + 1] == 'E')
	{
		if (data->collect == 0)
			close_window(data);
	}
	else if (data->map[data->perso.y][data->perso.x + 1] != '1')
	{
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
	}
	return (1);
}


int	move_left(t_data *data)
{
	int	c;

	if (data->map[data->perso.y][data->perso.x - 1] == 'E')
	{
		if (data->collect == 0)
			close_window(data);
	}
	else if (data->map[data->perso.y][data->perso.x - 1] != '1')
	{
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
	}
	return (1);
}


int	move_down(t_data *data)
{
	int	c;

	if (data->map[data->perso.y + 1][data->perso.x] == 'E')
	{
		if (data->collect == 0)
			close_window(data);
	}
	else if (data->map[data->perso.y + 1][data->perso.x] != '1')
	{
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
	}
	return (1);
}

int	move_up(t_data *data)
{
	int	c;

	if (data->map[data->perso.y - 1][data->perso.x] == 'E')
	{
		if (data->collect == 0)
			close_window(data);
	}
	else if (data->map[data->perso.y - 1][data->perso.x] != '1')
	{
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
	}
	return (1);
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
