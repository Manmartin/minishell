/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:24:12 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/04 11:29:26 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	select_env(char **s, int i)
{
	char	*env_var;
	char	*aux;
	char	*str;
	int		var_len;
	int		j;

	j = 0;
	str = *s;
	while (str[i + j] && ft_isenv(str[i + j]))
		j++;
	aux = ft_substr(str, i, j);
	if (!aux)
		exit_error("malloc");
	env_var = get_env(aux);
	if (!env_var)
		exit_error("malloc");
	free(aux);
	var_len = ft_strlen(env_var);
	*s = append_string(append_string(ft_substr(str, 0, i - 1), env_var),
			ft_substr(str, i + j, ft_strlen(&str[i + j])));
	free(str);
	return (i - 1 + var_len);
}

char	*make_expanded_str(char **str)
{
	t_flags	flags;
	char	*aux;
	int		i;

	i = 0;
	ft_memset(&flags, 0, sizeof(t_flags));
	aux = *str;
	while (aux[i])
	{
		if (aux[i] == '\'' && !flags.d_qts)
			flags.s_qts = !flags.s_qts;
		else if (aux[i] == '"' && !flags.s_qts)
			flags.d_qts = !flags.d_qts;
		if (aux[i] == '$' && ft_isenv(aux[i + 1]) && !flags.s_qts)
			i = select_env(&aux, i + 1) - 1;
		i++;
	}
	return (aux);
}

void	make_expand(char **str, char *flag)
{
	char	*aux;

	aux = ft_strdup(*str);
	*str = make_expanded_str(str);
	if (ft_strncmp(aux, *str, ft_strlen(aux) + 1))
		*flag = 1;
	free(aux);
}
