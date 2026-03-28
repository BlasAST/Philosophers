/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:46:28 by blas              #+#    #+#             */
/*   Updated: 2026/03/28 21:16:27 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *) arg;
	if (ph->id % 2 == 0)
		usleep(15000);
	while (!check_dead(ph->data))
	{
		print_with_time("is thinking", ph);
		philo_eat(ph);
		if (ph->data->must_eat != -1 && ph->meals_eaten >= ph->data->must_eat)
			break ;
		print_with_time("is sleeping", ph);
		smart_sleep(ph->data->time_to_sleep, ph->data);
		print_with_time("is thinking", ph);
		if (ph->data->number_philos % 2 != 0)
			usleep(500);
	}
	return (NULL);
}

void	await_pthreads(t_data *dt)
{
	int	i;

	i = 0;
	while (i < dt->number_philos)
	{
		pthread_join(dt->philos[i].thread, NULL);
		i++;
	}
}

int	main(int argn, char **args)
{
	t_data	dt;

	if (argn != 5 && argn != 6)
	{
		ft_print_error("Demasiados parametros \n Usage: ./philo [n_philos] [time_to_die] \
[time_to_eat] [time_to_sleep] [n_time_each_philo_must_eat]");
		return (1);
	}
	get_data(&dt, args + 1, argn);
	monitor(&dt);
	await_pthreads(&dt);
	free_all(&dt);
	return (0);
}
