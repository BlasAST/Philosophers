/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:46:28 by blas              #+#    #+#             */
/*   Updated: 2026/03/23 13:57:17 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* int	main(int argn, char **args)
{
	t_data	dt;

	if (argn != 5 && argn != 6)
	{
		ft_print_error("Demasiados parametros \n Usage: ./philo [n_philos] [time_to_die] \
[time_to_eat] [time_to_sleep] [n_time_each_philo_must_eat]");
		return (1);
	}
	get_data(&dt, args + 1, argn);
	
	return (0);
} */

void	*print_hola(void *arg)
{
	int	i;
	int	id;

	i = 0;
	id = *(int *)arg;
	while (i < 10)
	{
		printf("Hola desde hilo %d, iteración %d\n", id, i);
		usleep(1000);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	hilo1;
	pthread_t	hilo2;
	int			id1;
	int			id2;
	int			err;

	id1 = 1;
	id2 = 2;
	err = pthread_create(&hilo1, NULL, print_hola, &id1);
	if (err != 0)
		return (1);
	err = pthread_create(&hilo2, NULL, print_hola, &id2);
	if (err != 0)
		return (1);
	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);
	printf("Hilos finalizados\n");
	return (0);
}
