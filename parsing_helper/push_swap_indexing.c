/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_indexing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:47:36 by mrojouan          #+#    #+#             */
/*   Updated: 2026/01/03 15:25:46 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	*int_arr_cpy(int *values, int size)
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

static void	ft_bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

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

static int	make_index(int *sorted_values, int value, int size)
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
	int	i;
	int	*sorted_tab;
	int	*indexed_tab;

	sorted_tab = int_arr_cpy(values, size);
	if (!sorted_tab)
		return (NULL);
	ft_bubble_sort(sorted_tab, size);
	indexed_tab = malloc(sizeof(int) * size);
	if (!indexed_tab)
	{
		free(sorted_tab);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		indexed_tab[i] = make_index(sorted_tab, values[i], size);
		i++;
	}
	free(sorted_tab);
	return (indexed_tab);
}
