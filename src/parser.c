/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:45:57 by acrucesp          #+#    #+#             */
/*   Updated: 2021/12/18 17:53:55 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

typedef struct s_cmd {
	t_list	*simple_cmd;
}

char **parser(t_list *args)
{
	int		n_pipes;
	t_list	*tmp_args;

	n_pipes = 0;
	tmp_args = NULL;
	while (args)
	{
		if ((char *)args->content
		args = args->next;
	}

}
