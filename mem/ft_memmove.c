/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:06:31 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:29 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_memmove|═══════════════════════════════════════════════════════════════*

	Purpose:	Copies `n` bytes from the memory block `s2` to the memory 
				block `s1`. This function is similar to `ft_memcpy`, but 
				it handles overlapping memory regions safely. If `s1` and 
				`s2` overlap, it ensures data is not corrupted by copying 
				in reverse order when necessary.
				
	Parameters:
				s1 (OUT) -- Pointer to the destination memory block where 
							bytes will be copied.
				s2 (IN) -- Pointer to the source memory block from which 
							bytes will be copied.
				n  (IN) -- Number of bytes to copy from `s2` to `s1`.

	Returns:	A pointer to the destination memory block `s1`.

	Notes:		If both `s1` and `s2` are `NULL`, the function returns `NULL`.
				The caller should ensure `s1` has sufficient space for `n` bytes.
				The function is safe to use with overlapping memory regions, 
				as it can copy from the end to the beginning if `s1` and `s2` 
				overlap in a way that would otherwise cause data corruption.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*src;

	i = 0;
	dst = (unsigned char *)s1;
	src = (const unsigned char *)s2;
	if (!dst && !src)
		return (0);
	else if ((dst > src) && (dst < src + n) && (src < dst + n))
	{
		i = n;
		while (i--)
			dst[i] = src[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (s1);
}
