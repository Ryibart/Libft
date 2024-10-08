/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 16:10:17 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_insert|════════════════════════════════════════════════════════════*

	Purpose:	Inserts an element into the vector `dst` at the specified 
				index. The existing elements are shifted to accommodate 
				the new element.
				
	Parameters:
				dst (IN/OUT) -- Pointer to the destination vector where 
				the element will be inserted.
				elem (IN) -- Pointer to the element to insert.
				index (IN) -- Index at which to insert the new element.

	Returns:	VECTOR_ERROR if `dst` is NULL, if `index` is out of bounds, 
				or if memory operations fail. Returns VECTOR_SUCCESS on 
				success.

	Notes:		Ensure that `dst` has enough allocated memory to accommodate 
				the new element.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_insert(t_vector *dst, void *src, size_t index)
{
	if (!dst || !src || index > dst->len)
		return (VECTOR_ERROR);
	else if (index == dst->len)
		return (vector_push_last(dst, src));
	if (dst->elem_size * dst->len >= dst->alloc_size)
	{
		if (vector_resize(dst, (dst->alloc_size * 2) / dst->elem_size)
			== VECTOR_ERROR)
			return (VECTOR_ERROR);
	}
	ft_memmove(vector_get(dst, index + 1), vector_get(dst, index),
		(dst->len - index) * dst->elem_size);
	ft_memcpy(vector_get(dst, index), src, dst->elem_size);
	dst->len++;
	return (VECTOR_SUCCESS);
}
