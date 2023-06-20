/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:31:29 by abourgue          #+#    #+#             */
/*   Updated: 2023/06/20 14:17:47 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*temp;
	char	*command;

	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_cmd(char **args, char **envp, t_pipex process)
{
	if (dup2(process.tube[1], 1) == -1)
		msg(ERR_DUP);
	close(process.tube[0]);
	if (dup2(process.fd[0], STDIN_FILENO) == -1)
		msg(ERR_DUP);
	process.cmd_args = ft_split(args[2], ' ');
	process.cmd = get_cmd(process.cmd_path, process.cmd_args[0]);
	if (!process.cmd)
	{
		child_free(&process);
		exit(msg(ERR_CMD));
	}
	execve(process.cmd, process.cmd_args, envp);
	child_free(&process);
}

void	second_cmd(char **args, char **envp, t_pipex process)
{
	if (dup2(process.tube[0], 0) == -1)
		msg(ERR_DUP);
	close(process.tube[1]);
	if (dup2(process.fd[1], STDOUT_FILENO) == -1)
		msg(ERR_DUP);
	process.cmd_args = ft_split(args[3], ' ');
	process.cmd = get_cmd(process.cmd_path, process.cmd_args[0]);
	if (!process.cmd)
	{
		child_free(&process);
		exit(msg(ERR_CMD));
	}
	execve(process.cmd, process.cmd_args, envp);
	child_free(&process);
}
