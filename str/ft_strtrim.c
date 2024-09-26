/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:26:52 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:54:14 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_strtrim|═══════════════════════════════════════════════════════════════*

	Purpose:	Removes characters from the beginning and end of a string `s1` 
				that are present in a given set `set`. The function creates 
				a new string with the trimmed result, leaving the original 
				string untouched.
				
	Parameters:
				s1 (IN) -- The original null-terminated string to trim.
				set (IN) -- The set of characters to remove from `s1`.

	Returns:	A pointer to a newly allocated string with the trimmed result. 
				Returns `NULL` if memory allocation fails or if either `s1` 
				or `set` is `NULL`.

	Notes:		The caller is responsible for freeing the returned string 
				to avoid memory leaks. If `s1` consists entirely of characters 
				from `set`, the function returns an empty string.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;
	size_t	trimmed_len;

	start = 0;
	end = 0;
	if (!s1 || !set)
		return (0);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	trimmed_len = ft_strlen(s1 + start);
	while (trimmed_len && ft_strchr(set, s1[start + trimmed_len - 1]))
		trimmed_len--;
	ret = malloc(trimmed_len + 1);
	if (!ret)
		return (0);
	while (end < trimmed_len)
	{
		ret[end] = s1[start + end];
		end++;
	}
	ret[end] = '\0';
	return (ret);
}
