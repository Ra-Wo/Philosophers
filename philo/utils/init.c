/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:11:39 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/15 14:06:59 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	init_all_args(char **argv, t_vars *vars)
{
	int	i;
	int	x;

	i = 1;
	while (argv[i])
	{
		x = 0;
		while (argv[i][x])
			if (!ft_isdigit(argv[i][x++]))
				return (-1);
		i++;
	}
	vars->number_of_philosophers = ft_atoi(argv[1]);
	vars->time_to_die = ft_atoi(argv[2]);
	vars->time_to_eat = ft_atoi(argv[3]);
	vars->time_to_sleep = ft_atoi(argv[4]);
	vars->loop_for_ever = 0;
	if (argv[5] == NULL)
	{
		vars->loop_for_ever = 1;
		vars->number_of_times_each_philosopher_must_eat = 0;
	}
	else
		vars->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	return (0);
}

static int	check_params(t_vars *vars)
{
	if (vars->number_of_philosophers <= 0 || vars->time_to_die <= 0
		|| vars->time_to_eat <= 60 || vars->time_to_sleep <= 0)
		return (-1);
	return (0);
}

char	*init(int argc, char **argv, t_vars *vars)
{
	vars->dead = 0;
	vars->exit = 0;
	if (argc < 5 || argc > 6)
		return ("Error: wrong arguments");
	if (init_all_args(argv, vars) == -1)
		return ("Error");
	if (check_params(vars) == -1)
		return ("Error");
	return (NULL);
}
