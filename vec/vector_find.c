/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 05:28:06 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_find|══════════════════════════════════════════════════════════════*

	Purpose:	Finds an element in the vector `src` that satisfies a 
				predicate function `f`. Returns a pointer to the first 
				matching element.
				
	Parameters:
				src (IN) -- Pointer to the vector to search.
				f (IN) -- Predicate function that determines if an element 
				matches.

	Returns:	A pointer to the first matching element, or NULL if no 
				match is found or if `src` is NULL.

	Notes:		The predicate function must not modify the elements of 
				the vector.

*════════════════════════════════════════════════════════════════════════════*/

void	*vector_find(t_vector *src, bool (*f) (void *))
{
	void	*ptr;
	size_t	i;

	if (!src || !src->memory || !f)
		return (NULL);
	i = 0;
	while (i < src->len)
	{
		ptr = vector_get(src, i);
		if (f(ptr) == true)
			return (ptr);
		i++;
	}
	return (NULL);
}
