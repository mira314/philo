/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:47:32 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/18 11:31:31 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>   
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int			id;
	int			eating;
	int			count_eating;
	int			nb_times_to_eat;
	long		last_eat;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		time_start;
	int			*dead;
	int			nb_philo;
	pthread_t	thread;
	t_mutex		*right_fork;
	t_mutex		*left_fork;
	t_mutex		*write_lock;
	t_mutex		*dead_lock;
	t_mutex		*eat_lock;
}	t_philo;

typedef struct s_data
{
	int		one_philo_is_dead;
	t_mutex	dead_lock;
	t_mutex	eat_lock;
	t_mutex	write_lock;
	t_philo	*philo;
	int		nb_philo;
}	t_data;

/************main.c */
void	clear_pthread(t_data *data, t_mutex *forks);
/*************check.c  *********** */
int		ft_is_atoible(char *str);
int		check_argumets(int argc, char *argv[]);
/**************utils.c ************/
int		ft_strlen(char *str);
int		ft_atol(char *str);
/*************init.c  * ***********/
void	init_data(t_data *data, t_philo *philo);
void	init_forks(t_mutex *forks, long nb_philo);
void	init_philo(t_philo *ph, t_data *data, t_mutex *fork, char *argv[]);
/**********************time_utils.c*******************/
long	get_time(void);
int		ft_usleep(long time);
/***********************thread_utils.c****************/
int		init_thread(t_data *data, t_mutex *forks);
int		death_status(t_philo *philo);
void	destroy_pthread(char *msg, t_data *data, t_mutex *forks);
/***************************routing.c*******************/
int		is_dead(t_philo *philo, long time_to_dead);
void	*routing(void *ptr);
int		eat_full(t_philo *philo);
void	*action_philo(void *ptr);
/**************print.c******************************/
void	print_action(char *msg, t_philo *philo, int id);
void	print_dead(t_philo *philo, int id);
/*****************action.c*************************/
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
#endif
