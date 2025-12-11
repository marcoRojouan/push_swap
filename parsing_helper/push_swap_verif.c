/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_verif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:21:04 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/11 18:36:43 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pswap.h"

int	is_non_num(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-')
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
	return (0);
}
