/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:51:57 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/22 11:27:22 by manuel           ###   ########.fr       */
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

static void	exec_command(t_cmd **cmd, int fd[2])
{
	if (cmd[1] != NULL)
		make_dup(fd, WRITE_FD, STDOUT_FILENO);
	redirects(cmd[0]->rdtns);
	if (is_builtin(cmd[0]->argv[0]))
		exec_builtin(cmd[0]);
	else if (cmd[0]->pathname)
	{
		execve(cmd[0]->pathname, cmd[0]->argv, g_data.env);
		exit_error("execve");
	}
	else
	{
		ft_putstr_fd(cmd[0]->argv[0], STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		exit(0);
	}
}

static void	wait_childs(void)
{
	int		status;
	char	*s_status;

	while (g_data.n_cmd--)
		wait(&status);
	s_status = ft_itoa(WEXITSTATUS(status));
	set_env(ft_strdup("?"), s_status);
	init_data();
}

/* 
**	This function should not exist
**	Norminnete fault
*/

static void	im_sorry(t_cmd **cmd, int fd1[2][2])
{
	make_dup(fd1[0], READ_FD, STDIN_FILENO);
	exec_command(cmd, fd1[1]);
}

void	executor(t_cmd **cmd)
{
	pid_t	pid;
	int		fd1[2][2];

	if (cmd[1] != NULL)
		pipe(fd1[0]);
	pid = fork();
	if (pid == 0)
		exec_command(cmd, fd1[0]);
	else if (pid == -1)
		exit_error("fork");
	while (*(++cmd) != NULL)
	{
		close(fd1[0][WRITE_FD]);
		if (cmd[1] != NULL)
			pipe(fd1[1]);
		pid = fork();
		if (pid == 0)
			im_sorry(cmd, fd1);
		else if (pid == -1)
			exit(-1);
		fd1[0][0] = fd1[1][0];
		fd1[0][1] = fd1[1][1];
	}
	wait_childs();
}
