/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:16:30 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:57 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_strlcpy|═══════════════════════════════════════════════════════════════*

	Purpose:	Copies the null-terminated string `src` into the buffer `dst`, 
				up to a maximum size `size`. This function ensures the result 
				is null-terminated and does not exceed `size - 1` characters.
				
	Parameters:
				dst (OUT) -- The destination buffer where `src` is copied.
				src (IN) -- The source string to be copied into `dst`.
				size (IN) -- The total size of `dst`, including space for 
				              the null-terminator.

	Returns:	The length of the string that would have been copied if 
				`size` were unlimited. This is the length of `src`.

	Notes:		If `size` is zero, the function returns the length of `src` 
				without copying any characters. If `size` is greater than zero, 
				`dst` is always null-terminated, even if the entire `src` string 
				was not copied. Ensure `dst` has enough space to avoid buffer 
				overflow.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
