/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:14:48 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/05/22 14:40:13 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r')
		return (1);
	if (c == '\t' || c == '\v')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	while (*str != '\0' && ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	num = 0;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

void	ft_sleep(long long start, int period)
{
	long long	cur;

	cur = start;
	while (cur - start < period)
	{
		usleep(50);
		cur = get_time();
	}
}

long long	get_time(void)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	return (cur.tv_sec * 1000LL + cur.tv_usec / 1000);
}
