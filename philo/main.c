/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:46:28 by blas              #+#    #+#             */
/*   Updated: 2026/03/25 11:43:25 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *) arg;
	while (1)
	{
		if (check_dead(ph->data->tab.someone_dead))
			break;
		
		/*
		Pensar
		Coger tenedor left
		Coger tenedor right
		Comer
		Soltar tenedores
		Dormir
		*/
	}
	return (NULL);
}

void	await_pthreads(t_data *dt)
{
	int	i;

	i = 0;
	while (i < dt->number_philos)
	{
		pthread_detach(dt->philos[i].thread);
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
	await_pthreads(&dt);
	free_all(&dt);
	return (0);
}
