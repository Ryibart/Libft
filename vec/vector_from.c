/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_from.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 05:35:04 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_from|════════════════════════════════════════════════════════════*

	Purpose:	Copies a given memory block `src` into a new vector `dst`. This 
				function allows creating a vector from raw memory data, providing 
				an easy way to initialize a vector with existing data.
				
	Parameters:
				dst (OUT) -- Pointer to the destination vector to be created.
				src (IN) -- Pointer to the source memory block to copy.
				len (IN) -- Number of elements to copy into the vector.
				elem_size (IN) -- Size of each element in bytes.

	Returns:	VECTOR_SUCCESS (1) on success, or VECTOR_ERROR (-1) on failure.

	Notes:		The caller must ensure that `src` points to valid memory and that 
				`len` is within the bounds of the source memory block.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_from(t_vector *dst, void *src, size_t len, size_t elem_size)
{
	if (!dst || !src || len == 0 || elem_size == 0)
		return (VECTOR_ERROR);
	else if (vector_new(dst, len, elem_size) == VECTOR_ERROR)
		return (VECTOR_ERROR);
	ft_memcpy(dst->memory, src, len * elem_size);
	dst->len = len;
	return (VECTOR_SUCCESS);
}
