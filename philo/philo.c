/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:33:44 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/15 15:48:14 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	philo_actions(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->fork);
	ft_print("%ld %d has taken a fork\n", (get_time()
			- philosopher->vars->start), philosopher->id,
		&philosopher->vars->t_pen);
	pthread_mutex_lock(philosopher->next_fork);
	ft_print("%ld %d has taken a fork\n",
		(get_time() - philosopher->vars->start),
		philosopher->id, &philosopher->vars->t_pen);
	ft_print("%ld %d is eating\n", (get_time() - philosopher->vars->start),
		philosopher->id, &philosopher->vars->t_pen);
	philosopher->last_time_eat = get_time() - philosopher->vars->start;
	usleep(philosopher->vars->time_to_eat * 1000);
	pthread_mutex_unlock(&philosopher->fork);
	pthread_mutex_unlock(philosopher->next_fork);
	ft_print("%ld %d is sleeping\n", (get_time() - philosopher->vars->start),
		philosopher->id, &philosopher->vars->t_pen);
	usleep(philosopher->vars->time_to_sleep * 1000);
	ft_print("%ld %d is thinking\n", (get_time() - philosopher->vars->start),
		philosopher->id, &philosopher->vars->t_pen);
}

static void	*philosopher(void *philo_info)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo_info;
	while (philosopher->vars->number_of_times_each_philosopher_must_eat
		> philosopher->how_many_times_eat++ || philosopher->vars->loop_for_ever)
	{
		philo_actions(philosopher);
	}
	philosopher->vars->exit++;
	return (NULL);
}

void	check_philo_dead(t_philo *philo)
{
	int	x;

	x = 0;
	while (x <= philo[x].vars->number_of_philosophers)
	{
		if (philo[x].vars->number_of_philosophers - 1 == x)
		{
			x = 0;
		}
		if ((get_time() - philo[x].vars->start) - philo[x].last_time_eat
			>= philo[x].last_time_eat + philo[x].vars->time_to_die)
		{
			philo[x].vars->dead = 1;
			ft_print("%ld %d died\n", (get_time() - philo[x].vars->start),
				philo[x].id, &philo[x].vars->t_pen);
			pthread_mutex_lock(&philo[x].vars->t_pen);
			break ;
		}
		if (philo[x].vars->exit == philo[x].vars->number_of_philosophers)
			break ;
		x++;
	}	
}

int	main(int argc, char **argv)
{
	int		x;
	char	*error;
	t_vars	vars;
	t_philo	*philo;

	x = 0;
	error = init(argc, argv, &vars);
	if (error)
		return (printf("%s", error), 1);
	philo = malloc(sizeof(t_philo) * (vars.number_of_philosophers));
	vars.start = get_time();
	connect_philo_with_vars(philo, &vars);
	init_mutex(philo);
	x = 0;
	while (x < vars.number_of_philosophers)
	{
		philo[x].id = x + 1;
		philo[x].next_fork = &philo[x + 1].fork;
		usleep(100);
		pthread_create(&philo[x].t_id, NULL, philosopher, &philo[x]);
		x++;
	}
	check_philo_dead(philo);
	destroy_mutex(philo);
	return (0);
}
