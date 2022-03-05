/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:20:42 by acrucesp          #+#    #+#             */
/*   Updated: 2022/03/05 18:57:58 by acrucesp         ###   ########.fr       */
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

static void	error_message(char *env_var)
{
	int	i;
	int	b;

	i = 0;
	b = 1;
	while (env_var[i] && b)
	{
		if (i == 0)
		{
			if (!ft_isalpha(env_var[i]) && env_var[i] != '_')
				b = 0;
		}
		else
			if (!ft_isalnum(env_var[i]) && env_var[i] != '_')
				b = 0;
		i++;
	}
	if (!b)
	{
		write(STDERR_FILENO, "unset: `", 8);
		write(STDERR_FILENO, env_var, ft_strlen(env_var));
		write(STDERR_FILENO, "': not a valid identifier\n", 27);
	}
}

void	unset_exec(t_cmd *cmd)
{
	int		i;
	size_t	sz;
	int		j;
	int		k;

	j = 0;
	while (cmd->argv[++j])
	{
		k = get_lastenv();
		i = -1;
		sz = ft_strlen(cmd->argv[j]);
		error_message(cmd->argv[j]);
		while (g_data.env[++i])
			if (ft_strncmp(g_data.env[i], cmd->argv[j], sz) == 0
				&& (g_data.env[i][sz] == '='
				|| g_data.env[i][sz] == '\0'))
				break ;
		if (g_data.env[i] != NULL)
		{
			free(g_data.env[i]);
			g_data.env[i] = g_data.env[k];
			g_data.env[k] = NULL;
		}
	}
}

void	unset(t_cmd *cmd)
{
	int		i;
	size_t	sz;
	int		j;
	int		k;

	j = 0;
	while (cmd->argv[++j])
	{
		k = get_lastenv();
		i = -1;
		sz = ft_strlen(cmd->argv[j]);
		while (g_data.env[++i])
			if (ft_strncmp(g_data.env[i], cmd->argv[j], sz) == 0
				&& (g_data.env[i][sz] == '='
				|| g_data.env[i][sz] == '\0'))
				break ;
		if (g_data.env[i] != NULL)
		{
			free(g_data.env[i]);
			g_data.env[i] = g_data.env[k];
			g_data.env[k] = NULL;
		}
	}
}
