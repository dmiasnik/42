/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:23:16 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/11/15 15:00:39 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	do_move(int key)
{
	int	works;

	if (key == 53)
		exit(0);
	else if (key == 13)
		works = keyboard_w_s(game, command);
	if (key == 0)
		works = keyboard_a_d(game, command);
		if (key == 1)
		works = keyboard_w_s(game, command);
	if (key == 2)
		works = keyboard_a_d(game, command);
	if (works)
		adding_in_graphics(game);
	
	(void)key;
	return (1);
}