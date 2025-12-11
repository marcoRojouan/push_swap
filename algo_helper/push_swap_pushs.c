/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pushs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:16:25 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/11 18:36:51 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pswap.h"

void	pa(t_stack *a_stack, t_stack *b_stack)
{
	int i;

	if (b_stack->size == 0)
		return ;
	i = a_stack->size;
	while (i > 0)
	{
		a_stack->values[i] = a_stack->values[i - 1];
		i--;
	}
	a_stack->values[0] = b_stack->values[0];
	a_stack->size++;
	i = 0;
	while (i < b_stack->size - 1)
	{
		b_stack->values[i] = b_stack->values[i + 1];
		i++;
	} 
	b_stack->size--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *b_stack, t_stack *a_stack)
{
	int i;

	if (a_stack->size == 0)
		return ;
	i = b_stack->size;
	while (i > 0)
	{
		b_stack->values[i] = b_stack->values[i - 1];
		i--;
	}
	b_stack->values[0] = a_stack->values[0];
	b_stack->size++;
	i = 0;
	while (i < a_stack->size - 1)
	{
		a_stack->values[i] = a_stack->values[i + 1];
		i++;
	} 
	a_stack->size--;
	
	write(1, "pb\n", 3);
}

