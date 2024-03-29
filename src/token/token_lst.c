/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:06:40 by tohma             #+#    #+#             */
/*   Updated: 2024/03/29 18:49:35 by tohma            ###   ########.fr       */
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
		if (!tmp->next)
			return (FALSE);
	}
	return (TRUE);
}

void	free_token_lst(t_token_lst **tlst)
{
	if ((*tlst)->next)
		free_token_lst(&((*tlst)->next));
	free((*tlst)->data);
	free(*tlst);
	tlst = NULL;
}

void	print_token_list(t_token_lst *tlst)
{
	printf("--- PRINTING TOKEN LIST ---\n");
	while (tlst)
	{
		printf("%s\n", tlst->data);
		tlst = tlst->next;
	}
	printf("--- PRINTING TOKEN LIST ---\n");
}
