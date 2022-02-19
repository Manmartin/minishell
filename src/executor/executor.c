/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:51:57 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/19 19:50:30 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	make_dup(int fd[2], int used, int dupped)
{
	close(fd[!used]);
	dup2(fd[used], dupped);
	close(fd[used]);
}

/* Norminette make me do this 
	pathname will be not needed
*/

static void	exec_command(t_cmd **cmd, char *pathname, int fd[2])
{
	if (cmd[1] != NULL)
		make_dup(fd, WRITE_FD, STDOUT_FILENO);
	redirects(cmd[0]->rdtns);
	if (is_builtin(cmd[0]->argv[0]))
	{
	}
	else if (pathname)
		execve(pathname, cmd[0]->argv, g_data.env);
	exit(0);
}

/* 
	-Meter la busqueda del pathname en la parte del parser
	-Eliminar la n en cuanto deje de ser necesaria
*/

void	executor(t_cmd **cmd)
{
	pid_t	pid;
	char	*pathname;
	int		fd1[2];
	int		status;
	int		n;

	n = 1; // Not needed line
	pathname = get_path((*cmd)->argv[0]); // Not needed line
	if (cmd[1] != NULL)
		pipe(fd1);
	pid = fork();
	if (pid == 0)
		exec_command(cmd, pathname, fd1);
	else if (pid == -1)
		exit(errno);
	while (*(++cmd) != NULL)
	{
		free(pathname); // Not needed line
		pathname = get_path((*cmd)->argv[0]); // Not needed line
		close(fd1[WRITE_FD]);
		if (cmd[1] != NULL)
			pipe(fd1);
		pid = fork();
		if (pid == 0)
		{
			make_dup(fd1, READ_FD, STDIN_FILENO);
			exec_command(cmd, pathname, fd1);
		}
		else if (pid == -1)
			exit(-1);
	}
	for (int i = 0; i < n; i++)
		wait(&status);
}
