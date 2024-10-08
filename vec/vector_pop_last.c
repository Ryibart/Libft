/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 15:42:26 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_pop_last|═════════════════════════════════════════════════════════*

	Purpose:	Removes the last element from the vector `src` and stores 
				it in `dst`. This function decreases the size of the vector 
				by one.
				
	Parameters:
				dst (OUT) -- Pointer to the location where the removed 
				element will be stored.
				src (IN/OUT) -- Pointer to the vector from which to remove 
				the last element.

	Returns:	VECTOR_ERROR if either pointer is NULL. Returns 
				VECTOR_SUCCESS if an element is successfully popped.

	Notes:		If the vector is empty, the function will not modify 
				`dst`, and the return value indicates success.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_pop_last(void *dst, t_vector *src)
{
	if (!dst || !src)
		return (VECTOR_ERROR);
	else if (!src->memory || src->len == 0)
		return (VECTOR_OK);
	src->len--;
	ft_memcpy(dst, &src->memory[src->elem_size * src->len], src->elem_size);
	return (VECTOR_SUCCESS);
}
