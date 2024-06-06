/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:58:46 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/06 12:16:49 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**extract_path_from_env(t_env *env)
{
	while (env)
	{
		if (ft_strncmp(env->name, "PATH", 4))
			return (ft_split(env->content, ':'));
		env = env->next;
	}
	return (NULL);
}

int	is_absolute_path(char *cmd)
{
	if ((cmd[0] == '/' || cmd[0] == '.') && cmd[1])
		return (1);
	return (0);
}

char	*found_path(char *cmd, t_env *env)
{
	char	*each_path;
	char	*exec_path;
	char	**paths;
	int		i;

	i = 0;
	if (is_absolute_path(cmd))
		return (cmd);
	paths = extract_path_from_env(env);
	if (!paths)
		exit(EXIT_FAILURE);
	while (paths[i])
	{
		each_path = ft_strjoin(paths[i], "/");
		exec_path = ft_strjoin(each_path, cmd);
		free(each_path);
		if (access(exec_path, X_OK) == 0)
			return (ft_free_array(paths), exec_path);
		free(exec_path);
		i++;
	}
	ft_free_array(paths);
	return (NULL);
}

int	check_cmd_path_loop(char *each_path, char *ex_path, char **paths, char *cmd)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		each_path = ft_strjoin(paths[i], "/");
		ex_path = ft_strjoin(each_path, cmd);
		free(each_path);
		if (access(ex_path, X_OK) == 0)
		{
			ft_free_array(paths);
			free(ex_path);
			return (1);
		}
		free(ex_path);
		i++;
	}
	return (0);
}

int	check_cmd_path(char *cmd, t_env *env)
{
	char	*each_path;
	char	*exec_path;
	char	**paths;
	int		i;

	i = 0;
	each_path = NULL;
	exec_path = NULL;
	if (is_absolute_path(cmd))
		return (1);
	paths = extract_path_from_env(env);
	if (!paths)
		exit(EXIT_FAILURE);
	if (check_cmd_path_loop(each_path, exec_path, paths, cmd) == 1)
		return (1);
	ft_free_array(paths);
	return (0);
}
