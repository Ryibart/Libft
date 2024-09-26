/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:51:02 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:54:11 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_strrchr|═══════════════════════════════════════════════════════════════*

	Purpose:	Finds the last occurrence of the character `c` in a 
				null-terminated string `s`. The function searches from the 
				end of the string to the beginning and returns a pointer 
				to the found character. If `c` is not found, it returns `NULL`.
				
	Parameters:
				s (IN) -- The null-terminated string to search through.
				c (IN) -- The character to search for in the string `s`.

	Returns:	A pointer to the last occurrence of the character `c` in the 
				string `s`. If `c` is not found, returns `NULL`. If `c` is the 
				null-terminator, it returns a pointer to the null-terminator 
				at the end of the string.

	Notes:		If `c` is not found in the string, the function returns `NULL`. 
				Be cautious of buffer overflows by ensuring `s` points to a 
				valid null-terminated string.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	u_c;

	i = ft_strlen(s) - 1;
	u_c = (char)c;
	while (i >= 0)
	{
		if (s[i] == u_c)
			return ((char *)&s[i]);
		i--;
	}
	if (u_c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	return (0);
}
