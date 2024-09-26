/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:59:19 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:31 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_memset|═══════════════════════════════════════════════════════════════*

	Purpose:	Fills the first `n` bytes of the memory block `b` with 
				the byte `c`. This function is commonly used to initialize 
				or reset memory buffers with a specific value.
				
	Parameters:
				b (IN/OUT) -- Pointer to the memory block to fill.
				c (IN) -- The byte value used to fill the memory block. 
				          This is converted to `unsigned char`.
				n (IN) -- The number of bytes to fill in the memory block.

	Returns:	A pointer to the memory block `b`.

	Notes:		If `n` is zero, the function does nothing and simply 
				returns `b`. The caller should ensure that `b` has at 
				least `n` bytes allocated to avoid undefined behavior.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*u_b;
	unsigned char	u_c;

	i = 0;
	u_b = (unsigned char *)b;
	u_c = (unsigned char)c;
	while (i < n)
	{
		u_b[i] = u_c;
		i++;
	}
	return (b);
}
