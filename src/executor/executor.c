/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:51:57 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/13 00:01:07 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	make_dup(int fd[2], int used, int dupped)
{
	close(fd[!used]);
	dup2(fd[used], dupped);
	close(fd[used]);
}

/* Norminette make me do this 
	pathname will be not needed
*/

static void	exec_command(t_cmd *cmd, char *pathname, int fd[2])
{
	if (cmd != NULL)
		make_dup(fd, WRITE_FD, STDOUT_FILENO);
	execve(pathname, cmd->argv, g_data.env);
}

/* 
	-Meter la busqueda del pathname en la parte del parser
	-Eliminar la n en cuanto deje de ser necesaria
	-Hacerlo todo a traves de cmd y no con contadores
*/

void	executor(t_cmd **cmd)
{
	pid_t	pid;
	char	*pathname;
	int		fd1[2];
	int		n;

	n = 4; // Not needed line
	pathname = get_path((*cmd)->argv[0]); // Not needed line
	if (n > 1)
		pipe(fd1);
	pid = fork();
	if (pid == 0)
		exec_command(*cmd, pathname, fd1);
	while (*(++cmd) != NULL)
	{
		free(pathname); // Not needed line
		pathname = get_path((*cmd)->argv[0]); // Not needed line
		make_dup(fd1, READ_FD, STDIN_FILENO);
		if (cmd[1] != NULL)
			pipe(fd1);
		pid = fork();
		if (pid == 0)
			exec_command(*cmd, pathname, fd1);
	}
	waitpid(pid, NULL, 0);
	exit(0);
}