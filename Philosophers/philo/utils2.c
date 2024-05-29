/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:01:17 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/05/22 13:29:29 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_is_dead(t_philo *philo)
{
	int	d;

	pthread_mutex_lock(philo->mutex_dead);
	d = philo->dead;
	pthread_mutex_unlock(philo->mutex_dead);
	return (d);
}

void	set_is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_dead);
	philo->dead = 1;
	pthread_mutex_unlock(philo->mutex_dead);
}

int	is_all_eaten(t_pars pars)
{
	t_philo	*philo;

	philo = pars.first;
	while (philo)
	{
		pthread_mutex_lock(philo->mutex);
		if (philo->eat_number < pars.number_must_eat)
		{
			pthread_mutex_unlock(philo->mutex);
			return (0);
		}
		pthread_mutex_unlock(philo->mutex);
		if (philo->number == pars.number_of_philosophers)
			break ;
		philo = philo->next;
	}
	return (1);
}

int	is_anyone_dead(t_pars pars)
{
	t_philo		*philo;
	long long	ms;

	philo = pars.first;
	ms = get_time();
	while (philo)
	{
		pthread_mutex_lock(philo->mutex);
		if ((ms - philo->last_eating) >= philo->time_to_die)
		{
			set_is_dead(philo);
			printf("%-6lld %d %s%s%s\n", ms - philo->start, philo->number,
				C_RED, FT_DIED, C_RESET);
			pthread_mutex_unlock(philo->mutex);
			return (1);
		}
		pthread_mutex_unlock(philo->mutex);
		if (philo->number == pars.number_of_philosophers)
			break ;
		philo = philo->next;
	}
	return (0);
}
