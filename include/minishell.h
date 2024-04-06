/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:49:09 by truello           #+#    #+#             */
/*   Updated: 2024/04/06 18:08:49 by tohma            ###   ########.fr       */
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

t_btree			*newleaf(t_token *token);
void			free_tree(t_btree *tree);
int				put_after(t_btree *tree, t_btree *leaf);
int				put_before(t_btree *tree, t_btree *leaf);
t_btree			*get_first_leaf(t_btree *tree);
t_btree			*get_last_leaf(t_btree *tree);
void			print_tree(t_btree *tree, int floor);

/* Redirections files */

t_redir_files	*newrf(char *file_path, t_redirect_mode mode);
void			push_redir_file(t_redir_files **rf_struct, char *file_path,
					t_redirect_mode mode);
void			free_redir_files(t_redir_files *files);
void			print_redir_files(t_redir_files *files);
void			clear_minfos_rfiles(t_minishell *minfos);
void			free_minfos(t_minishell *minfos);

/* Pipes */

void			put_pipes_in_tree(t_btree **tree, t_token_lst *tlst);

/* Minishell Infos */

t_minishell		*init_minishell(void);

/* Tokens */

t_token			*newtoken(char *data, int flag);
void			free_token(t_token *token);

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
