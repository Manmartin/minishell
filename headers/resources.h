/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:12:07 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/13 10:28:17 by manuel           ###   ########.fr       */
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

#define TYPES ">,>>,<,<<"

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

# define PROMPT "-g-u-e:-b-p-e$ " 

#endif
