/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:36:07 by acrucesp          #+#    #+#             */
/*   Updated: 2022/03/04 13:23:39 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	is_str_valid(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
	{
		while (str[++i])
			if (!ft_isdigit(str[i]))
				return (0);
	}
	else
		return (0);
	return (1);
}

static int	msg_error(t_cmd **cmd, int i)
{
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putstr_fd(cmd[0]->argv[i], STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	return (2);
}

void	exitchan(t_cmd **cmd)
{
	int	value;
	int	i;

	value = 0;
	i = 0;
	ft_putendl_fd("exit", STDOUT_FILENO);
	while (cmd[0]->argv[++i])
	{
		if (!is_str_valid(cmd[0]->argv[i]))
		{
			value = msg_error(cmd, i);
			break ;
		}
		else if (i > 1)
		{
			ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
			value = 1;
			return ;
		}
		else
			value = ft_atoi(cmd[0]->argv[i]);
	}
	free_all_cmds(cmd);
	free_data();
	exit(value);
}

void	exit_exec(t_cmd **cmd)
{
	int	value;
	int	i;

	value = 0;
	i = 0;
	while (cmd[0]->argv[++i])
	{
		if (!is_str_valid(cmd[0]->argv[i]))
		{
			if (g_data.n_cmd > 1)
				value = msg_error(cmd, i);
			break ;
		}
		else if (i > 1)
		{
			if (g_data.n_cmd > 1)
				ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
			value = 1;
			break ;
		}
		else
			value = ft_atoi(cmd[0]->argv[i]);
	}
	exit(value);
}
