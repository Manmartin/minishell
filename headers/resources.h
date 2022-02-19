/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:12:07 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/19 20:05:36 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCES_H
# define RESOURCES_H

/* Colors */

# define RED "\e[30m"
# define GREEN "\e[32m"
# define BLUE "\e[34m" 
# define RESET_COLOR "\e[0m"

/* Pipes */

# define READ_FD	0
# define WRITE_FD	1

/* Parser Redirections */

# define TYPES ">,>>,<,<<"

/* Redirections: open flags */

# define W_FLGS O_CREAT | O_WRONLY | O_TRUNC
# define A_FLGS O_CREAT | O_WRONLY | O_APPEND
# define I_FLGS O_RDONLY
# define F_PERM S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH

# define HERE_DOCS "/tmp/.tmpheredocsminishell"

/*	Prompt */
/*	Prompt variables
 *		-u = user
 *		-p = current directory
 *		
 *		-r = red
 *		-g = green
 *		-b = blue
 *		-e = end color
 *		-- = '-'
*/

# define PROMPT "-u:-p$ " 

# define N_BUILTINS 7 

#endif
