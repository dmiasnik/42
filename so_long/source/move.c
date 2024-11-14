/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:23:16 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/01/06 15:01:45 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void static	putsteps(t_par *par)
{
	char	*t;

	put_image(par, '1', 0, 0);
	par->steps++;
	t = ft_itoa(par->steps);
	mlx_string_put(par->mlx, par->win, 10, 15, 255, t);
	free(t);
	ft_putstr_fd("Number of movements: \033[0;31m", 1);
	ft_putnbr_fd(par->steps, 1);
	ft_putstr_fd("\033[0m\n", 1);
}

int	no_col(t_par *par)
{
	char	*str;

	str = par->map;
	while (*str)
	{
		if (*str == 'C')
			return (0);
		str++;
	}
	return (1);
}

void	step_up(t_par *par, int n)
{
	char	im;

	im = par->map[n];
	if (im == '0' || im == 'C')
	{
		par->map[n] = 'P';
		par->map[par->i] = '0';
		par->i = n;
		load_images(*par);
		putsteps(par);
	}
	else if (im == 'E' && no_col(par))
	{
		prog_exit(par);
	}
}

int	do_move(int key, t_par *par)
{
	if (key == 53)
		prog_exit(par);
	else if (key == 123)
		step_up(par, par->i - 1);
	if (key == 124)
		step_up(par, par->i + 1);
	if (key == 125)
		step_up(par, par->i + par->x + 1);
	if (key == 126)
		step_up(par, par->i - par->x - 1);
	return (1);
}
