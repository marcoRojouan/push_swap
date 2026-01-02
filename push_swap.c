/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:56:25 by loup              #+#    #+#             */
/*   Updated: 2026/01/02 14:59:19 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void push_swap(t_stack *a_stack, t_stack *b_stack)
{
	if (!is_sorted(a_stack))
	{
		if (a_stack->size == 2)
			sort_2(a_stack);
		else if (a_stack->size == 3)
			sort_3(a_stack);
		else if (a_stack->size == 4)
			sort_4(a_stack, b_stack);
		else if (a_stack->size == 5)
			sort_5(a_stack, b_stack);
		else if (a_stack->size > 5)
			radix_sort(a_stack, b_stack);
	}
}

#include <stdio.h>

int main(int ac, char **av)
{
	t_stack a_stack;
	t_stack	b_stack;
	// int i = 0;
	
	if (ac < 2)
		return (0);
	a_stack = push_swap_parsing(ac, av);
	if (!a_stack.values || !a_stack.size)
		return (0);
	b_stack.values = malloc(sizeof(int) * a_stack.size);
	if (!b_stack.values)
		return (0);
	b_stack.size = 0;
	push_swap(&a_stack, &b_stack);
	// while (i < a_stack.size)
	// {
	// 	printf("%d", a_stack.values[i]);
	// 	i++;
	// }
	free(a_stack.values);
	free(b_stack.values);
	return (0);
}