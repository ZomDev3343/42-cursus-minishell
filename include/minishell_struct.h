/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:51:41 by truello           #+#    #+#             */
/*   Updated: 2024/03/26 18:07:55 by tohma            ###   ########.fr       */
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

typedef struct s_minishell
{
	char	*input_file;
	char	*output_file;
	char	**env;
}	t_minishell;

typedef struct s_btree
{
	t_token			*token;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

#endif
