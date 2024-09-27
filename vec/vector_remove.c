/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 06:22:37 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_remove|══════════════════════════════════════════════════════════*

	Purpose:	Removes an element from the vector `src` at the specified 
				`index`. The function shifts all subsequent elements to fill the 
				gap created by the removal, ensuring continuity of the vector's 
				data.
				
	Parameters:
				src (IN/OUT) -- Pointer to the source vector from which to remove 
				an element.
				index (IN) -- Index of the element to remove.

	Returns:	VECTOR_SUCCESS (1) on success, or VECTOR_ERROR (-1) on failure.

	Notes:		The caller must ensure that `index` is within the bounds of the 
				vector to avoid undefined behavior.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_remove(t_vector *src, size_t index)
{
	if (!src || index >= src->len)
		return (VECTOR_ERROR);
	else if (index == src->len)
	{
		src->len--;
		return (VECTOR_SUCCESS);
	}
	ft_memmove(vector_get(src, index),
		&src->memory[src->elem_size * (index + 1)],
		(src->len - index) * src->elem_size);
	src->len--;
	return (VECTOR_SUCCESS);
}
