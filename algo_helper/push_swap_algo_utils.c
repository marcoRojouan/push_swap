/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:33:51 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/11 18:36:53 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pswap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->values[i] > stack->values[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_2(t_stack *stack)
{
	if (stack->values[0] > stack->values[1])
		sa(stack, 1);
}

void	sort_3(t_stack *stack)
{
	int a;
	int b;	
	int c;

	a = stack->values[0];
	b = stack->values[1];
	c = stack->values[2];
	if (a > b && b < c && a < c)
		sa(stack, 1);
	else if (a > b && b > c)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack, 1);
}

void	sort_4(t_stack *a_stack, t_stack *b_stack)
{
	move_min(a_stack);
	pb(b_stack, a_stack);
	sort_3(a_stack);
	pa(a_stack, b_stack);
}
void	sort_5(t_stack *a_stack, t_stack *b_stack)
{
	move_min(a_stack);
	pb(b_stack, a_stack);
	move_min(a_stack);
	pb(b_stack, a_stack);
	sort_3(a_stack);
	pa(a_stack, b_stack);
	pa(a_stack, b_stack);
	if (a_stack->values[0] > a_stack->values[1])
        sa(a_stack, 1);
}
