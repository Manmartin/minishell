/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:45:18 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/10 17:45:20 by manmarti         ###   ########.fr       */
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

void	free_data(void)
{
	free(g_data.pwd);
	free(g_data.user);
	free(g_data.prompt);
	free_env();
}

int	main(int argc, char *argv[], char *env[])
{
	t_list	*tokens;

	(void)argc;
	(void)argv;
	init_env(env);
	init_data();
	while (true)
	{
		g_data.line = readline(g_data.prompt);
		if (g_data.line)
		{
			tokens = lexer(g_data.line);
			free(g_data.line);
			if (quote_checker(tokens))
			{
			}
		}
	}
	return (0);
}
