/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:28:11 by truello           #+#    #+#             */
/*   Updated: 2024/05/17 14:59:21 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>

# include "minishell_struct.h"
# include "../libft/ft.h"

/* --- Environment --- */

t_env			*newenv(char *name, char *content);
void			free_env(t_env *env);
void			push_env(t_env **env, t_env *env_var);
t_env			*make_env(char **envp);
int				remove_env_var(t_env **env, char *var_name);
char			*get_env_variable(t_env *env, char *var_name);
void			print_env(t_env *env);
int				has_env_variable(t_env *env, char *name);
char			**build_env(t_env *env);
char			*get_last_status_code(void);

/* --- Environment --- */

/* --- Parsing --- */

/* Token */

t_token			*newtoken(char *data, int cmd_id);
void			print_token_list(t_token *toklist);
t_token			*tokenize(char *line, t_env *env);
void			free_token(t_token *token);

/* Redirections */

t_redirections	*newredirection(char *path, int mode);
void			push_redirections(t_redirections **redirections,
					t_redirections *newredir);
int				parse_redirection(t_redirections **redirections,
					t_token *token);
void			print_redirections(t_redirections *redirections);
char			get_redirection_char(int mode);
void			free_redirections(t_redirections *redirections);

/* Commands */

void			parse_commands(t_token *tlist, t_command **cmds);
void			free_str_parts(t_string_part *parts);
void			push_str_part(t_string_part **cmd_parts, char *part);
char			**build_parts(t_string_part *cmd_parts);
void			print_commands(t_command *cmds);
void			free_command(t_command *cmd);
void			set_builtin_flag(t_command *cmd);

/* String Utils */

char			*build_str(t_string_part *parts);
int				is_quote_closed(char *str);
char			*rem_quotes(char *str, t_env *env);
void			print_str_parts(t_string_part *parts);

/* Verification */

int				check_commands(t_command *cmds);

/* --- Parsing --- */

/* --- Signals --- */

void			sig_on_interrupt(int code);
void			setup_signal_handler(void);

/* --- Signals --- */

#endif
