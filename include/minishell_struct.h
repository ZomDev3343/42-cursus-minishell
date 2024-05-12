/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:46:12 by truello           #+#    #+#             */
/*   Updated: 2024/05/12 21:05:56 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

enum e_redirection_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APP,
	REDIR_HD,
	NO_REDIR
};

typedef struct s_token
{
	char				*data;
	int					cmd_id;
	int					used;
	struct s_token		*next;
}	t_token;

typedef struct s_redirections
{
	char					*path;
	int						mode;
	struct s_redirections	*next;
}	t_redirections;

typedef struct s_string_part
{
	char					*part;
	struct s_string_part	*next;
}	t_string_part;

typedef struct s_command
{
	char				**parts;
	t_redirections		*redirections;
	struct s_command	*next;
}	t_command;

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_exec
{
	int				fd_stdin;
	int				fd_stdout;
	int				output_fd;
	int				input_fd;
	int				cmd_nb;
	int				**pipes;
}	t_exec;

#endif
