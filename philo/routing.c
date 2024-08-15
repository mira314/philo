/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:16:28 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/15 03:52:38 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int is_dead(t_philo *philo, long time_to_dead)
{
    pthread_mutex_lock(philo->eat_lock);
    if (get_time() - philo->last_eat >= time_to_dead && philo->eating == 0)
    {
        pthread_mutex_unlock(philo->eat_lock);
        return (1);
    }
    pthread_mutex_unlock(philo->eat_lock);
    return (0);
}
int dead_check(t_philo *philo)
{
    int i;

    i = 0;
    while (philo[0].nb_philo > i)
    {
        if (is_dead(&philo[i], philo[i].time_to_die))
        {
            print_action("died", &philo[i], philo[i].id);
            pthread_mutex_lock(philo[0].dead_lock);
            *philo->dead = 1;
            pthread_mutex_unlock(philo[0].dead_lock);
            return (1);
        }
        i++;
    }
    return (0);
}
int eat_full(t_philo *philo)
{
    int i;
    int is_full;

    i = 0;
    is_full = 0;
    if (philo[0].nb_times_to_eat == -1)
        return (0);
    while (philo[0].nb_philo > i)
    {
        pthread_mutex_lock(philo[i].eat_lock);
        if (philo[i].count_eating >= philo[i].nb_times_to_eat)
            is_full++;
        pthread_mutex_unlock(philo[i].eat_lock);
        i++;
    }
    if (is_full == philo[0].nb_philo)
    {
        pthread_mutex_lock(philo[0].dead_lock);
        *philo->dead = 1;
        pthread_mutex_unlock(philo[0].dead_lock);
        return (1);
    }
    return (0);
}
void *routing(void *ptr)
{
    t_philo *philo;

    philo = (t_philo *)ptr;
    while (1)
        if (dead_check(philo) == 1 || eat_full(philo) == 1)
            break ;
    return (ptr);
}

void    *action_philo(void *ptr)
{
    t_philo *philo;
    
    philo = (t_philo *)ptr;
    if (philo->id % 2 == 0)
        ft_usleep(10);
    while (!death_status(philo))
    {
        eating(philo);
        sleeping(philo);
        thinking(philo);
    }
    return (ptr);
}