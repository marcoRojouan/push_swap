/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swaps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:56:37 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/11 18:36:49 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pswap.h"

void	sa(t_stack *stack, int flag)
{	
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int flag)
{
	int	tmp;
		
	if (stack->size < 2)
		return ;
	tmp = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = tmp;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a_stack, t_stack *b_stack)
{	
	sa(a_stack, 0);
	sb(b_stack, 0);
	write(1, "ss\n", 3);
}