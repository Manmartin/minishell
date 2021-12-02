/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:45:18 by manmarti          #+#    #+#             */
/*   Updated: 2021/12/02 11:11:28 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_data	g_data;

void	init_data(void)
{
	g_data.pwd = get_env("PWD");
	g_data.user = get_env("USER");
	g_data.prompt = get_prompt();
}

int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	init_env(env);
	init_data();
	while (true)
	{
		g_data.line = readline(g_data.prompt);
		if (g_data.line)
			lexer(g_data.line);
		free(g_data.line);
	}
	return (0);
}
