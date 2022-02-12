/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:27:56 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/12 23:58:04 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_builtin(const char *const cmd)
{
	size_t	i;
	char 	*builtins[N_BUILTINS] = {"echo", "cd", "pwd",
		"export", "unset", "env", "exit"};

	i = -1;
	while (++i < N_BUILTINS)
		if (!ft_strncmp(cmd, builtins[i], ft_strlen(cmd) + 1))
			return (true);
	return (false);
}
