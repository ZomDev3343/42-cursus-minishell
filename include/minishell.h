/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:49:09 by truello           #+#    #+#             */
/*   Updated: 2024/03/26 12:50:37 by tohma            ###   ########.fr       */
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



/* Commands */

int			free_command(t_command *cmd);

#endif
