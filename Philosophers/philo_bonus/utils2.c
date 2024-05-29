/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:01:17 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/05/25 17:49:21 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_is_dead(t_philo *philo)
{
	int	d;

	d = philo->dead;
	return (d);
}

void	set_is_dead(t_philo *philo)
{
	philo->dead = 1;
}

int	is_all_eaten(t_pars pars)
{
	t_philo	*philo;

	philo = pars.first;
	while (philo)
	{
		//sem_wait(philo->mutex);
		if (philo->eat_number < pars.number_must_eat)
		{
			//sem_post(philo->mutex);
			return (0);
		}
		//sem_post(philo->mutex);
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
		//sem_wait(philo->mutex);
		if ((ms - philo->last_eating) >= philo->time_to_die)
		{
			//set_is_dead(philo);
			printf("%-6lld %d %s%s%s\n", ms - philo->start, philo->number,
				C_RED, FT_DIED, C_RESET);
			//sem_post(philo->mutex);
			return (1);
		}
		//sem_post(philo->mutex);
		if (philo->number == pars.number_of_philosophers)
			break ;
		philo = philo->next;
	}
	return (0);
}
