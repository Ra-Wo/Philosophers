/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_isdeath.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:42:04 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/15 19:11:31 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	check_philo_dead(t_philo *philo)
{
	int	x;

	x = 0;
	while (x < philo[0].vars->number_of_philosophers)
	{
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
		if (philo[0].vars->number_of_philosophers == x)
			x = 0;
	}
}
