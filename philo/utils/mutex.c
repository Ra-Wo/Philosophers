/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:13:57 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/15 16:35:49 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_mutex(t_philo *philo)
{
	int	x;

	x = 0;
	while (x < philo->vars->number_of_philosophers)
	{
		philo[x].how_many_times_eat = 0;
		pthread_mutex_init(&philo[x].fork, NULL);
		if (x == philo->vars->number_of_philosophers - 1)
			philo[x].next_fork = &philo[0].fork;
		else
			philo[x].next_fork = &philo[x + 1].fork;
		x++;
	}
}

void	destroy_mutex(t_philo *philo)
{
	int	x;

	x = 0;
	while (x < philo->vars->number_of_philosophers)
	{
		pthread_mutex_destroy(&philo[x].fork);
		pthread_detach(philo[x].t_id);
		x++;
	}
	free(philo);
}
