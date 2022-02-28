/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:37:22 by manuel            #+#    #+#             */
/*   Updated: 2022/02/28 21:58:33 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	env(void)
{
	int	i;

	i = -1;
	while (g_data.env[++i] != NULL)
		if (ft_strchr(g_data.env[i], '='))
			ft_putendl_fd(g_data.env[i], STDOUT_FILENO);
	return (0);
}
