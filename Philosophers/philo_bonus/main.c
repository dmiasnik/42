/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:43:32 by dmiasnik          #+#    #+#             */
/*   Updated: 2024/05/25 17:48:51 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_number(char *arg)
{
	int		i;
	long	a;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	a = ft_atoi(arg);
	if (a > INT_MAX || a < INT_MIN || i > 10)
		return (0);
	return (1);
}

static int	fill_pars(int a, char **args, t_pars *pars)
{
	if (a < 5 || a > 6)
	{
		printf("Args: number_of_philosophers  time_to_die  time_to_eat  ");
		printf("time_to_sleep  [number_of_times_each_philosopher_must_eat]\n");
		return (0);
	}
	pars->number_of_philosophers = ft_atoi(args[1]);
	pars->time_to_die = ft_atoi(args[2]);
	pars->time_to_eat = ft_atoi(args[3]);
	pars->time_to_sleep = ft_atoi(args[4]);
	pars->number_must_eat = INT_MAX;
	if (a == 6)
		pars->number_must_eat = ft_atoi(args[5]);
	if (pars->number_of_philosophers < 1 || pars->time_to_die < 0
		|| pars->time_to_eat < 0 || pars->time_to_sleep < 0
		|| pars->number_must_eat < 0 || !is_number(args[1])
		|| !is_number(args[2]) || !is_number(args[3]) || !is_number(args[4])
		|| (a == 6 && !is_number(args[5])))
	{
		printf("Wrong args!\n");
		return (0);
	}
	pars->start = get_time();
	return (1);
}

void	free_pars(t_pars pars)
{
	t_philo	*philo;
	t_philo	*tmp;

	philo = pars.first;
	while (philo)
	{
		tmp = philo->next;
		kill(philo->pid, SIGKILL);
		if (philo->number == pars.number_of_philosophers)
		{
			free(philo);
			break ;
		}
		free(philo);
		philo = tmp;
	}
	pars.first = NULL;
}

int	main(int a, char **args)
{
	t_pars	pars;

	if (!fill_pars(a, args, &pars))
		return (1);

	sem_unlink("forks");
	sem_unlink("mutex");
	sem_unlink("stop");
	sem_unlink("print");
	
	pars.forks = sem_open("forks", O_CREAT, S_IRWXU, pars.number_of_philosophers);
	pars.mutex = sem_open("mutex", O_CREAT, S_IRWXU, 1);
	pars.mutex_stop = sem_open("stop", O_CREAT, S_IRWXU, 1);
	pars.mutex_print = sem_open("print", O_CREAT, S_IRWXU, 1);
	create_philos(&pars);
	sem_wait(pars.mutex_stop);
	create_threads(pars);
	sem_wait(pars.mutex_stop);
	free_pars(pars);
	sem_close(pars.forks);
	sem_close(pars.mutex);
	sem_close(pars.mutex_stop);
	sem_unlink("forks");
	sem_unlink("mutex");
	sem_unlink("stop");
	sem_unlink("print");
	return (0);
}
/*
gcc *.c -o philo.exe
.\philo.exe 3 800 200 300 5


There are as many forks as philosophers.

Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.

When a philosopher has finished eating, they put their forks back on the table 
and start sleeping. Once awake, they start thinking again. The simulation stops 
when a philosopher dies of starvation.

Each philosopher has a number ranging from 1 to number_of_philosophers.

Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and 
philosopher number N + 1.

A message announcing a philosopher died should be displayed no more than 10 ms
after the actual death of the philosopher.

Each philosopher has a number ranging from 1 to number_of_philosophers

Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and 
philosopher number N + 1.

Any state change of a philosopher must be formatted as follows:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.

Here are the things you need to know if you want to succeed this assignment:
• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
• There are also forks on the table. There are as many forks as philosophers.
• Because serving and eating spaghetti with only one fork is very inconvenient,
a philosopher takes their right and their left forks to eat, one in each hand.
• When a philosopher has finished eating, they put their forks back on the 
table and start sleeping. Once awake, they start thinking again. The simulation
stops when a philosopher dies of starvation.

Each philosopher should be a thread.
• There is one fork between each pair of philosophers. Therefore, if there are 
several philosophers, each philosopher has a fork on their left side and a fork
on their right side. If there is only one philosopher, there should be only one
fork on the table.
• To prevent philosophers from duplicating forks, you should protect the forks 
state with a mutex for each of them.
*/
