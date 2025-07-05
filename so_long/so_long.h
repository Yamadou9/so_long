/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:10:45 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/05 11:52:22 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include"mlx/mlx.h"
# include "printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include<X11/keysym.h>

typedef struct s_image
{
	void	*sol;
	void	*p_droit;
	void	*face;
}	t_image;

typedef struct s_perso
{
	int	y;
	int	x;
}	t_perso;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_perso		perso;
	char		**map;
	t_image		image;
}	t_data;

int		is_rectangle(char *ber);
int		len(char *s);
char	**is_validber(char **av);
void	*recup_image(char c, t_data data);
void	put_sol(t_data data, int longeur, int largeur, char **ber);
void	initialisation(t_data *data);
int		game(int keycode, void *param);
void	replace_image(t_data *data, void *image, int y, int x);

#endif