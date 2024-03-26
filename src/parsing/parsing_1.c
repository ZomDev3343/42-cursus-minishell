/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:46:02 by tohma             #+#    #+#             */
/*   Updated: 2024/03/20 17:53:35 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_btree	*parse_command_line(char *line, char **env)
{
	t_btree	*exec_tree;

	exec_tree = (t_btree *) ft_calloc(1, sizeof(t_btree));
	if (!exec_tree)
		return (NULL);
	if (!parse_tokens(exec_tree))
		printf("Error while parsing tokens!\n");
}

int	parse_tokens(t_btree *exec_tree)
{
	
}
