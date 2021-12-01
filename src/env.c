/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:09:38 by acrucesp          #+#    #+#             */
/*   Updated: 2021/12/01 17:10:28 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init_env(char **env)
{
	char	**tmp_env;

	g_data.sz_env = 0;
	while (env[g_data.sz_env])
		g_data.sz_env++;
	g_data.sz_env *= 2;
	g_data.env = ft_calloc(g_data.sz_env, sizeof(char *));
	if (!g_data.env)
	{
		perror("init_env");
		exit(0);
	}
	tmp_env = g_data.env;
	while (*env)
		*tmp_env++ = ft_strdup(*env++);
}
