/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:20:25 by tohma             #+#    #+#             */
/*   Updated: 2024/05/14 15:29:34 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parse_word(t_string_part **parts, char *str, t_env *env)
{
	char	*to_put;
	int		last_cpy_index;
	int		i;

	i = -1;
	last_cpy_index = 0;
	to_put = ft_strcpy_until_quote(str, '\"');
	while (to_put[++i])
	{
		if (to_put[i] == '$' && to_put[i + 1])
		{
			push_str_part(parts,
				ft_strncpy(to_put + last_cpy_index, i - last_cpy_index));
			push_str_part(parts, get_env_variable(env, to_put + i));
			i += ft_strchr_nalphanum(to_put + i + 1);
			last_cpy_index = i + 1;
		}
	}
	if (i - last_cpy_index > 0)
		push_str_part(parts,
			ft_strncpy(to_put + last_cpy_index, i - last_cpy_index));
	ft_free(to_put);
}

void	parse_word_nquotes(t_string_part **parts, char *str, t_env *env)
{
	char	*to_put;
	int		last_cpy_index;
	int		i;

	i = -1;
	last_cpy_index = 0;
	to_put = ft_strcpy_until_quotes(str);
	while (to_put[++i])
	{
		if (to_put[i] == '$' && to_put[i + 1])
		{
			push_str_part(parts,
				ft_strncpy(to_put + last_cpy_index, i - last_cpy_index));
			push_str_part(parts, get_env_variable(env, to_put + i));
			i += ft_strchr_nalphanum(to_put + i + 1);
			last_cpy_index = i + 1;
		}
	}
	if (i - last_cpy_index > 0)
		push_str_part(parts,
			ft_strncpy(to_put + last_cpy_index, i - last_cpy_index));
	ft_free(to_put);
}
