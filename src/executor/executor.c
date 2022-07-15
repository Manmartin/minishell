/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:51:57 by manmarti          #+#    #+#             */
/*   Updated: 2022/07/15 16:44:13 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	exec_command(t_cmd **cmd, int fd[2])
{
	if (cmd[1] != NULL)
		make_dup(fd, WRITE_FD, STDOUT_FILENO);
	redirects(cmd[0]->rdtns);
	if (is_builtin(cmd[0]->argv[0]))
		exec_builtin(cmd);
	else if (cmd[0]->pathname)
	{
		if (cmd[0]->pathname[0] == '\0')
			exit(0);
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

static int	get_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WTERMSIG(status))
	{
		if (status == 2)
			return (130);
		if (status == 3)
			return (131);
	}
	return (status);
}

static void	wait_childs(t_cmd **cmds)
{
	int		status;
	char	*s_status;
	int		i;

	i = 0;
	while (i < g_data.n_cmd)
	{
		waitpid(g_data.pids[i++], &status, 0);
		cmds--;
	}
	status = get_status(status);
	env_builtins(cmds);
	free_all_cmds(cmds);
	s_status = ft_itoa(status);
	if (!s_status)
		exit_error("malloc");
	set_env(ft_strdup("?"), s_status);
}

static void	create_pipes(int (*fd)[2][2], t_cmd **cmd)
{
	int	pid;

	if (cmd[1] != NULL)
		pipe((*fd)[1]);
	close((*fd)[0][WRITE_FD]);
	pid = fork();
	if (pid == 0)
	{
		make_dup((*fd)[0], READ_FD, STDIN_FILENO);
		exec_command(cmd, (*fd)[1]);
	}
	else if (pid == -1)
	{
		make_dup((*fd)[0], READ_FD, STDIN_FILENO);
		exec_command(cmd, (*fd)[1]);
	}
	close((*fd)[0][READ_FD]);
	(*fd)[0][0] = (*fd)[1][0];
	(*fd)[0][1] = (*fd)[1][1];
	add_pid(pid);
}

void	executor(t_cmd **cmd)
{
	pid_t	pid;
	int		fd[2][2];

	if (make_heredocs(cmd))
	{
		if (cmd[1] != NULL)
			pipe(fd[0]);
		pid = fork();
		if (pid == 0)
			exec_command(cmd, fd[0]);
		else if (pid == -1)
			exit_error("fork");
		add_pid(pid);
		while (*(++cmd) != NULL)
			create_pipes(&fd, cmd);
		wait_childs(cmd);
	}
	else
		free_all_cmds(cmd);
	free_exec();
	signal(SIGQUIT, SIG_IGN);
}
