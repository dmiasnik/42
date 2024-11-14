/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:30:24 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/01/06 13:57:09 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_par *par, char	*path)
{
	int		f;
	char	*str;
	char	*t;
	char	*tmp;

	f = open(path, 0);
	if (f < 0)
		show_err(par, 0);
	str = malloc(sizeof(char));
	str[0] = '\0';
	while (1)
	{
		tmp = get_next_line(f);
		if (!tmp)
			break ;
		t = ft_strjoin(str, tmp);
		free(tmp);
		free(str);
		str = t;
		par->y++;
	}
	close(f);
	par->map = str;
	while (str && str[par->x] && str[par->x] != '\n')
		par->x++;
}

int	fill_map(char *str, int i, int x)
{
	int	res;

	res = 0;
	if (str[i - x - 1] != '1' && str[i - x - 1] != 'P')
	{
		str[i - x - 1] = 'P';
		res = 1;
	}
	if (str[i + x + 1] != '1' && str[i + x + 1] != 'P')
	{
		str[i + x + 1] = 'P';
		res = 1;
	}
	if (str[i - 1] != '1' && str[i - 1] != 'P')
	{
		str[i - 1] = 'P';
		res = 1;
	}
	if (str[i + 1] != '1' && str[i + 1] != 'P')
	{
		str[i + 1] = 'P';
		res = 1;
	}
	return (res);
}

int	no_sol(t_par *par)
{
	char	*str;
	int		i;
	int		res;

	str = ft_strdup(par->map);
	while (1)
	{
		i = 0;
		res = 0;
		while (str[i])
			if (str[i++] == 'P')
				res = res + fill_map(str, i - 1, par->x);
		if (res == 0)
			break ;
	}
	if (ft_strchr(str, 'C') || ft_strchr(str, 'E'))
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int	check_map(t_par *par)
{
	char	*m;
	size_t	i;
	size_t	j;

	m = par->map;
	i = 0;
	while (m[i])
	{
		j = i / (par->x + 1);
		if (j == 0 && m[i] != '1' && i < par->x)
			show_err(par, 1);
		else if (j != 0 && j != par->y - 1 && i % (par->x + 1) == 0
			&& m[i] != '1')
			show_err(par, 1);
		else if (j != 0 && j != par->y - 1 && i % (par->x + 1) == par->x - 1
			&& m[i] != '1')
			show_err(par, 1);
		else if (j == par->y - 1 && m[i] != '1')
			show_err(par, 1);
		i++;
	}
	if (no_sol(par))
		show_err(par, 1);
	return (1);
}

int	load_map(t_par *par, char *path)
{
	char	*n;

	n = ft_strnstr(path, ".ber", ft_strlen(path));
	if (!n || ft_strlen(n) != 4)
		return (0);
	read_map(par, path);
	n = par->map;
	while (*n)
	{
		if (*n != '1' && *n != '0' && *n != 'E' && *n != 'C' && *n != 'P'
			&& *n != '\n')
			show_err(par, 1);
		n++;
	}
	if (ft_strlen(par->map) != par->x * par->y + par->y - 1 || !check_map(par)
		|| !ft_strchr(par->map, 'C'))
		show_err(par, 1);
	n = ft_strchr(par->map, 'E');
	if (!n || ft_strchr(n + 1, 'E'))
		show_err(par, 1);
	n = ft_strchr(par->map, 'P');
	if (!n || ft_strchr(n + 1, 'P'))
		show_err(par, 1);
	par->i = n - par->map;
	return (1);
}
