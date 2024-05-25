/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:30:24 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/10/24 12:35:59 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(size_t p, int *len, int upper)
{
	char	*hex;

	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (p >= 16)
		ft_puthex(p / 16, len, upper);
	ft_putchar(hex[p % 16], len);
}

static int	get_len(size_t p)
{
	int	len;

	len = 0;
	if (p == 0)
		return (1);
	while (p)
	{
		p = p / 16;
		len++;
	}
	return (len);
}

void	ft_print_hexp(size_t p, int flags[], int *len)
{
	int	i;

	i = get_len(p) + 2;
	while (!flags[0] && flags[6] - i++ > 0)
		ft_putchar(' ', len);
	ft_putstr("0x", len);
	ft_puthex(p, len, 0);
	while (flags[0] && flags[6] - i++ > 0)
		ft_putchar(' ', len);
}
