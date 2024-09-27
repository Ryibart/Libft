/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 05:26:55 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_copy|══════════════════════════════════════════════════════════════*

	Purpose:	Copies the contents of the source vector `src` into the 
				destination vector `dst`, including its elements and 
				length.
				
	Parameters:
				dst (IN/OUT) -- Pointer to the destination vector to be 
				copied into.
				src (IN) -- Pointer to the source vector to copy from.

	Returns:	VECTOR_ERROR if either vector is NULL. Returns 
				VECTOR_SUCCESS on successful copy.

	Notes:		The destination vector must have enough allocated memory 
				to hold the copied elements.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_copy(t_vector *dst, t_vector *src)
{
	size_t	copy_size;

	if (!dst || !src || src->elem_size == 0)
		return (VECTOR_ERROR);
	else if (!dst->memory)
	{
		if (vector_new(dst, src->len, dst->elem_size) == VECTOR_ERROR)
			return (VECTOR_ERROR);
	}
	if (src->len * src->elem_size < dst->alloc_size)
		copy_size = src->len * src->elem_size;
	else
		copy_size = dst->alloc_size;
	ft_memcpy(dst->memory, src->memory, copy_size);
	dst->len = copy_size / dst->elem_size;
	return (VECTOR_SUCCESS);
}
