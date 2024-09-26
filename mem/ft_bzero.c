/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:50:25 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:08 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_bzero|═══════════════════════════════════════════════════════════════*

	Purpose:	Sets the first `n` bytes of a memory block `s` to zero. This 
				function is typically used to clear or initialize memory 
				buffers to ensure they contain no leftover data.
				
	Parameters:
				s (IN/OUT) -- Pointer to the memory block to zero out.
				n (IN) -- Number of bytes to set to zero in the memory block.

	Returns:	None (void).

	Notes:		If `n` is zero, the function does nothing. The caller must 
				ensure `s` points to valid memory with at least `n` bytes to 
				avoid undefined behavior.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*u_s;

	i = 0;
	u_s = (unsigned char *)s;
	while (i < n)
	{
		u_s[i] = 0;
		i++;
	}
}
