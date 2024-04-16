/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:46:12 by truello           #+#    #+#             */
/*   Updated: 2024/04/16 20:27:46 by tohma            ###   ########.fr       */
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

typedef struct s_command
{
	char				**parts;
	t_redirections		*redirections;
	struct s_command	*next;
}	t_command;

#endif
