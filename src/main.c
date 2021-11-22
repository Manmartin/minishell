/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:45:18 by manmarti          #+#    #+#             */
/*   Updated: 2021/11/22 23:51:18 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(void)
{
	t_data	g_data;

	g_data.prompt = "test> ";
	while (true)
	{
		g_data.line = readline(g_data.prompt);
		free(g_data.line);
	}
	return (0);
}
