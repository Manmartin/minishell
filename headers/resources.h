/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:12:07 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/25 15:11:14 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCES_H
# define RESOURCES_H

/* Colors */

# define RED "\e[30m"
# define GREEN "\e[32m"
# define BLUE "\e[34m" 
# define RESET_COLOR "\e[0m"

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

# define BUILTINS {"echo", "cd"}

#endif
