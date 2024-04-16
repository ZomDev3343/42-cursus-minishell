/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:28:11 by truello           #+#    #+#             */
/*   Updated: 2024/04/16 17:43:53 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "readline/history.h"
# include "readline/readline.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "minishell_struct.h"
# include "../libft/ft.h"

/* --- Parsing --- */

/* Token */

t_token			*newtoken(char *data, int type, int cmd_id);
void			print_token_list(t_token *toklist);
t_token			*tokenize(char *line);
void			free_token(t_token *token);

/* Redirections */

char			get_redirection_char(int mode);

/* Commands */

t_redirections	*newredirection(char *path, int mode);
void			push_redirections(t_redirections **redirections,
					t_redirections *newredir);

/* --- Parsing --- */

#endif
