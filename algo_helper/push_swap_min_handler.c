/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_min_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:19:20 by mrojouan          #+#    #+#             */
/*   Updated: 2026/01/03 15:23:39 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_min_index(int *nbrs, int size)
{
	int	i;
	int	min;
	int	min_index;

	i = 1;
	min = nbrs[0];
	min_index = 0;
	while (i < size)
	{
		if (nbrs[i] < min)
		{
			min = nbrs[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	move_min(t_stack *stack)
{
	int	min_index;

	min_index = find_min_index(stack->values, stack->size);
	if (min_index <= stack->size / 2)
	{
		while (min_index)
		{
			ra(stack, 1);
			min_index--;
		}
	}
	else
	{
		while (min_index < stack->size)
		{
			rra(stack, 1);
			min_index++;
		}
	}
}
