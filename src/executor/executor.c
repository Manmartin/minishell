/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:51:57 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/28 17:27:44 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
	env_builtins(cmds);
	free_all_cmds(cmds);
	free(g_data.pids);
	s_status = ft_itoa(WEXITSTATUS(status));
	if (!s_status)
		exit_error("malloc");
	set_env(ft_strdup("?"), s_status);
	init_data();
}

static void	create_pipes(int (*fd)[2][2], t_cmd **cmd)
{
	int	pid;

	close((*fd)[0][WRITE_FD]);
	if (cmd[1] != NULL)
		pipe((*fd)[1]);
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
		signal(SIGINT, manage_signals);
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
}
