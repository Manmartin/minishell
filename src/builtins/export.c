/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:40:13 by manuel            #+#    #+#             */
/*   Updated: 2022/02/22 16:39:33 by manuel           ###   ########.fr       */
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
			&& g_data.env[i][sz] == '=')
			break ;
	if (i == g_data.sz_env - 1)
		move_env();
	if (g_data.env[i] != NULL)
		free(g_data.env[i]);
	aux = append_string(name, ft_strdup("="));
	g_data.env[i] = append_string(aux, value);
}

int	export(t_cmd *cmd)
{
	(void)cmd;
	return (-1);
}
