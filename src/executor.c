/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:51:57 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/11 20:45:22 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define READ_FD		0
#define WRITE_FD	1
bool	is_builtin(const char *const cmd)
{
	size_t	i;
	char 	*builtins[N_BUILTINS] = {"echo", "cd", "pwd",
		"export", "unset", "env", "exit"};

	i = -1;
	while (++i < N_BUILTINS)
		if (!ft_strncmp(cmd, builtins[i], ft_strlen(cmd) + 1))
			return (true);
	return (false);
}

void	executor(t_cmd *cmd)
{
	pid_t	pid;
	char	*pathname;

	int n, m, fd1[2], fd2[2];
	n = 4;
	m = n;
	if (n > 1)
		pipe(fd1);
	n--;
	pathname = get_path(cmd->argv[0]);
	pid = fork();
	if (pid == 0)
	{
		if (n > 0)
		{
			close(fd1[READ_FD]);
			dup2(fd1[WRITE_FD], STDOUT_FILENO);
			close(fd1[WRITE_FD]);
		}
		execve(pathname, cmd->argv, g_data.env);
	}
	while (n)
	{
		cmd++;
		free(pathname);
		pathname = get_path(cmd->argv[0]);
		close(fd1[WRITE_FD]);
		dup2(fd1[READ_FD], STDIN_FILENO);
		close(fd1[READ_FD]);
		n--;
		if (n > 0)
			pipe(fd2);
		pid = fork();
		if (pid == 0)
		{
			if (n > 0)
			{
				close(fd2[READ_FD]);
				dup2(fd2[WRITE_FD], STDOUT_FILENO);
				close(fd2[WRITE_FD]);
			}
			execve(pathname, cmd->argv, g_data.env);
		}
		if (n > 0)
		{
			fd1[READ_FD] = fd2[READ_FD];
			fd1[WRITE_FD] = fd2[WRITE_FD];
		}
	}
	for (int i = 0; i < m; i++)
		waitpid(pid, NULL, 0);
	/*
	while (cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			if (pathname)
				execve(pathname, cmd->argv ,g_data.env);
			else
				printf("wrong\n");
			perror("execve");
			exit(-1);
		}
		else
			waitpid(pid, &wstatus, 0);
		exit(1);
		if (pathname)
		{
			free(pathname);
			pathname = NULL;
		}
		cmd++;
	}
	*/
}
