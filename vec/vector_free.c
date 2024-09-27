/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 05:30:34 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_free|══════════════════════════════════════════════════════════════*

	Purpose:	Frees the memory allocated for the vector `src`, including 
				the elements stored in it. After calling this function, 
				the vector should not be used unless reinitialized.
				
	Parameters:
				src (IN/OUT) -- Pointer to the vector to free.

	Returns:	None (void).

	Notes:		Ensure that all elements are properly managed before 
				freeing the vector to avoid memory leaks.

*════════════════════════════════════════════════════════════════════════════*/

void	vector_free(t_vector *src)
{
	if (!src || src->alloc_size == 0)
		return ;
	free(src->memory);
	src->memory = NULL;
	src->elem_size = 0;
	src->alloc_size = 0;
	src->len = 0;
}
