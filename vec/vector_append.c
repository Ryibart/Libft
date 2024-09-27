/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 05:25:35 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_append|═══════════════════════════════════════════════════════════*

	Purpose:	Appends the contents of the source vector `src` to the 
				destination vector `dst`. This function increases the size 
				of `dst` and copies elements from `src` into it.
				
	Parameters:
				dst (IN/OUT) -- Pointer to the destination vector to which 
				elements will be appended.
				src (IN) -- Pointer to the source vector whose elements 
				are to be appended.

	Returns:	VECTOR_ERROR if either vector is NULL or if memory 
				operations fail. Returns VECTOR_SUCCESS on success.

	Notes:		Ensure `dst` has enough allocated memory to accommodate 
				the additional elements from `src`.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_append(t_vector *dst, t_vector *src)
{
	int		ret;
	size_t	alloc_size;

	if (!dst || !src || !src->memory)
		return (VECTOR_ERROR);
	else if (!dst->memory)
	{
		if (vector_new(dst, src->len, src->elem_size) == VECTOR_ERROR)
			return (VECTOR_ERROR);
	}
	alloc_size = dst->len * dst->elem_size + src->len * src->elem_size;
	if (dst->alloc_size < alloc_size)
	{
		if (dst->alloc_size * 2 < dst->len * alloc_size)
			ret = vector_resize(dst, dst->alloc_size * 2);
		else
			ret = vector_resize(dst, alloc_size);
		if (ret == VECTOR_ERROR)
			return (VECTOR_ERROR);
	}
	ft_memcpy(&dst->memory[dst->elem_size * dst->len], src->memory,
		src->len * src->elem_size);
	dst->len += src->len;
	return (VECTOR_SUCCESS);
}
