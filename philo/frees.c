/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 23:13:27 by blas              #+#    #+#             */
/*   Updated: 2026/03/24 23:17:50 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *dt)
{
	int	i;

	i = 0;
	if (dt->philos)
		free(dt->philos);
	if (dt->tab.forks)
	{
		while (i < dt->number_philos)
		{
			pthread_mutex_destroy(&dt->tab.forks[i]);
			i++;
		}
		free(dt->tab.forks);
	}
	pthread_mutex_destroy(&dt->tab.prints);
	pthread_mutex_destroy(&dt->tab.death);
}
