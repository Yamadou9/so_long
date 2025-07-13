/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:44:05 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/13 14:37:45 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*p_image2(t_data *data, char *image)
{
	int		x;
	int		y;
	void	*img;

	x = 12;
	y = 12;
	img = mlx_xpm_file_to_image((*data).mlx_ptr, image, &x, &y);
	if (!img)
		return (0);
	return (img);
}

int	len_nb(int nb)
{
	int	len;

	len = 1;
	while (nb >= 10)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int	ft_putnbrimage(t_data data, int n, int pos)
{
	int		i;
	int		y;
	void	**digits;
	int		digit;

	i = 12;
	y = 0;
	digits = (void *[]){
		data.image.chiffre_0, data.image.chiffre_1,
		data.image.chiffre_2, data.image.chiffre_3,
		data.image.chiffre_4, data.image.chiffre_5,
		data.image.chiffre_6, data.image.chiffre_7,
		data.image.chiffre_8, data.image.chiffre_9};
	if (n == 0)
	{
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			digits[0], pos * i, y);
		return (1);
	}
	if (n >= 10)
		ft_putnbrimage(data, n / 10, pos - 1);
	digit = n % 10;
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		digits[digit], pos * i, y);
	return (1);
}
