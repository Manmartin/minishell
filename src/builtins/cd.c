/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:22:56 by acrucesp          #+#    #+#             */
/*   Updated: 2022/03/02 13:56:09 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	cd(t_cmd *cmd)
{
	char	*path;
	int		size;

	if (!cmd->argv[1] || cmd->argv[2])
		return (0);
	size = 4096;
	path = ft_calloc(sizeof(char), size);
	chdir(cmd->argv[1]);
	path = getcwd(path, size);
	set_env(ft_strdup("PWD"), path);
	return (0);
}

int	cd_exec(t_cmd *cmd)
{
	int		error;
	char	*path;

	if (!cmd->argv[1] || cmd->argv[1][0] == '\0')
		return (0);
	if (cmd->argv[2])
	{
		ft_putendl_fd("cd: too many arguments", STDERR_FILENO);
		return (0);
	}
	else if (cmd->argv[1] == NULL)
		path = get_env("HOME");
	else
		path = cmd->argv[1];
	error = chdir(path);
	if (error == -1)
	{
		write(STDERR_FILENO, "cd: ", 4);
		write(STDERR_FILENO, cmd->argv[1], ft_strlen(cmd->argv[1]));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
	}
	return (0);
}
