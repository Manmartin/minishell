/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:45:18 by manmarti          #+#    #+#             */
/*   Updated: 2021/11/29 23:17:55 by manmarti         ###   ########.fr       */
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

/*
 * Print list is only for debbuging purpouses, dont use it
 */

static void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
}

int	main(void)
{
	init_data();
	while (true)
	{
		g_data.line = readline(g_data.prompt);
		if (g_data.line)
			print_list(lexer(g_data.line));
		free(g_data.line);
	}
	return (0);
}
