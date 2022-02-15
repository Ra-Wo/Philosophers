/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_philo_with_vars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:46:48 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/15 14:03:03 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	connect_philo_with_vars(t_philo *philo, t_vars *vars)
{
	int	x;

	x = 0;
	while (x < vars->number_of_philosophers)
	{
		philo[x].vars = vars;
		x++;
	}
}
