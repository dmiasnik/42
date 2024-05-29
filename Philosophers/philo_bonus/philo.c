/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:40:41 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/05/25 17:59:28 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo, long long time)
{
	sem_wait(philo->mutex);
	if (time - philo->last_eating < philo->time_to_die)
	{
		sem_post(philo->mutex);
		return (0);
	}
	sem_post(philo->mutex);
	sem_wait(philo->mutex_print);
	printf("%-6lld %d %s%s%s\n", time - philo->start, philo->number, C_RED,
		FT_DIED, C_RESET);
	sem_post(philo->mutex_stop);
	return (1);
}

static int	is_eaten(t_philo *philo)
{
	if (!philo->next || philo->number_must_eat == INT_MAX)
		return (0);
	sem_wait(philo->mutex);
	//sem_wait(philo->mutex_print);
	if (philo->eat_number <= philo->number_must_eat)
	{
		//sem_post(philo->mutex_print);
		sem_post(philo->mutex);
		return (0);
	}
	sem_post(philo->mutex);
	//sem_post(philo->mutex_print);
	sem_post(philo->mutex_stop);
	return (1);
}

long long	put_state(t_philo *philo, char *message, char *color)
{
	long long	ms;

	sem_wait(philo->mutex_print);
	ms = get_time();
	//if (!is_dead(philo, ms) && !is_eaten(philo) && !get_is_dead(philo))
		printf("%-6lld %d %s%s%s\n", ms - philo->start, philo->number, color,
			message, C_RESET);
	sem_post(philo->mutex_print);
	return (ms);
}

void	do_work(t_philo *philo)
{
	long long	ms;

	put_state(philo, FT_FORK, C_GREEN);
	put_state(philo, FT_FORK, C_GREEN);
	ms = put_state(philo, FT_EAT, C_YELLOW);
	sem_wait(philo->mutex);
	//if (!is_dead(philo, ms) && !is_eaten(philo) && !get_is_dead(philo))
	{
		philo->last_eating = ms;
		philo->eat_number += 1;
	}
	sem_post(philo->mutex);
	//if (!get_is_dead(philo))
		ft_sleep(philo->last_eating, philo->time_to_eat);
}

void	*check_dead(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		//sem_wait(philo->mutex);
		if (!is_dead(philo, get_time()) && !is_eaten(philo))
		{
			//sem_post(philo->mutex);
			usleep(100);
			continue ;
		}
		//sem_post(philo->mutex);
		//sem_post(philo->mutex_stop);
		break ;
	}
	return (NULL);
}

void	*routine(t_philo *philo)
{
	pthread_t	thread;
	

	pthread_create(&thread, NULL, check_dead, philo);
	pthread_detach(thread);
	if (!philo->next)
		put_state(philo, FT_FORK, C_GREEN);
	while (philo->next)
	{
		sem_wait(philo->forks);
		sem_wait(philo->forks);
		do_work(philo);
		sem_post(philo->forks);
		sem_post(philo->forks);
		
		//if (!get_is_dead(philo))
		{
			//sem_wait(philo->mutex);
			ft_sleep(put_state(philo, FT_SLEEP, C_BLUE), philo->time_to_sleep);
			put_state(philo, FT_THINK, C_MAGENTA);
			//sem_post(philo->mutex);
		}
	}
	
	while (!philo->next)
	{
		usleep(1000);
		continue ;
	}
	return (NULL);
}
