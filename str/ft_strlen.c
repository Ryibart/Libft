/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:50:13 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:59 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_strlen|═══════════════════════════════════════════════════════════════*

	Purpose:	Returns the length of a null-terminated string `s`, excluding 
				the null-terminator. This function counts the number of
				characters in the string until it reaches the end.
				
	Parameters:
				s (IN) -- The null-terminated string whose
						  length is to be measured.

	Returns:	The length of the string `s`, excluding the null-terminator.

	Notes:		If `s` is `NULL`, the function's behavior is undefined. Always 
				ensure `s` is valid before calling this function.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
