/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:07:24 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:54:09 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_strnstr|═══════════════════════════════════════════════════════════════*

	Purpose:	Searches for the first occurrence of the substring `s2` 
				within the first `n` characters of the string `s1`. If 
				`s2` is found, the function returns a pointer to its start 
				in `s1`. If `s2` is not found, or if `n` is too small, 
				the function returns `NULL`.
				
	Parameters:
				s1 (IN) -- The null-terminated string to search within.
				s2 (IN) -- The substring to search for in `s1`.
				n  (IN) -- The maximum number of characters to search in `s1`.

	Returns:	A pointer to the first occurrence of `s2` in `s1` within the 
				first `n` characters. If `s2` is not found, returns `NULL`.

	Notes:		If `s2` is an empty string, the function returns a pointer to 
				the beginning of `s1`. If `n` is zero, the function does 
				nothing and returns `NULL`.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] && i + j < n)
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (0);
}
