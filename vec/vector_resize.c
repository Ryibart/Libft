/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 06:11:53 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_resize|════════════════════════════════════════════════════════════*

	Purpose:	Resizes the vector `src` to the specified target length. 
				If the new size is larger than the current size, additional 
				memory is allocated.
				
	Parameters:
				src (IN/OUT) -- Pointer to the vector to resize.
				target_len (IN) -- New desired length for the vector.

	Returns:	VECTOR_ERROR if `src` is NULL or if memory operations fail. 
				Returns VECTOR_SUCCESS on successful resizing.

	Notes:		Existing elements are preserved during the resize. 

*════════════════════════════════════════════════════════════════════════════*/

int	vector_resize(t_vector *src, size_t target_len)
{
	t_vector	dst;

	if (!src)
		return (VECTOR_ERROR);
	else if (!src->memory)
		return (vector_new(src, target_len, src->elem_size));
	else if (vector_new(&dst, target_len, src->elem_size) == VECTOR_ERROR)
		return (VECTOR_ERROR);
	ft_memcpy(dst.memory, src->memory, src->len * src->elem_size);
	dst.len = src->len;
	vector_free(src);
	*src = dst;
	return (VECTOR_SUCCESS);
}
