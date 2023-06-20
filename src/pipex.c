/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:39:19 by abourgue          #+#    #+#             */
/*   Updated: 2023/06/20 14:17:56 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// id CHILD_PROCESS = 0

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	process;

	if (argc != 5)
		return (msg(ERR_INPUT));
	process.fd[0] = open(argv[1], O_RDONLY);
	if (process.fd[0] < 0)
		msg_error(ERR_INFILE);
	process.fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (process.fd[1] < 0)
		msg_error(ERR_OUTFILE);
	if (pipe(process.tube) == -1)
		msg_error(ERR_PIPE);
	process.envp_path = find_path(envp);
	process.cmd_path = ft_split(process.envp_path, ':');
	process.pid1 = fork();
	if (process.pid1 == 0)
		first_cmd(argv, envp, process);
	process.pid2 = fork();
	if (process.pid2 == 0)
		second_cmd(argv, envp, process);
	close_pipes(&process);
	waitpid(process.pid1, NULL, 0);
	waitpid(process.pid2, NULL, 0);
	parent_free(&process);
	return (0);
}
