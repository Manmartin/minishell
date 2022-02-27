/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:22:56 by acrucesp          #+#    #+#             */
/*   Updated: 2022/02/27 19:29:21 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	cd(t_cmd *cmd)
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
