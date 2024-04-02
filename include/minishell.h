/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:49:09 by truello           #+#    #+#             */
/*   Updated: 2024/04/02 16:34:18 by truello          ###   ########.fr       */
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

t_btree			*new_leaf(t_token *token);
void			clear_tree(t_btree *tree);
int				put_after(t_btree *tree, t_btree *leaf);
int				put_before(t_btree *tree, t_btree *leaf);

/* Redirections files */

t_redir_files	*newrf(char *file_path, t_redirect_mode mode);
void			push_redir_file(t_redir_files **rf_struct, char *file_path,
					t_redirect_mode mode);
void			free_redir_files(t_redir_files *files);

/* Minishell Infos */

t_minishell		*init_minishell(void);

/* Tokens */

t_token			*newtoken(char *data, int flag);

/* Token List */

t_token_lst		*newtoklst(char *data);
t_token_lst		*tokenize(char *line);
int				push_lst(t_token_lst **lst, char *data);
void			print_token_list(t_token_lst *tlst);
void			free_token_lst(t_token_lst **tlst);

/* Parsing */

t_btree			*parse_exec_tree(t_minishell *minfos, t_token_lst *tlst);
int				parse_minfos(t_minishell *minfos, t_token_lst *tlst);
/* Commands */

int				free_command(t_command *cmd);
t_command		*tkn_to_cmd(t_token *token);

#endif
