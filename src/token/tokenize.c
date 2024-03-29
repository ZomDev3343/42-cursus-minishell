/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:27:33 by tohma             #+#    #+#             */
/*   Updated: 2024/03/29 18:47:35 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	handle_quotes(char cur_char, int *condition_var)
{
	if (cur_char == '\"')
		*condition_var ^= 0b1;
	else if (cur_char == '\'')
		*condition_var ^= 0b10;
}

t_token_lst	*tokenize(char *line)
{
	t_token_lst	*tok_lst;
	int			is_quoted;
	int			start_idx;
	int			i;

	tok_lst = NULL;
	i = ft_nstrchr_i(line, ' ');
	is_quoted = 0;
	start_idx = i;
	while (line[i])
	{
		handle_quotes(line[i], &is_quoted);
		if ((line[i] == ' ' && !(is_quoted & 0b1 || is_quoted & 0b10))
			|| line[i + 1] == '\0')
		{
			push_lst(&tok_lst, ft_strncpy(line + start_idx,
				ft_max(1, i - start_idx + (line[i + 1] == '\0'))));
			while (line[i + 1] == ' ')
				i++;
			start_idx = i + 1;
		}
		i++;
	}
	return (tok_lst);
}
