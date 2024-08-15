/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:06:40 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/15 15:40:49 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_action("has taken a fork", philo, philo->id);
	if (philo->nb_philo == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_action("has taken a fork", philo, philo->id);
	philo->eating = 1;
	print_action("is eating", philo, philo->id);
	pthread_mutex_lock(philo->eat_lock);
	philo->last_eat = get_time();
	philo->count_eating++;
	pthread_mutex_unlock(philo->eat_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeping(t_philo *philo)
{
	print_action("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_action("is thinking", philo, philo->id);
}
