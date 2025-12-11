/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_indexing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loup <loup@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:47:59 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/11 18:48:09 by loup             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pswap.h"

int *int_arr_cpy(int *values, int size)
{
	int	*new_tab;
	int	i;

	i = 0;
	new_tab = malloc(sizeof(int) * size);
	if (!new_tab)
		return (NULL);
	while (i < size)
	{
		new_tab[i] = values[i];
		i++;
	}
	return (new_tab);
}

void ft_bubble_sort(int *tab, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	} 
}
int make_index(int *sorted_values, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		while (sorted_values[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	*indexing_tab(int *values, int size)
{
	int i;
	int *sorted_tab;
	int	*indexed_tab;

	sorted_tab = int_arr_cpy(values, size);
	if (!sorted_tab)
		return (NULL);
	ft_bubble_sort(sorted_tab, size);
	indexed_tab = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		indexed_tab[i] = make_index(sorted_tab, values[i], size);
		i++;
	}
	return (indexed_tab);
}
