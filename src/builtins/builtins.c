/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:27:56 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/20 14:04:26 by manuel           ###   ########.fr       */
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
	if (!ft_strncmp(cmd->argv[0], "echo", 5))
	{
	}
	else if (!ft_strncmp(cmd->argv[0], "cd", 3))
	{
	}
	else if (!ft_strncmp(cmd->argv[0], "pwd", 4))
	{
	}
	else if (!ft_strncmp(cmd->argv[0], "export", 7))
	{
	}
	else if (!ft_strncmp(cmd->argv[0], "unset", 6))
	{
	}
	else if (!ft_strncmp(cmd->argv[0], "env", 4))
	{
	}
	else if (!ft_strncmp(cmd->argv[0], "exit", 5))
	{
	}
}
