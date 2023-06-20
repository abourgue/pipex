/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:34:15 by abourgue          #+#    #+#             */
/*   Updated: 2023/06/20 14:17:53 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_pipes(t_pipex *process)
{
	close(process->tube[0]);
	close(process->tube[1]);
}

void	parent_free(t_pipex *process)
{
	int	i;

	i = 0;
	close(process->fd[0]);
	close(process->fd[1]);
	while (process->cmd_path[i])
	{
		free(process->cmd_path[i]);
		i++;
	}
	free(process->cmd_path);
}

void	child_free(t_pipex *process)
{
	int	i;

	i = 0;
	while (process->cmd_args[i])
	{
		free(process->cmd_args[i]);
		i++;
	}
	free(process->cmd_args);
	free(process->cmd);
}
