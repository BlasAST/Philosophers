/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:09:12 by blas              #+#    #+#             */
/*   Updated: 2026/03/25 18:57:18 by blas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_print_error(char *str)
{
	write(2, "philo: ", 7);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

int	ft_atoi(char *args)
{
	int		sign;
	int		number;

	sign = 1;
	number = 0;
	while ((*args >= 9 && *args <= 13) || *args == ' ')
		args++;
	if (*args == '-' || *args == '+')
	{
		if (*args == '-')
			sign = -1;
		args++;
	}
	while (*args >= '0' && *args <= '9')
	{
		number = number * 10 + (*args - '0');
		args++;
	}
	return (number * sign);
}
