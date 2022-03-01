/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:19:22 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/01 20:58:16 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	env_builtins(t_cmd **cmds)
{
	if (!cmds[0]->argv[0])
		return (0);
	if (g_data.n_cmd == 1 && !ft_strncmp(cmds[0]->argv[0], "cd", 3))
		cd(cmds[0]);
	else if (g_data.n_cmd == 1 && !ft_strncmp(cmds[0]->argv[0], "export", 7))
		export(cmds[0]);
	else if (g_data.n_cmd == 1 && !ft_strncmp(cmds[0]->argv[0], "unset", 6))
		unset(cmds[0]);
	else if (g_data.n_cmd == 1 && !ft_strncmp(cmds[0]->argv[0], "exit", 5))
		exitchan(cmds);
	return (0);
}
