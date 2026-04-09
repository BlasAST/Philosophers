/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blas <blas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:09:12 by blas              #+#    #+#             */
/*   Updated: 2026/04/08 19:31:48 by blas             ###   ########.fr       */
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

int	ft_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_overflow(char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > 2147483647)
			return (1);
		i++;
	}
	return (0);
}
