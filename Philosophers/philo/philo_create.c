/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:03:27 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/05/22 15:06:37 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_pars pars)
{
	t_philo	*philo;

	philo = pars.first;
	while (philo->number <= pars.number_of_philosophers)
	{
		pthread_create(&philo->thread, NULL, &routine, philo);
		if (philo->number == pars.number_of_philosophers)
			break ;
		usleep(10);
		philo = philo->next;
	}
}

void	init_philo(t_pars *pars, t_philo *philo, t_philo *philo_prev)
{
	philo->right_fork = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->right_fork, NULL);
	philo->last_eating = pars->start;
	philo->start = pars->start;
	philo->time_to_die = pars->time_to_die;
	philo->time_to_eat = pars->time_to_eat;
	philo->time_to_sleep = pars->time_to_sleep;
	philo->number_must_eat = pars->number_must_eat;
	philo->dead = 0;
	philo->eat_number = 0;
	philo->left_fork = NULL;
	if (philo_prev)
		philo_prev->next = philo;
	if (philo_prev)
		philo->left_fork = philo_prev->right_fork;
}

void	create_philos(t_pars *pars, pthread_mutex_t *mutex,
	pthread_mutex_t *mutexd)
{
	t_philo	*philo;
	t_philo	*philo_prev;
	int		i;

	i = 0;
	philo_prev = NULL;
	while (++i <= pars->number_of_philosophers)
	{
		philo = malloc(sizeof(t_philo));
		philo->number = i;
		philo->prev = philo_prev;
		philo->mutex = mutex;
		philo->mutex_dead = mutexd;
		init_philo(pars, philo, philo_prev);
		if (i == 1)
			pars->first = philo;
		philo_prev = philo;
	}
	if (pars->number_of_philosophers != 1)
		pars->first->prev = philo;
	if (pars->number_of_philosophers != 1)
		pars->first->left_fork = philo_prev->right_fork;
	if (philo_prev)
		philo_prev->next = pars->first;
}
