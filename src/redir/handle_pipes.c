/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:00:10 by fbelotti          #+#    #+#             */
/*   Updated: 2024/05/12 19:45:20 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	**create_pipes(int pipe_nb)
{
	int	i;
	int	**pipes;

	i = 0;
	pipes = (int **)malloc(pipe_nb * sizeof(int *));
	while (i < pipe_nb)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (pipe(pipes[i]) < 0)
		{
			perror("ERROR : while creating a pipe\n");
			return (NULL);
		}
		i++;
	}
	return (pipes);
}
