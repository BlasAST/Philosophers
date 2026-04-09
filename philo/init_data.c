/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:54:38 by blas              #+#    #+#             */
/*   Updated: 2026/04/09 02:10:36 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_philo *philo, int i, t_table *tab)
{
	philo[i].fl = &tab->forks[i];
	philo[i].fr = &tab->forks[(i + 1) % philo[i].data->number_philos];
	if (philo[i].id % 2 == 0)
	{
		philo[i].fl = &tab->forks[(i + 1) % philo[i].data->number_philos];
		philo[i].fr = &tab->forks[i];
	}
}

void	init_p(t_data *dt)
{
	int	i;

	i = 0;
	while (i < dt->number_philos)
	{
		dt->philos[i].data = dt;
		dt->philos[i].id = i + 1;
		dt->philos[i].last_meal = dt->start_time;
		dt->philos[i].meals_eaten = 0;
		init_forks(dt->philos, i, &dt->tab);
		pthread_create(&(dt->philos[i].thread), NULL, routine,
			&(dt->philos[i]));
		i++;
	}
}

int	init_p_and_m(t_data *dt)
{
	int	i;

	i = 0;
	dt->tab.forks = malloc (sizeof(pthread_mutex_t) * (dt->number_philos));
	dt->philos = malloc (sizeof(t_philo) * (dt->number_philos));
	if (!dt->tab.forks || !dt->philos)
	{
		if (dt->tab.forks)
			free(dt->tab.forks);
		if (dt->philos)
			free(dt->philos);
		return (1);
	}
	while (i < dt->number_philos)
	{
		pthread_mutex_init(&(dt->tab.forks[i]), NULL);
		i++;
	}
	dt->start_time = get_time();
	init_p(dt);
	return (0);
}

int	get_data(t_data *dt, char **args, int argn)
{
	if (check_values(args, argn))
		return (1);
	dt->number_philos = ft_atoi(args[0]);
	dt->time_to_die = ft_atoi(args[1]);
	dt->time_to_eat = ft_atoi(args[2]);
	dt->time_to_sleep = ft_atoi(args[3]);
	dt->tab.someone_dead = 0;
	if (argn == 6)
	{
		dt->must_eat = ft_atoi(args[4]);
		if (dt->must_eat <= 0)
			return (1);
	}
	else
		dt->must_eat = -1;
	if (dt->number_philos <= 0 || dt->time_to_die <= 0
		|| dt->time_to_eat <= 0 || dt->time_to_sleep <= 0)
		return (1);
	pthread_mutex_init(&dt->tab.prints, NULL);
	pthread_mutex_init(&dt->tab.death, NULL);
	if (init_p_and_m(dt))
		return (destroy_mutex_philos(dt));
	return (0);
}
