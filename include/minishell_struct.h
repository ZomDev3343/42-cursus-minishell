/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:51:41 by truello           #+#    #+#             */
/*   Updated: 2024/04/02 14:59:38 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

typedef enum e_token_flag
{
	E_CMDNAME = 0b1,
	E_CMDARGS = 0b10,
	E_DBLE_QUOTE = 0b100,
	E_SMPL_QUOTE = 0b1000,
	E_PIPE = 0b10000,
	E_SPCHAR = 0b100000,
	E_REDIRECT = 0b1000000
}	t_tknflag;

typedef enum e_redirect_mode
{
	E_OUTPUT,
	E_INPUT,
	E_HERE_DOC,
	E_APPEND
}	t_redirect_mode;

typedef struct s_token
{
	char	*data;
	int		flag;
}	t_token;

typedef struct s_token_list
{
	char				*data;
	struct s_token_list	*next;
}	t_token_lst;

typedef struct s_command
{
	char	*cmd_name;
	char	**cmd_args;
}	t_command;

typedef struct s_redir_files
{
	char					*file_path;
	int						mode;
	struct s_redir_files	*next;
}	t_redir_files;

typedef struct s_minishell
{
	t_redir_files	*input_files;
	t_redir_files	*output_files;
	char			**env;
}	t_minishell;

typedef struct s_btree
{
	t_token			*token;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

#endif
