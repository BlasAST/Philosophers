/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:10:52 by blas              #+#    #+#             */
/*   Updated: 2026/04/01 21:29:32 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_data *dt)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < dt->number_philos)
		{
			pthread_mutex_lock(&dt->tab.death);
			if ((get_time() - dt->philos[i].last_meal) >= dt->time_to_die)
			{
				dt->tab.someone_dead = 1;
				pthread_mutex_lock(&dt->tab.prints);
				printf("%lld %d died\n", get_time()
					- dt->start_time, dt->philos[i].id);
				pthread_mutex_unlock(&dt->tab.prints);
				pthread_mutex_unlock(&dt->tab.death);
				return ;
			}
			pthread_mutex_unlock(&dt->tab.death);
			i++;
		}
		if (dt->must_eat != -1 && check_all_eaters(dt))
			return ;
		usleep(1000);
	}
}
