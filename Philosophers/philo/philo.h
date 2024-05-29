/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:48:31 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/05/22 14:43:25 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define C_RED     "\x1b[31m"
# define C_GREEN   "\x1b[32m"
# define C_YELLOW  "\x1b[33m"
# define C_BLUE    "\x1b[34m"
# define C_MAGENTA "\x1b[35m"
# define C_CYAN    "\x1b[36m"
# define C_RESET   "\x1b[0m"
/*
# define C_RED     ""
# define C_GREEN   ""
# define C_YELLOW  ""
# define C_BLUE    ""
# define C_MAGENTA ""
# define C_CYAN    ""
# define C_RESET   ""
*/
# define FT_FORK "has taken a fork"
# define FT_EAT "is eating"
# define FT_SLEEP "is sleeping"
# define FT_THINK "is thinking"
# define FT_DIED "died"

typedef struct s_philo
{
	int				number;
	long long		last_eating;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	void			*next;
	void			*prev;
	pthread_t		thread;
	int				eat_number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_must_eat;
	long long		start;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*mutex_dead;
	int				dead;
}	t_philo;

typedef struct s_pars
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_must_eat;
	long long	start;
	t_philo		*first;
}	t_pars;

long		ft_atoi(const char *str);
void		*routine(void *arg);
long long	put_state(t_philo *philo, char *message, char *color);
int			get_is_dead(t_philo *philo);
void		set_is_dead(t_philo *philo);
long long	get_time(void);
void		ft_sleep(long long start, int period);
void		create_threads(t_pars pars);
void		create_philos(t_pars *pars, pthread_mutex_t *mutex,
				pthread_mutex_t *mutexd);
int			is_anyone_dead(t_pars pars);
int			is_all_eaten(t_pars pars);
/*
memset, printf, malloc, free, write, gettimeofday, 
usleep, 
pthread_create, pthread_detach, pthread_join, 
pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, 
pthread_mutex_unlock

◦ number_of_philosophers: The number of philosophers and also 
the number of forks.
◦ time_to_die (in milliseconds): If a philosopher didn’t start 
eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the 
simulation, they die.
◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.
*/
#endif