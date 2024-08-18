/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:52:27 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/18 11:24:38 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_pthread(t_data *data, t_mutex *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->eat_lock);
	pthread_mutex_destroy(&data->dead_lock);
	while (data->philo[0].nb_philo > i)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_data			data;
	t_philo			*philo;
	t_mutex	*forks;

	if (check_argumets(argc, argv) == 0)
		return (1);
	philo = malloc(sizeof(t_philo) * ft_atol(argv[1]));
	forks = malloc(sizeof(t_mutex) * ft_atol(argv[1]));
	init_data(&data, philo);
	init_forks(forks, ft_atol(argv[1]));
	init_philo(philo, &data, forks, argv);
	init_thread(&data, forks);
	clear_pthread(&data, forks);
	free(philo);
	free(forks);
	return (0);
}
