/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:30:24 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/10/24 12:35:20 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexi(unsigned int p, int *len, int upper)
{
	char	*hex;

	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (p >= 16)
		ft_puthexi(p / 16, len, upper);
	ft_putchar(hex[p % 16], len);
}

static int	get_len(unsigned int p, int flags[])
{
	int	len;

	len = 0;
	if (p == 0 && flags[2] && !flags[7])
		return (0);
	if (p == 0)
		return (1);
	while (p)
	{
		p = p / 16;
		len++;
	}
	return (len);
}

static void	updown(int flags[], int upper, int *len, int p)
{
	if (flags[3] && p != 0)
	{
		if (upper)
			ft_putstr("0X", len);
		else
			ft_putstr("0x", len);
	}
}

void	ft_print_hexi(int p, int *len, int upper, int flags[])
{
	int	i;
	int	max;

	i = get_len(p, flags);
	max = i;
	if (flags[1] && !flags[2] && flags[6] > i)
		max = flags[6];
	else if (flags[2] && flags[7] > i)
		max = flags[7];
	if (flags[3] && p != 0)
		max += 2;
	while (!flags[0] && flags[6] - max > 0 && ++max)
		ft_putchar(' ', len);
	updown(flags, upper, len, p);
	if (flags[3] && p != 0 && !flags[2])
		i += 2;
	while (flags[1] && !flags[2] && flags[6] - i++ > 0)
		ft_putchar('0', len);
	while (flags[2] && flags[7] - i++ > 0)
		ft_putchar('0', len);
	if (!flags[2] || flags[7] || p)
		ft_puthexi(p, len, upper);
	while (flags[0] && flags[6] - max++ > 0)
		ft_putchar(' ', len);
}
