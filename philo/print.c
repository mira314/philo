/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:03:01 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/15 15:33:11 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(char *msg, t_philo *philo, int id)
{
	long	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->time_start;
	if (death_status(philo) == 0)
		printf("%ld %d %s\n", time, id, msg);
	pthread_mutex_unlock(philo->write_lock);
}

void	print_dead(t_philo *philo, int id)
{
	long	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->time_start;
	if (death_status(philo) == 0)
		printf("%ld %d died\n", time, id);
	pthread_mutex_unlock(philo->write_lock);
}
