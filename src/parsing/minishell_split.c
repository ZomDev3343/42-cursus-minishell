/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:32:42 by tohma             #+#    #+#             */
/*   Updated: 2024/05/27 00:06:04 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	count_parts(char *s, char delimiter)
{
	int	start;
	int	amount;

	amount = 0;
	start = ft_nstrchr_i(s, delimiter);
	while (s[start])
	{
		start += ft_strchr_i_nquotes(s + start, delimiter);
		amount++;
		if (s[start])
			start++;
	}
	return (amount);
}

char	**minishell_split(char *s, char delimiter)
{
	char	**res;
	int		nb_parts;
	int		i;
	int		current_part;

	if (!s)
		return (NULL);
	current_part = -1;
	nb_parts = count_parts(s, delimiter);
	res = (char **) ft_calloc(nb_parts + 1, sizeof(char *));
	i = ft_nstrchr_i(s, delimiter);
	while (s[i])
	{
		res[++current_part] = ft_strncpy(s + i,
				ft_strchr_i_nquotes(s + i, delimiter));
		i += ft_strchr_i_nquotes(s + i, delimiter);
		i += ft_nstrchr_i(s + i, delimiter);
	}
	return (res);
}
