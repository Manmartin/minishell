/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:51:57 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/03 16:02:50 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
	int		wstatus;
	char	*pathname;

	while (cmd)
	{
		pathname = get_path(cmd->argv[0]); 
		printf("%s\n",  pathname);
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
}
