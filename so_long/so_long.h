/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:10:45 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/13 23:02:32 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include"mlx/mlx.h"
# include "printf/ft_printf.h"
# include "get_next_line_malloc/get_next_line.h"
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
	void	*chiffre_0;
	void	*chiffre_1;
	void	*chiffre_2;
	void	*chiffre_3;
	void	*chiffre_4;
	void	*chiffre_5;
	void	*chiffre_6;
	void	*chiffre_7;
	void	*chiffre_8;
	void	*chiffre_9;
	void	*renard;
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
	int			nb_pas;
}	t_data;

int		is_rectangle(char **ber);
int		len(char *s);
void	*recup_image(char c, t_data *data, int x, int y);
void	put_sol(t_data data, int longeur, int largeur, char **ber);
int		initialisation(t_data *data);
int		game(int keycode, void *param);
void	put_img(t_data *data, void *image, int y, int x);
int		its_playable(t_data *data, char **map, int x, int y);
char	**is_validber(char **av, t_data *data);
int		close_window(t_data *param, int success);
char	**put_in_ber(char *fichier);
void	free_all(char **map);
void	free_image(t_data *data);
int		count(char *line, int c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char const *s2);
int		init_image(t_data *data);
int		init_image2(t_data *data);
int		init_image3(t_data *data);
void	put_sol(t_data data, int longeur, int largeur, char **ber);
void	free_image(t_data *data);
void	*p_image(t_data *data, char *image);
int		other(char *line);
int		ft_strcmp(char *s1, char *s2);
void	pos_perso(t_data *data);
void	*p_image2(t_data *data, char *image);
int		ft_putnbrimage(t_data data, int n, int pos);
int		init_image4(t_data *data);
int		len_nb(int nb);
void	*p_image2(t_data *data, char *image);
void	pos_door(t_data *data);

#endif