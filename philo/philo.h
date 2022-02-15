/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:34:54 by roudouch          #+#    #+#             */
/*   Updated: 2022/02/15 14:35:46 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_vars {
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long			start;
	int				dead;
	pthread_mutex_t	t_pen;
	int				x;
	int				loop_for_ever;
	int				exit;
}	t_vars;

typedef struct s_philsopher{
	pthread_t				t_id;
	pthread_mutex_t			fork;
	pthread_mutex_t			*next_fork;
	t_vars					*vars;
	int						how_many_times_eat;
	long					last_time_eat;
	int						id;
}	t_philo;

/* Functions */
char	*init(int argc, char **argv, t_vars *vars);
int		ft_atoi(const char *str);
int		ft_isdigit(int i);
void	init_mutex(t_philo *philo);
void	destroy_mutex(t_philo *philo);
void	pthread_wait(t_philo *philo);
void	connect_philo_with_vars(t_philo *philo, t_vars *vars);
void	ft_print(char *str, long time, int id, pthread_mutex_t *pen);

#endif