/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:52:35 by acrucesp          #+#    #+#             */
/*   Updated: 2022/02/26 20:12:16 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	echo(t_cmd *cmd)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!ft_strncmp(cmd->argv[i + 1], "-n", 3))
	{
		i++;
		k = 1;
	}
	while (cmd->argv[++i])
	{
		write(1, cmd->argv[i], ft_strlen(cmd->argv[i]));
		if (cmd->argv[i + 1])
			write(1, " ", 1);
	}
	if (!k)
		write(1, "\n", 1);
	return (0);
}
