/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:49:09 by truello           #+#    #+#             */
/*   Updated: 2024/03/19 16:53:29 by truello          ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0

/* Tokens */

/* Binary Tree */

t_btree		*new_leaf(void *val);
void		clear_tree(t_btree *tree);

#endif
