/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:47:32 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/14 22:20:30 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>   
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
    int id;
    int eating;
    int count_eating;
    int nb_times_to_eat;
    long last_eat;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long    time_start;
    int *dead;
    int nb_philo;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *write_lock;
    pthread_mutex_t *dead_lock;
    pthread_mutex_t *eat_lock;
} t_philo;

typedef struct s_data
{
    int one_philo_is_dead;
    pthread_mutex_t dead_lock;
    pthread_mutex_t eat_lock;
    pthread_mutex_t write_lock;
    t_philo *philo;
} t_data;

/************main.c */

/*************check.c  *********** */
int ft_is_atoible(char *str);
int check_argumets(int argc, char *argv[]);
/**************utils.c ************/
int	ft_strlen(char *str);
int	ft_atol(char *str);
/*************init.c  * ***********/
void init_data(t_data *data, t_philo *philo);
void    init_forks(pthread_mutex_t *forks, long nb_philo);
void init_philo(t_philo *ph, t_data *data, pthread_mutex_t *fork, char **argv);
/**********************time_utils.c*******************/
long    get_time(void);
/***********************thread_utils.c****************/
int init_thread(t_data *data, pthread_mutex_t *forks);
/***************************routing.c*******************/
int dead_check(t_philo *philo);
int is_dead(t_philo *philo, long time_to_dead);
void routing(void *ptr);
int eat_full(t_philo *philo);
/**************print.c******************************/
void print_action(char *msg, t_philo *philo, int id);
#endif
