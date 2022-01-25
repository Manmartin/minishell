/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:05:49 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/20 14:24:37 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*str_append(char *str1, const char *str2)
{
	char	*aux;

	aux = str1;
	str1 = ft_strjoin(str1, str2);
	free(aux);
	return (str1);
}

static char	*put_variables(const char *template, char *prompt)
{
	if (*template == 'u')
		prompt = str_append(prompt, g_data.user);
	else if (*template == 'p')
		prompt = str_append(prompt, g_data.pwd);
	else if (*template == '-')
		prompt = str_append(prompt, "-");
	else if (*template == 'r')
		prompt = str_append(prompt, RED);
	else if (*template == 'g')
		prompt = str_append(prompt, GREEN);
	else if (*template == 'b')
		prompt = str_append(prompt, BLUE);
	else if (*template == 'e')
		prompt = str_append(prompt, RESET_COLOR);
	return (prompt);
}

char	*get_prompt(void)
{
	char	*template;
	char	*prompt;

	template = PROMPT;
	prompt = (char *)ft_calloc(1, sizeof(char));
	if (prompt == NULL)
		exit(-1);
	while (*template)
	{
		if (*template == '-')
			prompt = put_variables(++template, prompt);
		else
			prompt = char_append(prompt, *template);
		template++;
		if (prompt == NULL)
			exit(-1);
	}
	return (prompt);
}
