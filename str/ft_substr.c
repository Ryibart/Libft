/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:43:43 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:54:17 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_substr|═══════════════════════════════════════════════════════════════*

	Purpose:	Extracts a substring from the given string `s`, starting at 
				the specified index `start`, and having a maximum length `len`.
				The function returns a newly allocated string containing the 
				extracted substring.
				
	Parameters:
				s (IN) -- The original null-terminated string.
				start (IN) -- The starting index from which
							  to extract the substring.
				len (IN) -- The maximum length of the substring to extract.

	Returns:	A pointer to the newly allocated substring. If memory allocation 
				fails, or if the `start` index is beyond the length of `s`, the 
				function returns an empty string.
				If `s` is `NULL`, it returns `NULL`.

	Notes:		If the `start` index is greater than or equal to the length of 
				`s`, the function returns an empty string. If `start + len` 
				exceeds the length of `s`, the substring is truncated to fit 
				the available length. The caller must free the returned string 
				to avoid memory leaks.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	actual_len;

	i = 0;
	actual_len = len;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		actual_len = ft_strlen(s) - start;
	ret = malloc(actual_len + 1);
	if (!ret)
		return (0);
	while (i < actual_len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[actual_len] = '\0';
	return (ret);
}
