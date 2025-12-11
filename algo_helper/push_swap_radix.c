/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:55:39 by loup              #+#    #+#             */
/*   Updated: 2025/12/11 19:41:07 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pswap.h"

int get_max_bit(t_stack *a_stack, int size)
{
    int i;
    int max_index;
    int max_bit;
    int bits;

    max_index = a_stack->values[0];
    i = 0;
    while (i < size)
    {
        if (max_index < a_stack->values[i])
            max_index = a_stack->values[i];
        i++;
    }
    max_bit = max_index;
    bits = 0;
    while ((max_bit >> bits) != 0)
        bits++;
    return (bits);
}

void radix_sort(t_stack *a_stack, t_stack *b_stack)
{
    int bits;
    int i;
    int j;
    int value;
    int size_a;

    bits = get_max_bit(a_stack, a_stack->size);
    i = 0;
    while (i < bits)
    {
        size_a = a_stack->size;
        j = 0;
        while (j < size_a)
        {
            value = a_stack->values[0];
            if (((value >> i) & 1) == 1)
                ra(a_stack, 1);
            else
                pb(b_stack, a_stack);
            j++;
        }
        while (b_stack->size > 0)
            pa(a_stack, b_stack);
        i++;
    }
}
