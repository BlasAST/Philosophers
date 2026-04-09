/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:48:33 by blas              #+#    #+#             */
/*   Updated: 2026/04/09 14:02:06 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int						id;
	pthread_t				thread;
	long long				last_meal;
	int						meals_eaten;
	pthread_mutex_t			*fl;
	pthread_mutex_t			*fr;
	t_data					*data;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	prints;
	pthread_mutex_t	death;
	int				someone_dead;
}	t_table;

typedef struct s_data
{
	long long		start_time;
	int				number_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	t_table			tab;
	t_philo			*philos;
}	t_data;

int			ft_strlen(char *str);
void		ft_print_error(char *str);
void		*routine(void *arg);
int			philo_eat(t_philo *ph);
void		smart_sleep(long long time_to_wait, t_data *dt);
long long	get_time(void);
int			check_dead(t_data *dt);
int			check_all_eaters(t_data *dt);
int			get_data(t_data *dt, char **args, int argn);
int			ft_atoi(char *args);
void		print_with_time(char *str, t_philo *ph);
void		monitor(t_data *dt);
void		free_all(t_data *dt);
int			ft_numeric(char *str);
int			check_values(char **args, int argn);
int			ft_is_overflow(char *str);
int			destroy_mutex_philos(t_data *dt);

#endif