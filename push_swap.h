/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:00:27 by loup              #+#    #+#             */
/*   Updated: 2026/01/22 14:05:23 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int		*values;
	int		size;
}	t_stack;

void	push_swap_parsing(int ac, char **av, t_stack *stack);

int		is_sorted(t_stack *stack);
int		is_valid_data(char **args);
int		ft_verif_max(char **tab);
int		ft_atoi(const char *nptr);
int		white_space(char c);
int		av_is_valid(char **av);
int		*indexing_tab(int *stack_values, int size);

char	**ft_split(char *str);
char	*ft_strjoin(char *s1, char *s2);

void	sa(t_stack *stack, int flag);
void	sb(t_stack *stack, int flag);
void	ss(t_stack *a_stack, t_stack *b_stack);
void	pa(t_stack *a_stack, t_stack *b_stack);
void	pb(t_stack *b_stack, t_stack *a_stack);
void	ra(t_stack *a_stack, int flag);
void	rb(t_stack *b_stack, int flag);
void	rr(t_stack *a_stack, t_stack *b_stack);
void	rra(t_stack *a_stack, int flag);
void	rrb(t_stack *b_stack, int flag);
void	rrr(t_stack *a_stack, t_stack *b_stack);
void	sort_2(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_4(t_stack *a_stack, t_stack *b_stack);
void	sort_5(t_stack *a_stack, t_stack *b_stack);
void	move_min(t_stack *stack);
void	radix_sort(t_stack *a_stack, t_stack *b_stack);
void	free_all(char **tab);

#endif