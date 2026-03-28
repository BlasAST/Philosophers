/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:48:23 by blas              #+#    #+#             */
/*   Updated: 2026/03/28 21:22:10 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *ph)
{
	pthread_mutex_lock(ph->fl);
	print_with_time("has taken a fork", ph);
	if (ph->data->number_philos == 1)
	{
		smart_sleep(ph->data->time_to_die, ph->data);
		pthread_mutex_unlock(ph->fl);
		return ;
	}
	pthread_mutex_lock(ph->fr);
	print_with_time("has taken a fork", ph);
	pthread_mutex_lock(&(ph->data->tab.death));
	ph->last_meal = get_time();
	pthread_mutex_unlock(&(ph->data->tab.death));
	print_with_time("is eating", ph);
	pthread_mutex_lock(&(ph->data->tab.death));
	ph->meals_eaten++;
	pthread_mutex_unlock(&(ph->data->tab.death));
	smart_sleep(ph->data->time_to_eat, ph->data);
	pthread_mutex_unlock(ph->fl);
	pthread_mutex_unlock(ph->fr);
}
