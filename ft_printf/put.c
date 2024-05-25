/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:30:34 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/10/24 12:36:33 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	if (*len < 0)
		return ;
	if (write(1, &c, 1) == -1)
	{
		*len = -1;
		return ;
	}
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	while (*str)
		ft_putchar(*str++, len);
}

void	ft_print_char(char c, int flags[], int *len)
{
	int	i;

	i = flags[6];
	while (!flags[0] && i-- - 1 > 0)
		ft_putchar(' ', len);
	ft_putchar(c, len);
	while (flags[0] && i-- - 1 > 0)
		ft_putchar(' ', len);
}

void	ft_print_string(va_list ap, int flags[], int *len)
{
	char	*str;
	int		i;
	int		max;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	i = 0;
	while (str[i])
		i++;
	max = i;
	if (flags[2] && flags[7] < max)
		max = flags[7];
	i = max;
	while (!flags[0] && flags[6] - i++ > 0)
		ft_putchar(' ', len);
	while (*str)
	{
		if (flags[2] && !max--)
			break ;
		ft_putchar(*str++, len);
	}
	while (flags[0] && flags[6] - i++ > 0)
		ft_putchar(' ', len);
}
