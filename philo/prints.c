/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:43:38 by blas              #+#    #+#             */
/*   Updated: 2026/03/25 12:41:03 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	get_time(t_philo *ph)
{
	long long			now_ms;

	now_ms = get_time_ms();
	if (ph->data->start_time == -1)
		ph->data->start_time = now_ms;
	return (now_ms - ph->data->start_time);
}

void	print_with_time(char *str, t_philo *ph)
{
	printf("%d %d %s", get_time(ph), ph->id, str);
}
