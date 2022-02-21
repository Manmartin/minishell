/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:12:07 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/21 22:20:31 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCES_H
# define RESOURCES_H

/* Colors */

# define RED "\e[30m"
# define GREEN "\e[32m"
# define BLUE "\e[34m" 
# define RESET_COLOR "\e[0m"

/* Parser redirections */

# define TYPES ">,>>,<,<<"

/* Pipes */

# define READ_FD	0
# define WRITE_FD	1

/* Here docs temp file */

# define HERE_DOCS "/tmp/.tmpheredocsminishell"

/*	Prompt */

# define PROMPT "[minishell]> " 

# define N_BUILTINS 7 

#endif
