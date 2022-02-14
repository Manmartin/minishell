/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:45:18 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/14 20:53:05 by manmarti         ###   ########.fr       */
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
	t_cmd				**comando;
	char *r1[] = {"seq", "-500", "500", NULL};
	char *r2[] = {"sort", "-R", NULL};
	char *r3[] = {"head", "-n","20", NULL};
	char *r4[] = {"wc", "-l", NULL};

	(void)argc;
	(void)argv;
	init_env(env);
	init_data();
	comando = malloc(sizeof(t_cmd *) * 5);
	for (int i = 0; i < 5; i++)
		comando[i] = malloc(sizeof(t_cmd));
	comando[0]->argv = r1;
	comando[1]->argv = r2;
	comando[2]->argv = r3;
	comando[3]->argv = r4;
	comando[4] = NULL;
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
				executor(comando);
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
