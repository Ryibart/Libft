/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:38:24 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:13 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_calloc|═══════════════════════════════════════════════════════════════*

	Purpose:	Allocates memory for an array of `count` elements, each of 
				`size` bytes, and initializes the memory to zero. This function 
				ensures that the allocated memory is clean and ready for use.
				
	Parameters:
				count (IN) -- The number of elements to allocate.
				size (IN) -- The size of each element in bytes.

	Returns:	A pointer to the allocated memory. If memory allocation fails, 
				or if the requested allocation would exceed system limits, 
				the function returns `NULL`.

	Notes:		If `count * size` exceeds `SIZE_MAX`, indicating potential 
				integer overflow, the function returns `NULL`. The caller 
				is responsible for freeing the allocated memory when no 
				longer needed to avoid memory leaks.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count != 0 && size != 0 && count > (SIZE_MAX / size))
		return (0);
	ret = malloc(count * size);
	if (!ret)
		return (0);
	ft_bzero(ret, count * size);
	return (ret);
}
