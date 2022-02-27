/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:27:56 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/27 15:30:14 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_builtin(const char *const cmd)
{
	if (!ft_strncmp(cmd, "echo", 5))
		return (true);
	else if (!ft_strncmp(cmd, "cd", 3))
		return (true);
	else if (!ft_strncmp(cmd, "pwd", 4))
		return (true);
	else if (!ft_strncmp(cmd, "export", 7))
		return (true);
	else if (!ft_strncmp(cmd, "unset", 6))
		return (true);
	else if (!ft_strncmp(cmd, "env", 4))
		return (true);
	else if (!ft_strncmp(cmd, "exit", 5))
		return (true);
	return (false);
}

void	exec_builtin(t_cmd *cmd)
{
	int	value;

	value = 0;
	if (!ft_strncmp(cmd->argv[0], "echo", 5))
		value = echo(cmd);
	else if (!ft_strncmp(cmd->argv[0], "pwd", 4))
		value = pwd();
	else if (!ft_strncmp(cmd->argv[0], "cd", 4))
		value = cd_exec(cmd);
	else if (!ft_strncmp(cmd->argv[0], "export", 7))
		value = export(cmd);
	else if (!ft_strncmp(cmd->argv[0], "unset", 6))
	{
	}
	else if (!ft_strncmp(cmd->argv[0], "env", 4))
		value = env();
	else if (!ft_strncmp(cmd->argv[0], "exit", 5))
	{
	}
	exit(value);
}
