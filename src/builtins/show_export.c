/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:22:28 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/01 17:03:48 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_export(void)
{
	int	i;
	int	j;
	int	eq;

	i = -1;
	eq = 0;
	while (g_data.env[++i])
	{
		j = -1;
		ft_putstr_fd("declare -x ", STDIN_FILENO);
		while (g_data.env[i][++j])
		{
			ft_putchar_fd(g_data.env[i][j], STDOUT_FILENO);
			if (g_data.env[i][j] == '=' && eq == 0)
			{
				eq = 1;
				ft_putchar_fd('"', STDOUT_FILENO);
			}
			if (g_data.env[i][j + 1] == '\0' && eq == 1)
				ft_putchar_fd('"', STDOUT_FILENO);
		}
		eq = 0;
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}

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
					ft_strlen(g_data.env[i]) + 1) > 0)
			{
				aux = g_data.env[i];
				g_data.env[i] = g_data.env[j];
				g_data.env[j] = aux;
			}
		}
	}
	print_export();
}
