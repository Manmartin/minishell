/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:44:37 by acrucesp          #+#    #+#             */
/*   Updated: 2022/03/05 21:44:58 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	exist_env(char *str)
{
	int		i;
	size_t	sz;

	i = 0;
	sz = ft_strlen(str);
	while (g_data.env[i])
	{
		if (ft_strncmp(g_data.env[i], str, sz) == 0
			&& g_data.env[i][sz] == '=')
			return (1);
		i++;
	}
	return (0);
}
