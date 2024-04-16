/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:28:11 by truello           #+#    #+#             */
/*   Updated: 2024/04/16 19:53:37 by tohma            ###   ########.fr       */
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

t_token			*newtoken(char *data, int cmd_id);
void			print_token_list(t_token *toklist);
t_token			*tokenize(char *line);
void			free_token(t_token *token);

/* Redirections */

t_redirections	*newredirection(char *path, int mode);
void			push_redirections(t_redirections **redirections,
					t_redirections *newredir);
void			parse_redirection(t_redirections **redirections,
					t_token *token);
void			print_redirections(t_redirections *redirections);
char			get_redirection_char(int mode);

/* Commands */

t_command		*parse_commands(t_token *tlist);

/* --- Parsing --- */

#endif
