/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rrotates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:56:04 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/11 18:36:50 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pswap.h"

void	rra(t_stack *stack, int flag)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->values[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = tmp;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int flag)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->values[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = tmp;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a_stack, t_stack *b_stack)
{
	rra(a_stack, 0);
	rrb(b_stack, 0);
	write(1, "rrr\n", 4);
}