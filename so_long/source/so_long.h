/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:39:48 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/01/03 14:42:04 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <unistd.h>
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_par
{
	void	*mlx;
	void	*win;	

	void	*wall;
	void	*collectible;
	void	*map_exit;
	void	*player;
	void	*back;

	size_t	x;
	size_t	y;

	char	*map;

	int		steps;

	size_t	i;
}	t_par;

int		load_map(t_par *par, char *path);
int		do_move(int key, t_par *par);
void	load_images(t_par par);
void	prog_exit(t_par *par);
void	show_err(t_par *par, int err);
void	put_image(t_par *par, char image, int i, int j);
void	fill_images(t_par *par);

#endif