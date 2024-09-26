/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:49:30 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:54:05 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_strncmp|═══════════════════════════════════════════════════════════════*

	Purpose:	Compares up to `n` characters of two null-terminated strings 
				`s1` and `s2`. The function returns a non-zero value if the 
				strings differ within the first `n` characters, or zero if 
				they are equal.
				
	Parameters:
				s1 (IN) -- The first string to compare.
				s2 (IN) -- The second string to compare.
				n (IN) -- The maximum number of characters to compare.

	Returns:	An integer representing the difference between the first 
				differing characters in `s1` and `s2`. Returns zero if the 
				strings are identical within the specified `n` characters.

	Notes:		If `n` is zero, the function returns zero without comparing 
				the strings. If one of the strings is shorter than `n`, the 
				comparison stops at the null-terminator.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	i = 0;
	u_s1 = (unsigned char *) s1;
	u_s2 = (unsigned char *) s2;
	while ((i < n) && (u_s1[i] || u_s2[i]))
	{
		if (u_s1[i] != u_s2[i])
		{
			return (u_s1[i] - u_s2[i]);
		}
		i++;
	}
	return (0);
}
