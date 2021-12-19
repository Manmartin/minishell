/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:45:57 by acrucesp          #+#    #+#             */
/*   Updated: 2021/12/19 20:12:38 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

typedef struct	s_cmd {
	t_list	*rdctns;
	char	**argv;
	int		argc;
}				t_cmd;

//declarar enum typos
typedef struct	s_rdctns {
	enum	type;
	char	*file;
}				t_rdnctns;

//t_list tokens >> t_list cmds >> cmd >> rdctns

int		count_pipes(t_list *tokens)
{
	int	n_cmds;

	n_cmds = 0;
	while (tokens)
	{
	//aun tengo que evaluar casos raros estilo echa a| > c como reacciona bash
		if (ft_strnstr((char *)tokens->content, "|", 
		ft_strlen((char *)tokens->content)))
			n_cmds++;
		tokens = tokens->next;
	}
	return (n_cmds);
}

char	**parser(t_list *tokens)
{
	int		n_pipes;
	char	**cmds;

	cmds = NULL;
	n_pipes = count_pipes(tokens);
	cmds = ft_calloc(sizeof(char *), n_pipes + 2);
	cmds[n_pipes + 1] = NULL;
	//aun tengo que añadir lo casos de error sintactico

	printf("%d\n", n_pipes);
	return (cmds);
}
