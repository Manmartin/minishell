/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:34:12 by manuel            #+#    #+#             */
/*   Updated: 2022/03/01 10:47:20 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	make_dup(int fd[2], int used, int dupped)
{
	close(fd[!used]);
	dup2(fd[used], dupped);
	close(fd[used]);
}

void	free_exec(void)
{
	if (g_data.pids != NULL)
		free(g_data.pids);
	g_data.pids = NULL;
	g_data.n_cmd = 0;
}

void	add_pid(int pid)
{
	int	i;

	i = 0;
	while (g_data.pids[i] != 0)
		i++;
	g_data.pids[i] = pid;
}
