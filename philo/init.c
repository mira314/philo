/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:00:16 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/15 01:48:34 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static void set_philo(char *argv[], t_philo *philo)
{
    philo->nb_philo = ft_atol(argv[1]);
    philo->time_to_die = ft_atol(argv[2]);
    philo->time_to_eat = ft_atol(argv[3]);
    philo->time_to_sleep = ft_atol(argv[4]);
    if (argv[5])
        philo->nb_times_to_eat = ft_atol(argv[5]);
    else
        philo->nb_times_to_eat = -1;
}

void init_data(t_data *data, t_philo *philo)
{
 data->one_philo_is_dead = 0;
 data->philo = philo;
 pthread_mutex_init(&data->write_lock, NULL);
 pthread_mutex_init(&data->dead_lock, NULL);
 pthread_mutex_init(&data->eat_lock, NULL);
}

void    init_forks(pthread_mutex_t *forks, long nb_philo)
{
    long i;

    i = 0;
    while (nb_philo > i)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
}

void init_philo(t_philo *ph, t_data *data, pthread_mutex_t *fork, char **argv)
{
    long i;

    i = 0;
    while (ft_atol(argv[1]) > i)
    {
        ph[i].id = i + 1;
        ph[i].eating = 0;
        ph[i].count_eating = 0;
        set_philo(argv, &ph[i]);
        ph[i].time_start = get_time();
        ph[i].last_eat = get_time();
        ph[i].write_lock = &data->write_lock;
        ph[i].dead_lock = &data->dead_lock;
        ph[i].eat_lock = &data->eat_lock;
        ph[i].dead = &data->one_philo_is_dead;
        ph[i].left_fork = &fork[i];
        if (i == 0)
            ph[i].right_fork = &fork[ph[i].nb_philo - 1];
        else
            ph[i].right_fork = &fork[i - 1];
        i++;
    }
}
