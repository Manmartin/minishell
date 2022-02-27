/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:12:07 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/27 12:58:08 by manmarti         ###   ########.fr       */
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

/* Free tokens flags */

# define T_EXIT		0
# define T_NEXIT	1

/*	Prompt */

# define PROMPT "[minishell]> " 

# define N_BUILTINS 7 

#endif
