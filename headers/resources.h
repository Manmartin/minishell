/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:12:07 by manmarti          #+#    #+#             */
/*   Updated: 2021/11/23 22:54:44 by manmarti         ###   ########.fr       */
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

# define PROMPT "-g-u-e:-b-p-e$ " 

#endif