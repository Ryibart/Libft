/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:08:24 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:55 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_strlcat|═══════════════════════════════════════════════════════════════*

	Purpose:	Appends the null-terminated string `src` to the end of the 
				null-terminated string `dst` while ensuring the resulting 
				string does not exceed the specified `size`. This function 
				appends as many characters from `src` as possible to `dst`, 
				and then null-terminates the result.
				
	Parameters:
				dst (IN/OUT) -- Destination string to which `src` is appended. 
				              It must have enough space for the final result.
				src (IN) -- The source string to be appended to `dst`.
				size (IN) -- The total size of `dst` including null-terminator.

	Returns:	The length of the string that would have been created if 
				there were no size limitations. If `size` is zero, returns 
				the length of `src`. If `dst`'s initial length is greater 
				than or equal to `size`, returns the length of `src` plus `size`.

	Notes:		Ensure that `dst` has enough space to avoid buffer overflow. 
				If `dst` is already larger than `size`, the function only
				returns the combined length but does not modify `dst`.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			dst_len;
	size_t			src_len;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] != '\0')
		i++;
	dst_len = i;
	src_len = ft_strlen(src);
	while (*src != '\0' && i < size - 1)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	if (dst_len >= size)
		return (src_len + size);
	else
		return (src_len + dst_len);
}
