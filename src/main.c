/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:48:48 by truello           #+#    #+#             */
/*   Updated: 2024/03/25 17:19:23 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parse_line(char *line)
{
	char	**parts;
	t_btree	*tree;

	tree = (t_btree *) ft_calloc(1, sizeof(t_btree));
	if (!tree)
		return ;
	parts = ft_split(line, ' ');
	//parse_tokens(parts, tree);
	free_parts(parts);
}

int	main(void)
{
	char	*prompt;

	prompt = readline("minishell > ");
	while (prompt[0] != '\0')
	{
		parse_line(prompt);
		free(prompt);
		prompt = readline("minishell > ");
	}
	free(prompt);
	return (0);
}
