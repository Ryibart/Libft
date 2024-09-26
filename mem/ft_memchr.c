/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:29:39 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:16 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_memchr|═══════════════════════════════════════════════════════════════*

	Purpose:	Searches for the first occurrence of a specified byte 
            	value in a memory block. Returns a pointer to the byte's 
        		position or `NULL` if not found within the first `n` bytes.
				
	Parameters:
				s (IN) -- Pointer to the memory block to scan.
            	c (IN) -- Byte value to search for (cast to `unsigned char`).
            	n (IN) -- Number of bytes to scan in `s`.

	Returns:	A pointer to the first occurrence of `c` within the 
    			first `n` bytes of `s`. Returns `NULL` if not found or if `n` 
        		is zero.
*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*u_s;
	unsigned char		u_c;

	i = 0;
	u_s = (unsigned char *)s;
	u_c = (unsigned char)c;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (u_s[i] == u_c)
			return ((void *)u_s + i);
		i++;
	}
	return (0);
}
