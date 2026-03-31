/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:48:33 by blas              #+#    #+#             */
/*   Updated: 2026/03/30 17:14:10 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>


//RESTRICT
/*
	- Global vars
*/

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
//Los philos no hablan entre ellos por lo que no saben si otro muere
//DEBEN DE INTENTAR NO MORIR

//Cuentan con identificador de forma que el ultimo
//terminará estando con el primero

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

int		ft_strlen(char *str);
void	ft_print_error(char *str);

//Turnos de comer, pensar, dormir
void	*routine(void *arg);
void	get_forks(t_philo *ph);
int		unlock_forks(t_philo *ph);
int	philo_eat(t_philo *ph);
void	smart_sleep(long long time_to_wait, t_data *dt);


// Get timers
long long	get_time(void);

//Checkers
int		check_dead(t_data *dt);
int	check_all_eaters(t_data *dt);

// Save data params main
void	get_data(t_data *dt, char **args, int argn);
int		ft_atoi(char *args);



// Notify changes philos - correctos y en orden
void	print_with_time(char *str, t_philo *ph);


// Tiempo limite de notificación y momento de muerte
void	monitor(t_data *dt);
//frees

void	free_all(t_data *dt);


//BONUS

#endif