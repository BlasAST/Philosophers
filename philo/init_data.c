/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:54:38 by blas              #+#    #+#             */
/*   Updated: 2026/03/22 17:12:48 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_data(t_data *dt, char **args, int argn)
{
	dt->number_philos = ft_atoi(args[0]);
	dt->time_to_eat = ft_atoi(args[1]);
	dt->time_to_die = ft_atoi(args[2]);
	dt->time_to_sleep = ft_atoi(args[3]);
	if (argn == 5)
		dt->time_must_ea = 0;
	else
		dt->time_must_ea = ft_atoi(args[4]);
}