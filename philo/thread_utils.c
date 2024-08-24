/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:08:19 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/24 12:40:31 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_pthread(char *msg, t_data *data, t_mutex *forks)
{
	int	i;
	int	result;

	i = 0;
	if (msg)
		printf("%s\n", msg);
	result = pthread_mutex_destroy(&data->write_lock);
	if (result != 0)
		printf("mutex destory failed on write lock with code %d\n", result);
	result = pthread_mutex_destroy(&data->eat_lock);
	if (result != 0)
		printf("mutex destory failed on eat_lock with code %d\n", result);
	result = pthread_mutex_destroy(&data->dead_lock);
	if (result != 0)
		printf("mutex destory failed on dead_lock with code %d\n", result);
	while (data->philo[0].nb_philo > i)
	{
		result = pthread_mutex_destroy(&forks[i]);
		if (result != 0)
			printf("mutex destory failed on forks with code %d\n", result);
		i++;
	}
}

int	death_status(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	init_thread(t_data *data, t_mutex *forks)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	if (pthread_create(&monitor, NULL, &routing, data->philo))
		destroy_pthread("thread error creating ", data, forks);
	while (data->philo[0].nb_philo > i)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &action_philo,
				&data->philo[i]))
			destroy_pthread("thread error creating ", data, forks);
		i++;
	}
	i = 0;
	if (pthread_join(monitor, NULL))
		destroy_pthread("join error ", data, forks);
	while (data->philo[0].nb_philo > i)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			destroy_pthread("join error ", data, forks);
		i++;
	}
	return (0);
}
