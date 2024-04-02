/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:36:40 by truello           #+#    #+#             */
/*   Updated: 2024/04/02 15:24:42 by truello          ###   ########.fr       */
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
