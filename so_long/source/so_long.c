/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:35:40 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/11/15 14:40:26 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int q, char *a[])
{
	char	*n;
	char	*map;
	void	*mlx;
	void	*win;

	if (q != 2)
		return (1);
	map = a[1];
	n = ft_strnstr(map, ".ber", ft_strlen(map));
	if (!n || ft_strlen(n) != 4)
		return (1);
	if (!check_map(map))
		return (1);
	mlx = mlx_init();
	win = mlx_new_window(mlx, (400), (400), "so_long");
	//load_images();	
	mlx_key_hook(win, &do_move, 0);
	mlx_hook(win, 17, 0, (void *)exit, 0);
	mlx_loop(mlx);
	return (0);
}