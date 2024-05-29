/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:35:48 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/11/12 13:09:07 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	fill_char(char *str, int pos, int sig)
{
	char	c;

	if (!str)
		return ;
	c = str[pos];
	c = c << 1;
	if (sig == SIGUSR1)
		c = c + 1;
	str[pos] = c;
}

void	init_str(char **str, int pos)
{
	char	*nstr;
	int		len;

	len = 1000;
	if (*str == NULL)
	{
		*str = malloc(sizeof(char) * (len + 1));
		ft_memset(*str, 0, len + 1);
	}
	else if (pos && pos % len == 0)
	{
		nstr = malloc(sizeof(char) * (pos + len + 1));
		ft_memset(nstr, 0, pos + len + 1);
		ft_memcpy(nstr, *str, pos);
		free(*str);
		*str = nstr;
	}
}

void	func(int sig)
{
	static int	i;
	static int	pos;
	static char	*str;

	if (sig != SIGUSR1 && sig != SIGUSR2)
		return ;
	if (i % 8 == 0)
		init_str(&str, pos);
	fill_char(str, pos, sig);
	if (++i == 8)
	{
		i = 0;
		pos++;
		if (!str[pos - 1])
		{
			ft_putstr_fd(str, 1);
			free(str);
			str = NULL;
			pos = 0;
		}
	}
}

int	main(int q, char *arg[])
{
	(void)q;
	(void)arg;
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, func);
	signal(SIGUSR2, func);
	while (1)
		pause();
	return (0);
}
