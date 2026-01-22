/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:15:42 by mrojouan          #+#    #+#             */
/*   Updated: 2026/01/22 14:07:31 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	**rearrange_args(int ac, char **av)
{
	char	*joined_args;
	char	**splitted_args;
	int		i;

	joined_args = malloc(sizeof(char) * 1);
	if (!joined_args)
		return (NULL);
	joined_args[0] = '\0';
	i = 1;
	while (i < ac)
	{
		joined_args = ft_strjoin(joined_args, av[i]);
		if (!joined_args)
			return (NULL);
		i++;
	}
	splitted_args = ft_split(joined_args);
	if (!splitted_args)
		return (NULL);
	free(joined_args);
	return (splitted_args);
}

static char	**parsing_args(int ac, char **av)
{
	char	**parsed_args;

	if (!av_is_valid(av))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	parsed_args = rearrange_args(ac, av);
	if (!parsed_args)
		return (0);
	if (is_valid_data(parsed_args))
	{
		write(2, "Error\n", 6);
		free_all(parsed_args);
		return (NULL);
	}
	return (parsed_args);
}

static void	fill_stack(char **args, t_stack *stack)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	stack->values = malloc(sizeof(int) * i);
	if (!stack->values)
		return ;
	i = 0;
	while (args[i])
	{
		stack->values[i] = ft_atoi(args[i]);
		stack->size++;
		i++;
	}
}

void	push_swap_parsing(int ac, char **av, t_stack *stack)
{
	char	**args;
	int		*tmp;

	stack->values = NULL;
	stack->size = 0;
	args = parsing_args(ac, av);
	if (!args)
		return ;
	fill_stack(args, stack);
	free_all(args);
	tmp = stack->values;
	stack->values = indexing_tab(stack->values, stack->size);
	free(tmp);
	if (!stack->values)
	{
		stack->size = 0;
		return ;
	}
}
