/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:28:27 by blas              #+#    #+#             */
/*   Updated: 2026/03/28 21:51:12 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	smart_sleep(long long time_to_wait, t_data *dt)
{
	long long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time_to_wait)
	{
		if (check_dead(dt))
			break ;
		usleep(500);
	}
}
