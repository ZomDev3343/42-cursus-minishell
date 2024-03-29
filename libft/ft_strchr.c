/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:59:35 by tohma             #+#    #+#             */
/*   Updated: 2024/03/29 17:10:16 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strchr_i(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

/* Searches the lowest index that is not the given character */
int	ft_nstrchr_i(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != c)
			return (i);
	return (-1);
}
