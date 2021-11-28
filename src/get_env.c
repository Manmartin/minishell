/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:09:38 by acrucesp          #+#    #+#             */
/*   Updated: 2021/11/28 00:12:10 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	get_env(char **env)
{
	char	**tmp_env;
	char	**tmp_envg;

	tmp_env = env;
	g_data.sz_env = 0;
	while (*tmp_env++)
		g_data.sz_env++;
	g_data.env = g_data.env * 2;
	g_data.env = ft_calloc(g_data.sz_env, sizeof(char *));
	if (!g_data.env)
		exit(0);
	tmp_envg = g_data.env;
	while (*env)
		*tmp_envg++ = *env++;
}
