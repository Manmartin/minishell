/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:45:18 by manmarti          #+#    #+#             */
/*   Updated: 2021/11/28 18:34:11 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_data	g_data;

void	init_data(void)
{
	g_data.pwd = getenv("PWD");
	g_data.user = getenv("USER");
	g_data.prompt = get_prompt();
}

int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	init_data();
	get_env(env);
	while (true)
	{
		g_data.line = readline(g_data.prompt);
		free(g_data.line);
	}
	return (0);
}
