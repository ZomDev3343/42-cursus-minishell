/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:51:41 by truello           #+#    #+#             */
/*   Updated: 2024/03/19 14:30:30 by truello          ###   ########.fr       */
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
	char	flag;
}	t_token;

typedef struct s_btree
{
	void			*val;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

#endif
