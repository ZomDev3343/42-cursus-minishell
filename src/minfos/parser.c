/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:21:11 by truello           #+#    #+#             */
/*   Updated: 2024/04/01 16:02:50 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static int	handle_double_modes(t_redir_files *rf, char *cur_str, int *is_redir_filepath)
// {
// 	if (cur_str[1] == '\0')
// 		is_redir_filepath = TRUE;
// }

// static void	handle_simple_modes(t_redir_files *rf, char symbol,
// 	t_token_lst *tlst, int *is_redir_filepath)
// {

// }

// static int	parse_minfos_redirs(t_redir_files **side, char symbol,
// 	t_token_lst *tlst)
// {
// 	int	is_redir_filepath;
// 	int	i;

// 	is_redir_filepath = FALSE;
// 	while (tlst)
// 	{
// 		if (is_redir_filepath)
// 		{
// 			push_redir_file(side, ft_strdup(tlst->data));
// 			is_redir_filepath = FALSE;
// 			continue ;
// 		}
// 		i = ft_strchr_i_nquotes(tlst->data, symbol);
// 		if (i > -1)
// 		{
// 			if (!handle_double_modes(side, symbol, tlst, &is_redir_filepath))
// 				handle_simple_modes(side, symbol, tlst, &is_redir_filepath);
// 		}
// 		tlst = tlst->next;
// 	}
// }

// int	parse_minfos(t_minishell *minfos, t_token_lst *tlst)
// {

// 	return (TRUE);
// }
