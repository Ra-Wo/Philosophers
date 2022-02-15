/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_wait.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:23:19 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/15 14:01:30 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	pthread_wait(t_philo *philo)
{
	int	x;

	x = 0;
	while (x < philo->vars->number_of_philosophers)
	{
		pthread_join(philo[x].t_id, NULL);
		x++;
	}
}
