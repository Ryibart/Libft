/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_prepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 05:36:08 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_prepend|══════════════════════════════════════════════════════════*

	Purpose:	Adds a new element to the beginning of the vector `dst`, shifting 
				all existing elements to the right. This function allows easy 
				insertion of elements at the start of the vector.
				
	Parameters:
				dst (IN/OUT) -- Pointer to the destination vector to which the 
				element will be added.
				elem (IN) -- Pointer to the element to be prepended to the vector.

	Returns:	VECTOR_SUCCESS (1) on success, or VECTOR_ERROR (-1) on failure.

	Notes:		If the vector reaches its capacity, it automatically resizes to 
				accommodate the new element. The caller must ensure that `elem` 
				points to valid memory with a size matching `dst->elem_size`.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_prepend(t_vector *dst, t_vector *src)
{
	t_vector	tmp;
	size_t		alloc_size;

	if (!dst || !src)
		return (VECTOR_ERROR);
	else if (!dst->memory)
	{
		if (vector_new(dst, 1, dst->elem_size) == VECTOR_ERROR)
			return (VECTOR_ERROR);
	}
	alloc_size = dst->len * dst->elem_size + src->len * src->elem_size;
	if (vector_new(&tmp, alloc_size / dst->elem_size, dst->elem_size)
		== VECTOR_ERROR)
		return (VECTOR_ERROR);
	vector_copy(&tmp, src);
	tmp.len = src->len + dst->len;
	ft_memcpy(&tmp.memory[dst->elem_size * dst->len], dst->memory,
		dst->len * dst->elem_size);
	vector_free(dst);
	*dst = tmp;
	return (VECTOR_SUCCESS);
}
	