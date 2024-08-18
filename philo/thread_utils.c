/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:08:19 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/18 11:27:11 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void destroy_pthread(char *msg, t_data *data, t_mutex *forks)
{
    int i;

    i = 0;
    if (msg)
        printf("%s\n", msg);
    pthread_mutex_destroy(&data->write_lock);
    pthread_mutex_destroy(&data->eat_lock);
    pthread_mutex_destroy(&data->dead_lock);
    while (data->philo[0].nb_philo > i)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
}

int death_status(t_philo *philo)
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
int init_thread(t_data *data, t_mutex *forks)
{
    pthread_t   monitor;
    int    i;

    i = 0;
    if (pthread_create(&monitor, NULL, &routing, data->philo))
        destroy_pthread("thread error creating", data, forks);
    while (data->philo[0].nb_philo > i)
    {
        if (pthread_create(&data->philo[i].thread, NULL, &action_philo, 
            &data->philo[i]))
            destroy_pthread("thread error creating", data, forks);
        i++;
    }
    i = 0;
    if (pthread_join(monitor, NULL))
        destroy_pthread("join error", data, forks);
    while (data->philo[0].nb_philo > i)
    {
        if (pthread_join(data->philo[i].thread, NULL))
            destroy_pthread("join error", data, forks);
        i++;
    }
    return (0);
}