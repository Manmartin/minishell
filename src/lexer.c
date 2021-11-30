/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:38:25 by manmarti          #+#    #+#             */
/*   Updated: 2021/11/30 18:07:58 by manmarti         ###   ########.fr       */
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

static int	add_arg(t_list **args, void *str)
{
	t_list	*new;

	new = ft_lstnew(str);
	if (!new || !str)
		return (0);
	ft_lstadd_back(args, new);
	return (1);
}

static const char	*check_instructions(const char *line, t_list **args)
{
	while (ft_isforshell(*line))
	{
		if (*line != ' ')
			if (!(add_arg(args, ft_strdup("|"))))
				return (0);
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

static t_list	*clean_args(t_list **args)
{
	ft_lstclear(args, free);
	perror("lexer");
	return (0);
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
			if (!(add_arg(&args, ft_substr(init, 0, line - init))))
				return (clean_args(&args));
		line = check_instructions(line, &args);
		if (!line)
			return (clean_args(&args));
	}
	return (args);
}
