/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:38:25 by manmarti          #+#    #+#             */
/*   Updated: 2021/11/30 12:44:57 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 *	lexer:
 *		receive a string as argument an return a linked list of strings for
 *		parser
 *
 *	t_flags disable line split while any quotes are open
 *		-d_qts: True if double quotes are open
 *		-s_qts: True if sigle quotes are open
 */

typedef struct s_flags {
	bool	d_qts;
	bool	s_qts;
}	t_flags;

static const char	*check_instructions(const char *line, t_list **args)
{
	while (ft_isforshell(*line))
	{
		if (*line != ' ')
			ft_lstadd_back(args, ft_lstnew(ft_strdup("|")));
		line++;
	}
	return (line);
}

static const char	*make_arg(const char *line, t_flags *flags)
{
	while ((!ft_isforshell(*line) || flags->d_qts || flags->s_qts) && *line)
	{
		if (*line == '\'')
			flags->s_qts = !flags->s_qts;
		else if (*line == '"')
			flags->d_qts = !flags->d_qts;
		line++;
	}
	return (line);
}

t_list	*lexer(const char *line)
{
	char const	*init;
	t_list		*args;
	t_flags		flags;

	args = 0;
	ft_memset(&flags, 0, sizeof(t_flags));
	while (*line)
	{
		init = line;
		line = make_arg(line, &flags);
		if (line != init)
			ft_lstadd_back(&args, ft_lstnew(ft_substr(init, 0, line - init)));
		line = check_instructions(line, &args);
	}
	return (args);
}
