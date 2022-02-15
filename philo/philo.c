/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:33:44 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/15 18:00:43 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	create_philos(t_vars *vars, t_philo *philo)
{
	int	x;

	x = 0;
	while (x < vars->number_of_philosophers)
	{
		philo[x].id = x + 1;
		usleep(100);
		if (pthread_create(&philo[x].t_id, NULL, philosopher, &philo[x]) != 0)
			return (-1);
		x++;
	}
	return (0);
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
	if (create_philos(&vars, philo))
		return (printf("ERROR: can't create a thread\n"), 1);
	check_philo_dead(philo);
	destroy_mutex(philo);
	return (0);
}
