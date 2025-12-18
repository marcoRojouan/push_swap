/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_verif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:21:04 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/18 13:54:53 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pswap.h"

int av_is_valid(char **av)
{
	int	i;
	int	j;
	int is_valid;

	i = 1;
	
	while (av[i])
	{
		j = 0;
		is_valid = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				is_valid = 1;
			j++;
		}
		if (is_valid == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_non_num(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if ((args[i][j] == '-' || args[i][j] == '+' ) && args[i][j + 1] != '\0')
			j++;
		while (args[i][j])
		{
			if ((args[i][j] < '0' || args[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_doubles(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_data(char **args)
{
	if (is_non_num(args))
		return (1);
	if (is_doubles(args))
		return (1);
	if (ft_verif_max(args))
		return (1);
	return (0);
}
