/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:51:57 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/26 12:24:54 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_builtin(const char *const cmd)
{
	if (!ft_strncmp("echo", cmd, 5))
		return (true);
	else if (!ft_strncmp("cd", cmd, 3))
		return (true);
	else if (!ft_strncmp("pwd", cmd, 4))
		return (true);
	else if (!ft_strncmp("export", cmd, 7))
		return (true);
	else if (!ft_strncmp("unset", cmd, 6))
		return (true);
	else if (!ft_strncmp("env", cmd, 4))
		return (true);
	else if (!ft_strncmp("exit", cmd, 5))
		return (true);
	return (false);
}

/*
void	executor(t_cmd *cmd)
{
	pid_t	pid;
	int		wstatus;
	char	*pathname;

	while (cmd)
	{
		pathname = get_path(cmd->argv[0]); 
		pid = fork();
		if (pid == 0)
		{
			if (pathname)
				execve(pathname, cmd->argv ,g_data.env);
			perror("execve");
			exit(-1);
		}
		waitpid(pid, &wstatus, 0);
		i++;
		if (pathname)
		{
			free(pathname);
			pathname = NULL;
		}
		cmd++;
	}
}
*/
