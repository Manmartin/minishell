/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:59:54 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/19 14:32:28 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	manage_signals(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signals(void)
{
	struct sigaction	set;

	ft_memset(&set, 0, sizeof(set));
	set.sa_handler = manage_signals;
	sigaction(SIGINT, &set, NULL);
	signal(SIGQUIT, SIG_IGN);
}
