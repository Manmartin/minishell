/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:45:18 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/21 22:22:25 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_data	g_data;

void	init_data(void)
{
	g_data.n_cmd = 0;
	signals();
}

void	free_data(void)
{
	rl_clear_history();
	free_env();
}

int	main(int argc, char *argv[], char *env[])
{
	char	*line;
	t_cmd	**cmds;

	(void)argc;
	(void)argv;
	init_env(env);
	init_data();
	while (true)
	{
		line = readline(PROMPT);
		if (line)
		{
			if (line[0] != '\0')
				add_history(line);
			cmds = parse_string(line);
			if (cmds)
				executor(cmds);
		}
		else
		{
			write(STDOUT_FILENO, "\n", 1);
			free_data();
			return (0);
		}
	}
}
