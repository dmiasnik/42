/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:40:41 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/05/22 17:39:44 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo, long long time)
{
	t_philo	*start;

	if (get_is_dead(philo))
		return (1);
	if (time - philo->last_eating < philo->time_to_die)
		return (0);
	start = philo;
	philo = philo->next;
	while (philo)
	{
		set_is_dead(philo);
		philo = philo->next;
		if (!philo || philo->number == start->number)
			break ;
	}
	set_is_dead(start);
	return (1);
}

static int	is_eaten(t_philo *philo)
{
	t_philo	*start;

	if (!philo->next || philo->number_must_eat == INT_MAX)
		return (0);
	start = philo;
	while (philo)
	{
		if (philo->eat_number < philo->number_must_eat)
			return (0);
		philo = philo->next;
		if (philo->number == start->number)
			break ;
	}
	philo = start;
	while (philo)
	{
		set_is_dead(philo);
		philo = philo->next;
		if (philo->number == start->number)
			break ;
	}
	return (1);
}

long long	put_state(t_philo *philo, char *message, char *color)
{
	long long	ms;

	pthread_mutex_lock(philo->mutex);
	ms = get_time();
	if (!is_dead(philo, ms) && !is_eaten(philo) && !get_is_dead(philo))
		printf("%-6lld %d %s%s%s\n", ms - philo->start, philo->number, color,
			message, C_RESET);
	pthread_mutex_unlock(philo->mutex);
	return (ms);
}

void	do_work(t_philo *philo)
{
	long long	ms;

	put_state(philo, FT_FORK, C_GREEN);
	put_state(philo, FT_FORK, C_GREEN);
	ms = put_state(philo, FT_EAT, C_YELLOW);
	pthread_mutex_lock(philo->mutex);
	if (!is_dead(philo, ms) && !is_eaten(philo) && !get_is_dead(philo))
	{
		philo->last_eating = ms;
		philo->eat_number++;
	}
	pthread_mutex_unlock(philo->mutex);
	if (!get_is_dead(philo))
		ft_sleep(philo->last_eating, philo->time_to_eat);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (!philo->left_fork)
		put_state(philo, FT_FORK, C_GREEN);
	while (philo->left_fork && !get_is_dead(philo))
	{		
		if (pthread_mutex_lock(philo->left_fork) != 0)
			continue ;
		if (pthread_mutex_lock(philo->right_fork) != 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			continue ;
		}
		do_work(philo);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		if (!get_is_dead(philo))
		{
			ft_sleep(put_state(philo, FT_SLEEP, C_BLUE), philo->time_to_sleep);
			put_state(philo, FT_THINK, C_MAGENTA);
		}
	}
	return (NULL);
}
