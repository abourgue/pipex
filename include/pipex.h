/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:30:08 by abourgue          #+#    #+#             */
/*   Updated: 2023/05/24 15:11:34 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/*to perror*/
# include <stdio.h>

/* libft */
# include "./libft.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"
# define ERR_DUP "error dup fd\n"

typedef struct s_pipex
{
	int			tube[2];
	int			fd[2];
	pid_t		pid1;
	pid_t		pid2;
	char		*envp_path;
	char		**cmd_path;
	char		**cmd_args;
	char		*cmd;
}	t_pipex;

void	first_cmd(char **args, char **envp, t_pipex process);
void	second_cmd(char **args, char **envp, t_pipex process);
void	child_free(t_pipex *process);
void	parent_free(t_pipex *process);
void	close_pipes(t_pipex *process);
void	msg_error(char *error);
int		msg(char *error);

#endif