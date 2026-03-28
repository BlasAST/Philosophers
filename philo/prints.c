/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:43:38 by blas              #+#    #+#             */
/*   Updated: 2026/03/28 21:34:47 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_with_time(char *str, t_philo *ph)
{
	long long	time;

	pthread_mutex_lock(&ph->data->tab.prints);
	if (!check_dead(ph->data))
	{
		time = get_time() - ph->data->start_time;
		printf("%lld %d %s\n", time, ph->id, str);
	}
	pthread_mutex_unlock(&ph->data->tab.prints);
}
