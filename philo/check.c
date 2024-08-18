/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:22:38 by vrandria          #+#    #+#             */
/*   Updated: 2024/08/18 12:50:56 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_argumets_helps(char *argv[])
{
	if (ft_atol(argv[3]) < 1)
	{
		printf("Invalid time to eat.\n");
		return (0);
	}
	if (ft_atol(argv[4]) < 1)
	{
		printf("Invalid time to sleep.\n");
		return (0);
	}
	if (ft_atol(argv[2]) < 1)
	{
		printf("Invalid time to die.\n");
		return (0);
	}
	if (ft_atol(argv[1]) < 1)
	{
		printf("Invalid philosophers number.\n");
		return (0);
	}
	return (1);
}

static int	check_value(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (argc > i)
	{
		if (ft_is_atoible(argv[i]) == 0)
		{
			printf("only numeric values are autotized.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_is_atoible(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_argumets(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		printf("error, number of argumet should be 4 or 5.\n");
		return (0);
	}
	if (check_value(argc, argv) == 0)
		return (0);
	if (check_argumets_helps(argv) == 0)
		return (0);
	if (argc == 6)
	{
		if (ft_atol(argv[5]) < 0)
		{
			printf("Invalid have to eat\n");
			return (0);
		}
		if (ft_atol(argv[5]) == 0)
		{
			printf("nobody can die, they are already full.\n");
			return (0);
		}
	}
	return (1);
}
