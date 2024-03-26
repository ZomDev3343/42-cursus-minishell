/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:06:40 by tohma             #+#    #+#             */
/*   Updated: 2024/03/26 18:21:04 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token_lst	*newtoklst(char *data)
{
	t_token_lst	*res;

	res = (t_token_lst *) ft_calloc(1, sizeof(t_token_lst));
	if (!res)
		return (NULL);
	res->data = data;
	res->next = NULL;
	return (res);
}

int	push_lst(t_token_lst **lst, char *data)
{
	t_token_lst	*tmp;

	if (!lst)
		return (FALSE);
	if (!*lst)
	{
		*lst = newtoklst(data);
		if (!*lst)
			return (FALSE);
	}
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newtoklst(data);
		if (!tmp)
			return (FALSE);
	}
	return (TRUE);
}
