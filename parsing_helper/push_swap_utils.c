/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:56:27 by loup              #+#    #+#             */
/*   Updated: 2025/12/14 17:11:25 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pswap.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		need_space;
	char	*tab;

	need_space = (ft_strlen(s1) > 0);
	tab = malloc(ft_strlen(s1) + ft_strlen(s2) + need_space + 1);
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	if (need_space)
	{
		tab[j++] = ' ';
	}
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = '\0';
	free(s1);
	return (tab);
}

int	ft_atoi(const char *nptr, int *is_nogood)
{
	int	i;
	int	multi;
	int	nbr;
	int tmp;

	i = 0;
	multi = 1;
	nbr = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			multi = multi * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		tmp = nbr * 10 + (nptr[i] - '0');
		if (tmp < nbr)
			*is_nogood = 0;
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (nbr * multi);
}

int	white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);	
	return (0);
}
