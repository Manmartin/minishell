/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:33:45 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/26 21:44:36 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	exit_error(char *msg)
{
	perror(msg);
	exit(errno);
}

void	exit_shell_error(char *msg, int code)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	if (code != -1)
		exit(code);
}
