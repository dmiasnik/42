/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:30:08 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/10/24 12:36:49 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putunbr(unsigned int i, int *len)
{
	if (i >= 10)
		putunbr(i / 10, len);
	ft_putchar(i % 10 + '0', len);
}

static int	get_len(unsigned int i, int flags[])
{
	int	len;

	len = 0;
	if (i == 0 && flags[2] && !flags[7])
		return (0);
	if (i == 0)
		return (1);
	while (i)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

void	ft_putunbr(unsigned int i, int flags[], int *len)
{
	int		j;
	char	c;
	int		max;
	int		k;

	if (flags[4] && i >= 0)
		ft_putchar(' ', len);
	if (flags[5] && i > 0)
		ft_putchar('+', len);
	j = get_len(i, flags);
	c = ' ';
	if (flags[1] && !flags[2])
		c = '0';
	max = j;
	if (flags[7] > max)
		max = flags[7];
	k = max;
	while (!flags[0] && flags[6] - k > 0 && ++k)
		ft_putchar(c, len);
	while (flags[2] && max - j++ > 0)
		ft_putchar('0', len);
	if (!flags[2] || flags[7] || i)
		putunbr(i, len);
	while (flags[0] && flags[6] - max++ > 0)
		ft_putchar(' ', len);
}
