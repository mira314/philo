/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:58:44 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/14 20:35:14 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    get_time(void)
{
    struct timeval  time;
    long    current_time;

    if (gettimeofday(&time, NULL) == -1)
    {
        printf("error of time get\n");
    }
    current_time = time.tv_sec * 1000;
    current_time += time.tv_usec / 1000;
    return (current_time);
}

int ft_usleep(long time)
{
    long    start;

    start = get_time();
    while (get_time() - start < time)
        usleep(200);
    return (0);
}