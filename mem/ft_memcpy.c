/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:12:58 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:27 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_memcpy|═══════════════════════════════════════════════════════════════*

	Purpose:	Copies `n` bytes from the memory block `s2` to the memory 
				block `s1`. If `s1` and `s2` overlap, the behavior is undefined.
				This function is typically used for copying data between 
				memory regions where overlap is not expected or desired.
				
	Parameters:
				s1 (OUT) -- Pointer to the destination memory block where 
							bytes will be copied.
				s2 (IN) -- Pointer to the source memory block from which 
							bytes will be copied.
				n  (IN) -- Number of bytes to copy from `s2` to `s1`.

	Returns:	A pointer to the destination memory block `s1`.

	Notes:		If both `s1` and `s2` are `NULL`, the function returns `NULL`.
				The caller should ensure that `s1` has enough space to hold 
				the `n` bytes being copied from `s2`.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*src;

	i = 0;
	dst = (unsigned char *)s1;
	src = (const unsigned char *)s2;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
