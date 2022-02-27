/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:22:56 by acrucesp          #+#    #+#             */
/*   Updated: 2022/02/27 18:14:39 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	cd(t_cmd *cmd)
{
	char	*path;
	int		size;

	size = ft_strlen(cmd->argv[1]) + ft_strlen(get_env("PWD")) + 2;
	path = ft_calloc(sizeof(char), size);
	chdir(cmd->argv[1]);	
	path = getcwd(path, size);
	set_env(ft_strdup("PWD"), path);
	return (0);
}

int	cd_exec(t_cmd *cmd)
{
	int		error;

	error = chdir(cmd->argv[1]);	
	if (error == -1)
	{
		write(STDERR_FILENO, "cd: ", 4);
		write(STDERR_FILENO, cmd->argv[1], ft_strlen(cmd->argv[1]));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
	}
	return (0);
}

int	should_move(t_cmd **cmds)
{
	if (g_data.n_cmd == 1 && !ft_strncmp(cmds[0]->argv[0], "cd", 3))
		cd(cmds[0]);
	if (g_data.n_cmd == 1 && !ft_strncmp(cmds[0]->argv[0], "export", 7))
		export(cmds[0]);
	return (0);
}
