/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:59:35 by tohma             #+#    #+#             */
/*   Updated: 2024/04/01 15:10:02 by truello          ###   ########.fr       */
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

int	ft_strchr_i_nquotes(char *str, char c)
{
	int	i;
	int	quotes;

	i = -1;
	quotes = 0;
	while (str[++i])
	{
		if (str[i] == '\'')
			quotes ^= 0b1;
		else if (str[i] == '\"')
			quotes ^= 0b10;
		if (str[i] == c && !(quotes & 0b1 || quotes & 0b10))
			return (i);
	}
	return (-1);
}
