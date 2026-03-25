/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:54:38 by blas              #+#    #+#             */
/*   Updated: 2026/03/25 12:43:04 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_philo *philo, int i, t_table *tab)
{
	philo[i].fl = &tab->forks[i];
	philo[i].fr = &tab->forks[(i + 1) % philo->data->number_philos];
}

void	init_p_and_m(t_data *dt)
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
		return ;
	}
	while (i < dt->number_philos)
	{
		pthread_mutex_init(&(dt->tab.forks[i]), NULL);
		pthread_create(&(dt->philos[i].thread), NULL, routine,
			&(dt->philos[i]));
		dt->philos[i].id = i + 1;
		dt->philos[i].last_meal = 0;
		dt->philos[i].meals_eaten = 0;
		init_forks(dt->philos, i, &dt->tab);
		i++;
	}
}

void	get_data(t_data *dt, char **args, int argn)
{
	if (ft_atoi(args[0]) > 1)
		dt->number_philos = ft_atoi(args[0]);
	else
		dt->number_philos = ft_atoi(args[0]); // Aqui debe de ir un printone
	dt->time_to_eat = ft_atoi(args[1]);
	dt->time_to_die = ft_atoi(args[2]);
	dt->time_to_sleep = ft_atoi(args[3]);
	dt->start_time = -1;
	if (argn == 5 && ft_atoi(args[4]) > 0)
		dt->must_eat = ft_atoi(args[4]);
	else
		dt->must_eat = -1;
	pthread_mutex_init(&dt->tab.prints, NULL);
	pthread_mutex_init(&dt->tab.death, NULL);
	init_p_and_m(dt);
}
