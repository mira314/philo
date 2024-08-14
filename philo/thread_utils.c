/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:08:19 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/14 22:40:17 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void destroy_pthread(char *msg, t_data *data, pthread_mutex_t *forks)
{
    int i;

    i = 0;

    if (msg)
        printf("%s\n", msg);
    pthread_mutex_destroy(&data->write_lock);
    pthread_mutex_destroy(&data->eat_lock);
    pthread_mutex_destroy(&data->dead_lock);
    while (data->philo[0].nb_philo)
}
int dead_lock(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    if (*philo->dead == 1)
    {
        pthread_mutex_unlock(philo->dead_lock);
        return (1);
    }
    pthread_mutex_unlock(philo->dead->lock);
    return (0);
}
int init_thread(t_data *data, pthread_mutex_t *forks)
{
    pthread_t   monitor;
    int    i;

    if (pthread_create(&monitor, NULL, &routing, data->philo) != 0)
    {
        
    }
    
}