/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:49:15 by ydembele          #+#    #+#             */
/*   Updated: 2025/07/11 17:05:57 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_countword(char const *s, char c)
{
	int		set;
	int		i;
	int		word;

	word = 0;
	i = 0;
	set = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (set == 1 && s[i] != c)
		{
			word++;
			set = 0;
		}
		else if (s[i] == c)
			set = 1;
		i++;
	}
	return (word);
}

int	len_set(char const *s, int o, char c)
{
	int	i;

	i = 0;
	while (s[o] && s[o] == c)
				o++;
	while (s[o] && s[o] != c)
	{
		i++;
		o++;
	}
	return (i);
}

int	ft_cpy(const char *s, int i, char *res, char c)
{
	int	r;

	r = 0;
	while (s[i] != c && s[i])
		res[r++] = s[i++];
	res[r] = 0;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (j < ft_countword(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		res[j] = malloc(sizeof(char) * len_set(s, i, c) + 1);
		if (res[j] == NULL)
		{
			free_all(res);
			return (NULL);
		}
		i = ft_cpy(s, i, res[j], c);
		j++;
	}
	res[j] = NULL;
	return (res);
}
