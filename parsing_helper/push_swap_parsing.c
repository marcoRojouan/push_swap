/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:15:42 by mrojouan          #+#    #+#             */
/*   Updated: 2025/12/14 17:00:51 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pswap.h"
#include <stdio.h>
#include <unistd.h>

char	**rearrange_args(int ac, char **av)
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
	return (splitted_args);
}

char	**parsing_args(int ac, char **av)
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
		free(parsed_args);
		return (NULL);
	}
	return (parsed_args);
}

t_stack	fill_stack(char **args, t_stack stack)
{
	int		i; 
	int		is_nogood;
	
	is_nogood = 1;
	i = 0;
	while (args[i])
		i++;
	stack.values = malloc(sizeof(int) * i);
	i = 0;
	while (args[i])
	{
		stack.values[i] = ft_atoi(args[i], &is_nogood);
		stack.size++;
		i++;
	}
	if (!is_nogood)
	{
		write(2, "Error\n", 6);
		free(stack.values);
		exit(1);
	}
	return (stack);
}

t_stack	push_swap_parsing(int ac, char **av)
{
    char	**args;
	t_stack	stack;

	stack.values = NULL;
	stack.size = 0;
	args = parsing_args(ac, av);
	if (!args)
		return (stack);
	stack = fill_stack(args, stack);
	stack.values = indexing_tab(stack.values, stack.size);
	return (stack);
}