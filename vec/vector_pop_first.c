/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 15:50:15 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_pop_first|════════════════════════════════════════════════════════*

	Purpose:	Removes the first element from the vector `src` and stores 
				it in `dst`. This function decreases the size of the vector 
				by one.
				
	Parameters:
				dst (OUT) -- Pointer to the location where the removed 
				element will be stored.
				src (IN/OUT) -- Pointer to the vector from which to remove 
				the first element.

	Returns:	VECTOR_ERROR if either pointer is NULL. Returns 
				VECTOR_SUCCESS if an element is successfully popped.

	Notes:		If the vector is empty, the function will not modify 
				`dst`, and the return value indicates success.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_pop_first(void *dst, t_vector *src)
{
	if (!dst || !src)
		return (VECTOR_ERROR);
	else if (!src->memory || src->len == 0)
		return (VECTOR_OK);
	ft_memcpy(dst, src->memory, src->elem_size);
	ft_memmove(src->memory, &src->memory[src->elem_size],
		(src->len - 1) * src->elem_size);
	src->len--;
	return (VECTOR_SUCCESS);
}
