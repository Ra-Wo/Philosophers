/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:35:49 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/14 12:57:06 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print(char *str, long time, int id, pthread_mutex_t *pen)
{
	pthread_mutex_lock(pen);
	printf(str, time, id);
	pthread_mutex_unlock(pen);
}
