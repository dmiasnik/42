/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:35:40 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/03/01 12:55:10 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_err(t_par *par, int err)
{
	if (err == 0)
		ft_putstr_fd(strerror(errno), 1);
	else if (err == 1)
		ft_putstr_fd("Error\nMap is incorrect\n", 1);
	prog_exit(par);
}

void	prog_exit(t_par *par)
{
	if (par->wall)
		mlx_destroy_image(par->mlx, par->wall);
	if (par->player)
		mlx_destroy_image(par->mlx, par->player);
	if (par->collectible)
		mlx_destroy_image(par->mlx, par->collectible);
	if (par->back)
		mlx_destroy_image(par->mlx, par->back);
	if (par->map_exit)
		mlx_destroy_image(par->mlx, par->map_exit);
	if (par->win)
		mlx_destroy_window(par->mlx, par->win);
	if (par->map)
		free(par->map);
	exit(0);
}

int	main(int q, char *a[])
{
	t_par	par;

	if (q != 2)
		return (1);
	par.wall = NULL;
	par.player = NULL;
	par.collectible = NULL;
	par.back = NULL;
	par.map_exit = NULL;
	if (!load_map(&par, a[1]))
		return (1);
	par.steps = 0;
	par.mlx = mlx_init();
	par.win = mlx_new_window(par.mlx, par.x * 40, par.y * 40, "so_long");
	fill_images(&par);
	load_images(par);
	mlx_key_hook(par.win, do_move, &par);
	mlx_hook(par.win, 17, 0, (void *)prog_exit, &par);
	mlx_loop(par.mlx);
	return (0);
}
