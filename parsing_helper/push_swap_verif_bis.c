/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_verif_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:56:57 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/18 13:51:26 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pswap.h"

static int	in_int_range(char *str)
{
	long long	n;
	int			sign;

	n = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		n = n * 10 + (*str - '0');
		if (sign == 1 && n > INT_MAX)
			return (1);
		if (sign == -1 && - n < INT_MIN)
			return (1);
		str++;
	}
	return (0);
}

int	ft_verif_max(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (in_int_range(tab[i]))
			return (1);
		i++;
	}
	return (0);
}