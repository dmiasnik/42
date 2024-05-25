/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:29:33 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/10/24 12:35:26 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isflag(char c)
{
	char	*flags;

	flags = "-0.# +";
	while (*flags)
	{
		if (*flags == c)
			return (1);
		flags++;
	}
	return (0);
}

static const char	*fill_num(const char *f, int flags[], int ap)
{
	if (ap)
	{
		while (*f && *f >= '0' && *f <= '9')
		{
			flags[7] = flags[7] * 10 + *f - '0';
			f++;
		}
		f--;
	}
	else
	{
		if (*f == '0' && flags[6] == 0)
			flags[1] = 1;
		while (*f && *f >= '0' && *f <= '9')
		{
			flags[6] = flags[6] * 10 + *f - '0';
			f++;
		}
		if (!*f || *f <= '0' || *f >= '*')
			f--;
	}
	return (f);
}

const char	*ft_fill_flags(const char *f, int flags[])
{
	while (*f && (isflag(*f) || (*f >= '0' && *f <= '9')))
	{
		if (*f == '-')
			flags[0] = 1;
		else if (*f == '.' && !flags[7])
		{	
			flags[2] = 1;
			f = fill_num(++f, flags, 1);
		}
		else if (*f == '#')
			flags[3] = 1;
		else if (*f == ' ')
			flags[4] = 1;
		else if (*f == '+')
			flags[5] = 1;
		else if (*f >= '0' && *f <= '9' && !flags[6])
			f = fill_num(f, flags, 0);
		f++;
	}
	if (flags[5])
		flags[4] = 0;
	if (flags[0])
		flags[1] = 0;
	return (f);
}

static void	ft_print(const char c, va_list ap, int flags[], int *len)
{
	int	i;

	i = 0;
	if (c == 'c')
		ft_print_char(va_arg(ap, int), flags, len);
	else if (c == 's')
		ft_print_string(ap, flags, len);
	else if (c == 'p')
		ft_print_hexp((unsigned long)va_arg(ap, void *), flags, len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), flags, len);
	else if (c == 'u')
		ft_putunbr(va_arg(ap, unsigned int), flags, len);
	else if (c == 'x')
		ft_print_hexi((int)va_arg(ap, int), len, 0, flags);
	else if (c == 'X')
		ft_print_hexi((int)va_arg(ap, int), len, 1, flags);
	else if (c == '%')
		ft_print_char('%', flags, len);
	while (i < 8)
		flags[i++] = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		flags[8];

	len = 0;
	while (len < 8)
		flags[len++] = 0;
	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format = ft_fill_flags(format, flags);
			ft_print(*format, ap, flags, &len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(ap);
	return (len);
}
/*
#include <stdio.h>
#include <limits.h>
int main()
{
	printf("%i", ft_printf("% .d", 0));
	printf("%c", '\n');
	printf("%i",    printf("% .d", 0));

 	return 0;
}*/
