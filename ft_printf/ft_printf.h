/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:29:13 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/10/24 12:35:35 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);

void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_print_char(char c, int flags[], int *len);
void	ft_print_string(va_list ap, int flags[], int *len);
void	ft_putnbr(int i, int flags[], int *len);
void	ft_putunbr(unsigned int i, int flags[], int *len);
void	ft_print_hexp(size_t p, int flags[], int *len);
void	ft_print_hexi(int p, int *len, int upper, int flags[]);

#endif
