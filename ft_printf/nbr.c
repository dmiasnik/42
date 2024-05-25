/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:30:08 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/10/24 12:36:17 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr(int i, int zero, int *len)
{
	if (i < 0)
	{
		ft_putchar('-', len);
		while (zero-- > 0)
			ft_putchar('0', len);
		if (i == -2147483648)
		{
			ft_putstr("2147483648", len);
			return ;
		}
		i = -i;
	}
	if (i >= 10)
		putnbr(i / 10, 0, len);
	ft_putchar(i % 10 + '0', len);
}

int	get_len(int i, int flags[])
{
	int	len;

	if (i == 0 && flags[2] && !flags[7])
		return (0);
	if (i == 0)
		return (1);
	len = 0;
	if (i < 0)
		len++;
	while (i)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

static int	get_zero(int i, int len, int flags[])
{
	int	zero;

	zero = 0;
	if (!flags[1] && !flags[2])
		return (zero);
	if (flags[2] && i >= 0 && flags[7] > len)
		zero = flags[7] - len;
	else if (flags[2] && i < 0 && flags[7] > len - 1)
		zero = flags[7] - len + 1;
	else if (flags[1] && !flags[2] && flags[6] > len)
		zero = flags[6] - len;
	if (flags[4] && !flags[2] && i >= 0)
		zero--;
	if (flags[5] && !flags[2] && i >= 0)
		zero--;
	return (zero);
}

void	ft_putnbr(int i, int flags[], int *len)
{
	int		j;
	int		zero;
	int		z;
	char	c;

	j = get_len(i, flags);
	zero = get_zero(i, j, flags);
	if (flags[5] && i >= 0)
		j++;
	if (flags[4] && i >= 0 && ++j)
		ft_putchar(' ', len);
	c = ' ';
	if (flags[1] && !flags[2])
		c = '0';
	while (!flags[0] && flags[6] - zero - j > 0 && ++j)
		ft_putchar(c, len);
	if (flags[5] && i >= 0)
		ft_putchar('+', len);
	z = zero;
	while (i >= 0 && z-- > 0)
		ft_putchar('0', len);
	if (!flags[2] || flags[7] || i)
		putnbr(i, zero, len);
	while (flags[0] && flags[6] - zero - j++ > 0)
		ft_putchar(' ', len);
}
