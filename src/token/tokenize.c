/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:27:33 by tohma             #+#    #+#             */
/*   Updated: 2024/04/01 16:04:54 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	handle_quotes(char cur_char, int *flags)
{
	if (cur_char == '\"')
		*flags ^= 0b1;
	else if (cur_char == '\'')
		*flags ^= 0b10;
	if (cur_char == '<' || cur_char == '>')
		*flags |= 0b100;
	else if (cur_char != ' ')
		*flags &= 0b11;
}

static void	handle_split(char *line, int *i, int *start_idx, t_token_lst **tlst)
{
	push_lst(tlst, ft_strncpy(line + *start_idx,
			ft_max(1, (*i) - *start_idx + (line[(*i) + 1] == '\0'))));
	while (line[(*i) + 1] == ' ')
		(*i)++;
	*start_idx = (*i) + 1;
}

t_token_lst	*tokenize(char *line)
{
	t_token_lst	*tok_lst;
	int			flags;
	int			start_idx;
	int			i;

	tok_lst = NULL;
	i = ft_nstrchr_i(line, ' ');
	flags = 0;
	start_idx = i;
	while (line[i])
	{
		handle_quotes(line[i], &flags);
		if ((line[i] == ' ' && !flags)
			|| line[i + 1] == '\0')
			handle_split(line, &i, &start_idx, &tok_lst);
		i++;
	}
	return (tok_lst);
}
