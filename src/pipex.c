/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:39:19 by abourgue          #+#    #+#             */
/*   Updated: 2023/05/18 13:33:56 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// id CHILD_PROCESS = 0

int	check_file(char *path)
{
	int	res;

	res = 0;
	if (access(path, F_OK) == -1)
		return (1);
	if (access(path, R_OK) != -1)
		res += 3;
	if (access(path, W_OK) != -1)
		res += 2;
	printf("check_file : %d\n", res);
	return (res);
}

int change_standard(int type, char *path, t_pipex *process)
{
	if (type == 1)
	{
		process->fd_in = open(path, O_RDONLY);
		if (process->fd_in == -1)
			return (1);
		if (dup2(process->fd_in, STDIN_FILENO) == -1)
			return (2);
	}
	else
	{
		process->fd_out = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (process->fd_out == -1)
			return (1);
		if (dup2(process->fd_in, STDOUT_FILENO) == -1)
			return (2);
	}
	return (0);
}

int	pipex(char **args)
{
	t_pipex	process = {.id = -1};

	if (check_file(args[1]) < 3)
		return (1);
	if (change_standard(1, args[1], &process) != 0)
		return (1);
	if (pipe(process.fd) == -1)
		return (1);
	process.id = fork();
	if (process.id == -1)
		return (2);
	if (process.id == 0)
	{
		close(process.fd[1]);
		printf("salut (child_process)\n");
	}
	else
	{
		printf("salut\n");
	}

	close(process.fd[0]);
	close(process.fd[1]);
	close(process.fd_in);
	close(process.fd_out);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 5)
		return (0);
	if (pipex(argv) != 0)
		return (1);
	printf("COMPILE OK!");
	return (0);
}