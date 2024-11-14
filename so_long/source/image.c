/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:01:00 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/01/06 14:45:06 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_images(t_par *par)
{
	int	i;
	int	j;

	par->back = mlx_xpm_file_to_image(par->mlx,
			"images/floor.xpm", &i, &j);
	par->wall = mlx_xpm_file_to_image(par->mlx,
			"images/wall.xpm", &i, &j);
	par->player = mlx_xpm_file_to_image(par->mlx,
			"images/player.xpm", &i, &j);
	par->map_exit = mlx_xpm_file_to_image(par->mlx,
			"images/exit.xpm", &i, &j);
	par->collectible = mlx_xpm_file_to_image(par->mlx,
			"images/item.xpm", &i, &j);
	if (!par->back || !par->collectible || !par->player || !par->wall
		|| !par->map_exit)
		show_err(par, 1);
}

void	*get_image(t_par *par, char c)
{
	if (c == '0')
		return (par->back);
	if (c == '1')
		return (par->wall);
	if (c == 'C')
		return (par->collectible);
	if (c == 'E')
		return (par->map_exit);
	if (c == 'P')
		return (par->player);
	return (NULL);
}

void	put_image(t_par *par, char image, int i, int j)
{
	void	*im;

	im = get_image(par, image);
	mlx_put_image_to_window(par->mlx, par->win, im, i * 40, j * 40);
}

void	load_images(t_par par)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < par.x)
	{
		j = 0;
		while (j < par.y)
		{
			put_image(&par, par.map[i + j * (par.x + 1)], i, j);
			j++;
		}
		i++;
	}
}
