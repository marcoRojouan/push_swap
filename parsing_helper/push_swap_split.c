/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:20:55 by mrojouan          #+#    #+#             */
/*   Updated: 2026/01/03 15:26:42 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str || !str[0])
		return (0);
	if (!white_space(str[0]))
	{
		count += 1;
	}
	i++;
	while (str[i])
	{
		if (!white_space(str[i]) && white_space(str[i - 1]))
			count++;
		i++;
	}
	return (count);
}

static char	*duplicate_wrd(char *str)
{
	char	*dup;
	int		word_len;
	int		i;

	word_len = 0;
	while (!white_space(str[word_len]) && str[word_len])
		word_len++;
	if (!str)
		return (NULL);
	dup = malloc(sizeof(char) * (word_len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	fill_tab(char *str, char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((i == 0 && !white_space(str[i]))
			|| (i > 0 && !white_space(str[i]) && white_space(str[i - 1])))
		{
			tab[j] = duplicate_wrd(str + i);
			if (!tab[j])
			{
				free_all(tab);
				return (0);
			}
			j++;
		}
		i++;
	}
	tab[j] = 0;
	return (1);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		word_count;

	word_count = count_words(str);
	if (!str)
		return (NULL);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (NULL);
	if (!fill_tab(str, tab))
		return (0);
	return (tab);
}
