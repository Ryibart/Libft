/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:56:38 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:18 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_memcmp|═══════════════════════════════════════════════════════════════*

	Purpose:	Compares the first `n` bytes of two memory blocks `s1` and 
				`s2`. Returns a positive value if `s1` is greater, a negative 
				value if `s2` is greater, or zero if they are equal within the 
				first `n` bytes.
				
	Parameters:
				s1 (IN) -- Pointer to the first memory block to compare.
				s2 (IN) -- Pointer to the second memory block to compare.
				n  (IN) -- Number of bytes to compare in the memory blocks.

	Returns:	A positive, negative, or zero value based on the comparison 
				of the memory blocks. If `n` is zero, returns zero.
				
*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	i = 0;
	u_s1 = (unsigned char *) s1;
	u_s2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (u_s1[i] != u_s2[i])
		{
			return (u_s1[i] - u_s2[i]);
		}
		i++;
	}
	return (0);
}
