/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:07:09 by blas              #+#    #+#             */
/*   Updated: 2026/03/28 21:24:08 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_data *dt)
{
	int	stop;

	pthread_mutex_lock(&dt->tab.death);
	stop = dt->tab.someone_dead;
	pthread_mutex_unlock(&dt->tab.death);
	return (stop);
}

int	check_all_eaters(t_data *dt)
{
	int	i;
	int	all_eat;
	int	meals;

	i = 0;
	all_eat = 1;
	while (i < dt->number_philos)
	{
		pthread_mutex_lock(&dt->tab.death);
		meals = dt->philos[i].meals_eaten;
		pthread_mutex_unlock(&dt->tab.death);
		if (meals < dt->must_eat)
			all_eat = 0;
		i++;
	}
	return (all_eat);
}
