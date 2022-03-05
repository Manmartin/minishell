/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:40:13 by manuel            #+#    #+#             */
/*   Updated: 2022/03/05 21:46:32 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	move_env(void)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_calloc(g_data.sz_env * 2, sizeof(char *));
	if (tmp == NULL)
		exit_error("malloc");
	while (g_data.env[++i] != NULL)
		tmp[i] = g_data.env[i];
	free(g_data.env);
	g_data.env = tmp;
	g_data.sz_env *= 2;
}

void	set_env(char *name, char *value)
{
	int		i;
	size_t	sz;
	char	*aux;

	i = -1;
	sz = ft_strlen(name);
	while (g_data.env[++i])
		if (ft_strncmp(g_data.env[i], name, sz) == 0
			&& (g_data.env[i][sz] == '='
			|| g_data.env[i][sz] == '\0'))
			break ;
	if (i == g_data.sz_env - 1)
		move_env();
	if (g_data.env[i] != NULL)
		free(g_data.env[i]);
	if (value)
		aux = append_string(name, ft_strdup("="));
	else
	{
		value = ft_strdup("");
		aux = name;
	}
	g_data.env[i] = append_string(aux, value);
}

int	parse_arg(t_cmd *cmd, int i)
{
	int	j;

	j = 0;
	if (cmd->argv[i][j] == '_' || ft_isalpha(cmd->argv[i][0]))
	{
		while (cmd->argv[i][++j])
		{
			if (!ft_isexp(cmd->argv[i][j]) && cmd->argv[i][j] != '=')
				return (0);
			else if (cmd->argv[i][j] == '=')
				return (1);
			j++;
		}	
	}
	else
		return (0);
	return (1);
}

int	export(t_cmd *cmd)
{
	int		i;
	char	*name;
	char	*value;

	i = 0;
	while (cmd->argv[++i])
	{
		if (parse_arg(cmd, i))
		{
			name = ft_strdup(cmd->argv[i]);
			if (ft_strchr(name, '=') != NULL)
			{
				*ft_strchr(name, '=') = '\0';
				value = ft_strdup(ft_strchr(cmd->argv[i], '=') + 1);
				set_env(name, value);
			}
			else
			{
				if (!exist_env(name))
					set_env(name, NULL);
			}
		}
	}
	return (0);
}

int	export_exec(t_cmd *cmd)
{
	int		i;

	i = 0;
	if (cmd->argv[1] == NULL)
		show_export();
	while (cmd->argv[++i])
	{
		if (!parse_arg(cmd, i))
		{
			ft_putstr_fd("export: `", STDERR_FILENO);
			ft_putstr_fd(cmd->argv[i], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
		}
	}
	return (0);
}
