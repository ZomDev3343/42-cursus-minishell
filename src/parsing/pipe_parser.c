/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:29:51 by tohma             #+#    #+#             */
/*   Updated: 2024/04/06 18:24:12 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	count_pipes(t_token_lst *tlst)
{
	t_token_lst	*tmp;
	int			i;
	int			r;

	tmp = tlst;
	r = 0;
	while (tmp)
	{
		i = -1;
		while (tmp->data[++i])
			if (tmp->data[i] == '|')
				r++;
		tmp = tmp->next;
	}
	return (r);
}

void	put_pipes_in_tree(t_btree **tree, t_token_lst *tlst)
{
	int		pipes_amount;

	pipes_amount = count_pipes(tlst);
	while (pipes_amount-- > 0)
	{
		if (!*tree)
			*tree = newleaf(newtoken(ft_strcpy("|"), E_PIPE));
		else
			put_after(*tree, newleaf(newtoken(ft_strcpy("|"), E_PIPE)));
	}
}
