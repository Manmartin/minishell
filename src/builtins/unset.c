/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:20:42 by acrucesp          #+#    #+#             */
/*   Updated: 2022/02/27 20:26:14 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	get_lastenv(void)
{
	int		k;

	k = 0;
	while (g_data.env[k] != NULL)
		k++;
	k--;
	return (k);
}

void	unset(t_cmd *cmd)
{
	int		i;
	size_t	sz;
	char	*name;
	int		j;
	int		k;

	j = 0;
	while (cmd->argv[++j])
	{
		k = get_lastenv();
		name = cmd->argv[j];
		i = -1;
		sz = ft_strlen(name);
		while (g_data.env[++i])
			if (ft_strncmp(g_data.env[i], name, sz) == 0
				&& g_data.env[i][sz] == '=')
				break ;
		if (g_data.env[i] != NULL)
		{
			free(g_data.env[i]);
			g_data.env[i] = g_data.env[k];
			g_data.env[k] = NULL;
		}
	}
}
