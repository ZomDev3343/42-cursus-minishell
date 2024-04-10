/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:20:33 by truello           #+#    #+#             */
/*   Updated: 2024/04/09 16:42:49 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Permets de gerer les differents etats du parsing d'une commande
 *
 * @param flags
 * 			0b0001 - Pipe trouve sans guillemets
 * 			0b0010 - Chevrons trouve sans guillemets
 * 			0b0100 - Entre single quote
 * 			0b1000 - Entre double quote
 * @param c Caractere actuellement pointe
 * @return int Booleen determinant si on passe a une autre commande
 */
static int	handle_flags(int *flags, char c)
{
	if (c == '|' && (*flags & 0b1100) == 0)
		*flags |= 0b0001;
	else if ((c == '<' || c == '>') && (*flags & 0b1100) == 0)
		*flags |= 0b0010;
	else if (c == '\"')
		*flags ^= 0b0100;
	else if (c == '\'')
		*flags ^= 0b1000;
	else if (c == ' ')
		*flags &= 0b1100;
	return ((*flags & 0b0011) > 0 && (*flags & 0b1100) == 0);
}

static void	add_cmd_part(char **cmd, char *cmd_part)
{
	char	*joined;

	if (!*cmd)
		joined = ft_strcpy(cmd_part);
	else
		joined = ft_strnewjoin(*cmd, cmd_part);
	free(*cmd);
	free(cmd_part);
	*cmd = joined;
}

void	parse_commands(t_minishell *minfos, t_btree *tree, t_token_lst *tlst)
{
	int			flags;
	int			i;
	char		*cmd;

	flags = 0;
	cmd = NULL;
	minfos->env = minfos->env;
	while (tlst)
	{
		i = -1;
		while (tlst->data[++i])
		{
			if (handle_flags(&flags, tlst->data[i])
				|| (!tlst->data[i + 1] && !tlst->next))
			{
				add_cmd_part(&cmd, ft_strncpy(tlst->data, i));
				printf("Command : %s\n", cmd);
				put_command(tree, cmd);
				flags = 0;
				cmd = NULL;
			}
		}
		if (cmd)
			add_cmd_part(&cmd, ft_strcpy(" "));
		tlst = tlst->next;
	}
}
