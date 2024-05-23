/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:58:46 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/23 16:28:10 by fbelotti         ###   ########.fr       */
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

char	*found_path(char *cmd, t_env *env)
{
	char	*each_path;
	char	*exec_path;
	char	**paths;
	int		i;

	i = 0;
	paths = extract_path_from_env(env);
	if (!paths)
	{
		perror("ERROR : PATH not found in the environnement\n");
		exit(EXIT_FAILURE);
	}
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
	perror("ERROR : executable not found\n");
	return (NULL);
}

int	check_cmd_path(char *cmd, t_env *env)
{
	char	*each_path;
	char	*exec_path;
	char	**paths;
	int		i;

	i = 0;
	paths = extract_path_from_env(env);
	if (!paths)
		exit(EXIT_FAILURE);
	while (paths[i])
	{
		each_path = ft_strjoin(paths[i], "/");
		exec_path = ft_strjoin(each_path, cmd);
		free(each_path);
		if (access(exec_path, X_OK) == 0)
			return (1);
		free(exec_path);
		i++;
	}
	ft_free_array(paths);
	return (0);
}
