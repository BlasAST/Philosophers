/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguenc <bsiguenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:46:28 by blas              #+#    #+#             */
/*   Updated: 2026/04/11 16:19:58 by bsiguenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	breakmind_switch(long long breakmind, t_philo *ph)
{
	if (breakmind < 0)
		breakmind = 0;
	if (ph->data->number_philos % 2 != 0)
		breakmind += (ph->data->time_to_eat / 2);
	if (breakmind > 0)
		smart_sleep(breakmind + 2, ph->data);
	else
		usleep(500);
}

void	*routine(void *arg)
{
	t_philo		*ph;
	long long	breakmind;

	ph = (t_philo *) arg;
	if (ph->id % 2 == 0)
		smart_sleep(ph->data->time_to_eat / 2, ph->data);
	while (!check_dead(ph->data))
	{
		if (philo_eat(ph))
			break ;
		if (ph->data->must_eat != -1 && ph->meals_eaten >= ph->data->must_eat)
			break ;
		print_with_time("is sleeping", ph);
		smart_sleep(ph->data->time_to_sleep, ph->data);
		print_with_time("is thinking", ph);
		breakmind = ph->data->time_to_eat - ph->data->time_to_sleep;
		breakmind_switch(breakmind, ph);
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
		ft_print_error("Error \n Usage: ./philo [n_philos > 0] [time_to_die >] \
	[time_to_eat > 0] [time_to_sleep > 0] \
	[n_time_each_philo_must_eat > 0 | empty]");
		return (1);
	}
	if (get_data(&dt, args + 1, argn))
		return (1);
	monitor(&dt);
	await_pthreads(&dt);
	free_all(&dt);
	return (0);
}
