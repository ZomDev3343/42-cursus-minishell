/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:28:11 by truello           #+#    #+#             */
/*   Updated: 2024/05/21 10:01:10 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>

# include "minishell_struct.h"
# include "../libft/ft.h"

/* --- Environment --- */

t_env			*newenv(char *name, char *content);
void			free_env(t_env *env);
void			push_env(t_env **env, t_env *env_var);
t_env			*make_env(char **envp);
int				remove_env_var(t_env *env, char *var_name);
char			*get_env_variable(t_env *env, char *var_name);
void			print_env(t_env *env);
int				has_env_variable(t_env *env, char *name);
char			**build_env(t_env *env);

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
int				handle_redirections(t_redirections *redir, t_exec *exec);
int				handle_input_redirection(char *path);
int				handle_output_redirection(char *path, t_exec *exec);
int				handle_append_redirection(char *path);
int				handle_here_doc_redirection(char *path, t_exec *exec);
int				**create_pipes(int pipe_nb);
void			handle_redir_leaving_exec(int i, t_exec *exec);
void			handle_redir_entering_exec(int i, t_exec *exec);

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
void			parse_word(t_string_part **parts, char *str, t_env *env);
void			parse_word_nquotes(t_string_part **parts,
					char *str, t_env *env);

/* Verification */

int				check_commands(t_command *cmds);

/* --- Signals --- */

void			sig_on_interrupt(int code);
void			setup_signal_handler(void);

/* --- builtins --- */

/* builtin */

int				check_builtin_path(t_command *cmd);
void			builtin_in_child(t_command *cmd, t_env *env);
void			builtin_out_child(int i, t_exec *exec, t_command *cmd, t_env *env);
void			ft_cd(t_command *cmd, t_env *env);
void			ft_echo(t_command *cmd);
void			ft_env(int flag, t_command *cmd, t_env *env);
void			ft_exit(t_command *cmd);
void			ft_pwd(void);

/* builtin utils */

char			*get_current_working_directory(void);
void			update_env(char *content, char *name, t_env *env);
void			add_env_variable(t_env *env, t_env *env_var);

/* execution */

void			exec_command(int i, t_exec *exec, t_command *cmd, t_env *env);
void			handle_execution(t_command *cmd, t_env *env);

/* --- Command execution --- */

/* command utils */

int				get_nb_of_commands(t_command *cmd);
void			ft_free_array(char **str);
t_exec			*make_exec_structure(void);
void			free_pipes(int **pipes, int pipe_nb);

/* process */

void			parent_process(int i, t_exec *exec);
void			child_process(int i, t_exec *exec, t_command *cmd, t_env *env);

/* path */

char			**extract_path_from_env(t_env *env);
char			*found_path(char *cmd, t_env *env);

#endif
