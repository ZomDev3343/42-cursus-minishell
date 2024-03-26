/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:49:09 by truello           #+#    #+#             */
/*   Updated: 2024/03/26 18:20:52 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "minishell_struct.h"
# include "../libft/ft.h"

# define FALSE 0
# define TRUE 1

/* Binary Tree */

t_btree		*new_leaf(t_token *token);
void		clear_tree(t_btree *tree);
int			put_after(t_btree *tree, t_btree *leaf);
int			put_before(t_btree *tree, t_btree *leaf);

/* Tokens */

t_token		*newtoken(char *data, int flag);

/* Token List */

t_token_lst	*newtoklst(char *data);
int			push_lst(t_token_lst **lst, char *data);

/* Parsing */

t_btree		*parse_exec_tree(char *line);

/* Commands */

int			free_command(t_command *cmd);
t_command	*tkn_to_cmd(t_token *token);

#endif
