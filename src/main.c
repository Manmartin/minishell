/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:45:18 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/28 23:33:16 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_data	g_data;

void	init_data(void)
{
	g_data.n_cmd = 0;
	if (g_data.pids != NULL)
		free(g_data.pids);
	g_data.pids = NULL;
	g_data.fd_closed = 0;
	g_data.fd = dup(STDIN_FILENO);
	signals();
}

void	free_data(void)
{
	rl_clear_history();
	free_env();
}

static void	dup_stdin(void)
{
	if (g_data.fd_closed)
	{
		g_data.fd_closed = 0;
		dup2(g_data.fd, STDIN_FILENO);
	}
}

static int	final_exit(void)
{
	char	*aux;
	int		ret_value;

	ret_value = 0;
	aux = get_env("?");
	if (aux[0] != '\0')
		ret_value = ft_atoi(aux);
	free(aux);
	ft_putstr_fd("exit\n", STDIN_FILENO);
	free_data();
	return (ret_value);
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
			dup_stdin();
		}
		else
			return (final_exit());
	}
}
