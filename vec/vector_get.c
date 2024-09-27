/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 05:35:35 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_get|═════════════════════════════════════════════════════════════*

	Purpose:	Retrieves an element from the vector `src` at the specified 
				`index`. This function provides access to elements stored within 
				the vector.
				
	Parameters:
				src (IN) -- Pointer to the source vector to access.
				index (IN) -- Index of the element to retrieve.

	Returns:	A pointer to the element at the specified index, or NULL if the 
				index is out of bounds.

	Notes:		The caller must ensure that `src` is valid and the `index` is 
				within the bounds of the vector's length to avoid undefined 
				behavior.

*════════════════════════════════════════════════════════════════════════════*/

void	*vector_get(t_vector *src, size_t index)
{
	unsigned char *ptr;
	
	if (index >= src->len || !src || !src->memory)
		return (NULL);
	ptr = &src->memory[src->elem_size * index];
	return (ptr);
}
		