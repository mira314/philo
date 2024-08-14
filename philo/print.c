/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:03:01 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/14 22:16:43 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_action(char *msg, t_philo *philo, int id)
{
    long    time;
    pthread_mutex_lock(philo->write_lock);
    time = get_time() - philo->time_start;
    if (!dead_lock(philo))
        printf("%l %d %s\n", time, id, msg);
    pthread_mutex_unlock(philo->write_lock);
}