/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 05:35:46 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_new|═════════════════════════════════════════════════════════════*

	Purpose:	Creates a new vector `src` with the specified initial length and 
				element size. This function allocates memory for the vector and 
				sets its initial parameters.
				
	Parameters:
				src (OUT) -- Pointer to the vector to be initialized.
				init_len (IN) -- Initial length of the vector.
				elem_size (IN) -- Size of each element in bytes.

	Returns:	VECTOR_SUCCESS (1) on success, or VECTOR_ERROR (-1) on failure.

	Notes:		The function allocates memory for the vector's storage, and the 
				caller is responsible for freeing this memory using `vector_free`.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_new(t_vector *src, size_t init_len, size_t elem_size)
{
	if (!src || elem_size == 0)
		return (VECTOR_ERROR);
	src->alloc_size = init_len * elem_size;
	src->len = 0;
	src->elem_size = elem_size;
	if (init_len == 0)
		src->memory = NULL;
	else
	{
		src->memory = malloc(src->alloc_size);
		if (!src->memory)
			return (VECTOR_ERROR);
	}
	return (VECTOR_SUCCESS);
}
