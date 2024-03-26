/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:46:02 by tohma             #+#    #+#             */
/*   Updated: 2024/03/26 17:33:01 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_btree	*parse_exec_tree(char *line)
{
	char	**parts;
	int		i;
	t_btree	*tree;

	i = -1;
	tree = (t_btree *) ft_calloc(1, sizeof(t_btree));
	if (!tree)
		return (NULL);
	parts = ft_split(line, ' ');
	printf("--- Command Line Parts ---\n");
	while (parts[++i])
		printf("%s\n", parts[i]);
	printf("--- Command Line Parts ---\n");
	return (free_parts(parts), free(tree), tree);
}
