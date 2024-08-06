/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:47:32 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/06 15:13:31 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>   
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>
# include <stdint.h>
# include <pthread.h>

typedef struct s_data t_data;

typedef struct s_philo
{
    unsigned long id;
    pthread_t   thread;
    unsigned long   time_to_eat;
    unsigned long   fork[2];
    pthread_mutex_t mutex;
    unsigned long   last_eat;
    t_data  *data;
} t_philo;
typedef struct s_data
{
    unsigned long   time_start;
    int nb_philo;
    pthread_t   is_dead;
    unsigned long   time_to_die;
    unsigned long   time_to_eat;
    unsigned long   time_to_sleep;
    int eat_needed;
    bool simulation_end;
    pthread_mutex_t simulation_end_lock;
    pthread_mutex_t action_lock;
    pthread_mutex_t *fork_locks;
    t_philo **philos;

} t_data;



#endif
