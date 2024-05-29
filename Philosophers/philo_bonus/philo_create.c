/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:03:27 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/05/25 17:48:57 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checking_dead(t_pars pars)
{
	t_philo	*philo;

	philo = pars.first;
	while (philo)
	{
		waitpid(philo->pid, NULL, 0);		
		if (philo->number == pars.number_of_philosophers)
			break ;
		philo = philo->next;
	}
}

void	create_threads(t_pars pars)
{
	t_philo	*philo;

	philo = pars.first;
	while (philo->number <= pars.number_of_philosophers)
	{		
		philo->pid = fork();
		if (philo->pid == 0)
		{
			routine(philo);
			exit(0);
		}
		if (philo->number == pars.number_of_philosophers)
			break ;
		usleep(100);
		philo = philo->next;
	}
	//checking_dead(pars);
}

void	init_philo(t_pars *pars, t_philo *philo, t_philo *philo_prev)
{
	philo->last_eating = pars->start;
	philo->start = pars->start;
	philo->time_to_die = pars->time_to_die;
	philo->time_to_eat = pars->time_to_eat;
	philo->time_to_sleep = pars->time_to_sleep;
	philo->number_must_eat = pars->number_must_eat;
	philo->dead = 0;
	philo->eat_number = 0;
	philo->forks = pars->forks;
	if (philo_prev)
		philo_prev->next = philo;
}

void	create_philos(t_pars *pars)
{
	t_philo	*philo;
	t_philo	*philo_prev;
	int		i;

	i = 0;
	philo_prev = NULL;
	while (++i <= pars->number_of_philosophers)
	{
		philo = malloc(sizeof(t_philo));
		memset(philo, 0, sizeof(t_philo));
		philo->number = i;
		philo->prev = philo_prev;
		philo->mutex = pars->mutex;
		philo->mutex_stop = pars->mutex_stop;
		philo->mutex_print = pars->mutex_print;
		init_philo(pars, philo, philo_prev);
		if (i == 1)
			pars->first = philo;
		philo_prev = philo;
	}
	if (pars->number_of_philosophers != 1)
		pars->first->prev = philo;
	if (philo_prev && pars->number_of_philosophers != 1)
		philo_prev->next = pars->first;
}
