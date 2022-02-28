/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:36:07 by acrucesp          #+#    #+#             */
/*   Updated: 2022/02/27 21:30:18 by acrucesp         ###   ########.fr       */
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

static void	msg_error(t_cmd **cmd, int i)
{
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putstr_fd(cmd[0]->argv[i], STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
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
			msg_error(cmd, i);
			break ;
		}
		else if (i > 1)
		{
			ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
			break ;
		}
		else
			value = ft_atoi(cmd[0]->argv[i]);
	}
	free_all_cmds(cmd);
	free_data();
	exit(value);
}
