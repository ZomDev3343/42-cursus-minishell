/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutills.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:48:33 by tohma             #+#    #+#             */
/*   Updated: 2024/04/29 16:34:13 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_str_parts(t_string_part *parts)
{
	if (!parts)
		return ;
	if (parts->next)
		free_str_parts(parts->next);
	free(parts->part);
	free(parts);
}

void	push_str_part(t_string_part **str_parts, char *part)
{
	t_string_part	*str_part;
	t_string_part	*tmp;

	str_part = ft_calloc(1, sizeof(t_string_part));
	if (!str_part || !part || part[0] == '\0')
		return (ft_free(part), (void) 0);
	str_part->part = part;
	if (!*str_parts)
		*str_parts = str_part;
	else
	{
		tmp = *str_parts;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = str_part;
	}
}

/**
 * @brief Takes string parts and builds a new string from them
 * 	(frees the original parts)
*/
char	*build_str(t_string_part *parts)
{
	char			*res;
	char			*tmp_str;
	t_string_part	*tmp;

	res = NULL;
	if (!parts)
		return (NULL);
	tmp = parts;
	while (tmp)
	{
		if (!res)
			res = ft_strcpy(parts->part);
		else
		{
			tmp_str = ft_strjoin(res, tmp->part);
			free(res);
			res = tmp_str;
		}
		tmp = tmp->next;
	}
	free_str_parts(parts);
	return (res);
}

void	print_str_parts(t_string_part *parts)
{
	if (!parts)
		return ;
	while (parts)
	{
		printf("%s\n", parts->part);
		parts = parts->next;
	}
}
