/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 06:18:00 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_push|════════════════════════════════════════════════════════════*

	Purpose:	Adds an element from the source vector `src` to the end of the 
				destination vector `dst`. This function increases the length of 
				`dst` and resizes it if necessary to accommodate the new element.
				
	Parameters:
				dst (IN/OUT) -- Pointer to the destination vector to which the 
				element from `src` will be added.
				src (IN) -- Pointer to the source vector containing the element to 
				push.

	Returns:	VECTOR_SUCCESS (1) on success, or VECTOR_ERROR (-1) on failure.

	Notes:		If `dst` has no allocated memory, it initializes `dst` with an 
				initial size of 1. If the destination vector is full, it 
				resizes it by doubling its allocated size. The caller must ensure 
				that `src` points to a valid element with a size matching 
				`dst->elem_size`.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_push(t_vector *dst, void *src)
{
	if (!dst || !src)
		return (VECTOR_ERROR);
	else if (!dst->memory)
		vector_new(dst, 1, dst->elem_size);
	if (dst->elem_size * dst->len >= dst->alloc_size)
	{
		if (vector_resize(dst, dst->alloc_size * 2) == VECTOR_ERROR)
			return (VECTOR_ERROR);
	}
	ft_memcpy(&dst->memory[dst->elem_size * dst->len], src, dst->elem_size);
	dst->len++;
	return (VECTOR_SUCCESS);
}
