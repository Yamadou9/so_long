/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:10:45 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/08 16:46:10 by ydembele         ###   ########.fr       */
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
	void	*droit;
	void	*face;
	void	*left;
	void	*dos;
	void	*cointbd;
	void	*cointhg;
	void	*cointhd;
	void	*cointbg;
	void	*mur_haut;
	void	*mur_gauche;
	void	*mur_droit;
	void	*mur_bas;
	void	*collect;
	void	*door;
	void	*boule;
	void	*trou;
	void	*door_close;
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
	char		**map_bis;
	t_image		image;
	int			largeur;
	int			longeur;
	int			collect;
	int			exit_y;
	int			exit_x;
}	t_data;

int		is_rectangle(char *ber);
int		len(char *s);
void	*recup_image(char c, t_data *data, int x, int y);
void	put_sol(t_data data, int longeur, int largeur, char **ber);
void	initialisation(t_data *data);
int		game(int keycode, void *param);
void	put_img(t_data *data, void *image, int y, int x);
void	its_playable(char **map, int x, int y);
char	**is_validber(char **av, t_data *data);
int		close_window(t_data *param);
char	**put_in_ber(char *fichier, int longeur);
void	free_all(char **map);
void	free_image(t_data *data);

#endif