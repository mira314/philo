/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:52:27 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/14 21:07:09 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
    t_data data;
    t_philo *philo;
    pthread_mutex_t *forks;
    
    if (check_argumets(argc, argv) == 0)
        return (1);
    philo = malloc(sizeof(t_philo) * ft_atol(argv[1]));
    forks = malloc(sizeof(pthread_mutex_t) * ft_atol(argv[1]));
    init_data(&data, philo);
    init_forks(forks, ft_atol(argv[1]));
    init_philo(philo, &data, forks, argv);
    init_thread(&data, forks);
    free(philo);
    free(forks);
    return (0);
}
