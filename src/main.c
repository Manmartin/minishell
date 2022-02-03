/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:45:18 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/03 16:04:18 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_data	g_data;

void	init_data(void)
{
	g_data.pwd = get_env("PWD");
	g_data.user = get_env("USER");
	g_data.prompt = get_prompt();
	signals();
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
	t_list				*tokens;
	t_cmd				comando;
	char				*strings[3] = {"ls", "-la", NULL};
	(void)argc;
	(void)argv;
	init_env(env);
	init_data();
	
	comando.rdrcs = NULL;
	comando.argv = strings;
	executor(&comando);
	while (true)
	{
		g_data.line = readline(g_data.prompt);
		if (g_data.line)
		{
			tokens = lexer(g_data.line);
			if (g_data.line[0] != '\0')
				add_history(g_data.line);
			free(g_data.line);
			if (quote_checker(tokens))
			{
				expand_env(tokens);
				while (tokens)
				{
					printf("%s\n", (char *)(tokens->content));
					tokens = tokens->next;
				}

			}
		}
		else
		{
			free_data();
			return (0);
		}
	}
	return (0);
}
