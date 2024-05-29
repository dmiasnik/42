/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:35:38 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/11/12 13:08:39 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c << i++ & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

void	send_mes(int pid, char *str)
{
	while (*str)
	{
		send_char(*str, pid);
		str++;
	}
	send_char(0, pid);
}

int	check_pid(char *pid)
{
	while (*pid)
	{
		if (!ft_isdigit(*pid))
			return (0);
		pid++;
	}
	return (1);
}

int	main(int q, char *arg[])
{
	int	pid;

	if (q != 3)
		exit(1);
	if (!check_pid(arg[1]))
		exit(1);
	pid = ft_atoi(arg[1]);
	if (!pid)
		exit(1);
	if (*arg[2])
		send_mes(pid, arg[2]);
	return (0);
}
