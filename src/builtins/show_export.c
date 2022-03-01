/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:22:28 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/01 15:52:10 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	show_export(void)
{
	char	*aux;
	int		i;
	int		j;

	i = -1;
	while (g_data.env[++i] != NULL)
	{
		j = i;
		while (g_data.env[++j])
		{
			if (ft_strncmp(g_data.env[i], g_data.env[j],
					ft_strlen(g_data.env[i] + 1)) > 0)
			{
				aux = g_data.env[i];
				g_data.env[i] = g_data.env[j];
				g_data.env[j] = aux;
			}
		}
	}
	i = 0;
	while (g_data.env[i])
		printf("%s\n", g_data.env[i++]);
}
