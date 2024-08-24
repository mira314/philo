/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:51:51 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/24 10:33:03 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atol(char *str)
{
	long		sign;
	long		result;
	long		i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return ((long)result * sign);
}

long	get_time(void)
{
	struct timeval	time;
	long			current_time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("error of time get\n");
	}
	current_time = time.tv_sec * 1000;
	current_time += time.tv_usec / 1000;
	return (current_time);
}

int	ft_usleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(500);
	return (0);
}
