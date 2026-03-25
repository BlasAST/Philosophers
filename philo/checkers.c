/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:07:09 by blas              #+#    #+#             */
/*   Updated: 2026/03/25 11:42:10 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	unlock_forks(t_philo *ph)
{
	pthread_mutex_lock(ph->fl);
	pthread_mutex_lock(ph->fr);
}

int	check_dead(t_philo *ph)
{
	
}
