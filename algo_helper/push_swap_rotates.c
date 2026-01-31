/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:00:48 by mrojouan          #+#    #+#             */
/*   Updated: 2026/01/31 14:46:07 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_stack *stack, int flag)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->values[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[stack->size - 1] = tmp;
	if (flag)
		write(1, "ra\n", 3);
}

// void	rb(t_stack *stack, int flag)
// {
// 	int	tmp;
// 	int	i;

// 	if (stack->size < 2)
// 		return ;
// 	tmp = stack->values[0];
// 	i = 0;
// 	while (i < stack->size - 1)
// 	{
// 		stack->values[i] = stack->values[i + 1];
// 		i++;
// 	}
// 	stack->values[stack->size - 1] = tmp;
// 	if (flag)
// 		write(1, "rb\n", 3);
// }

// void	rr(t_stack *a_stack, t_stack *b_stack)
// {
// 	ra(a_stack, 0);
// 	rb(b_stack, 0);
// 	write(1, "rr\n", 3);
// }
