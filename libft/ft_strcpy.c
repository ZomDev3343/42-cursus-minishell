/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:36:40 by truello           #+#    #+#             */
/*   Updated: 2024/04/16 14:13:56 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strcpy(char *to_copy)
{
	size_t	i;
	char	*res;

	if (!to_copy)
		return (NULL);
	i = -1;
	res = ft_calloc(ft_strlen(to_copy) + 1, 1);
	while (to_copy[++i])
		res[i] = to_copy[i];
	return (res);
}

char	*ft_strncpy(char *to_copy, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = ft_calloc(n + 1, 1);
	while (i < n && to_copy[i])
	{
		res[i] = to_copy[i];
		i++;
	}
	return (res);
}

/**
 * @brief Copy the next word in the string (delimited by a space)
 *
 * @return char*
 */
char	*ft_strcpy_wsp(char *line, int *index)
{
	int	quotes;
	int	i;
	int	next_space_index;

	quotes = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == '\"')
			quotes ^= 0b1;
		else if (line[i] == '\'')
			quotes ^= 0b10;
		else if (line[i] == ' ' && quotes == 0)
		{
			next_space_index = ft_nstrchr_i(line + i, ' ');
			return (*index += i + next_space_index, ft_strncpy(line, i));
		}
	}
	return (*index += i, ft_strcpy(line));
}
