/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 16:09:58 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_filter|══════════════════════════════════════════════════════════*

	Purpose:	Creates a new vector `dst` containing elements from `src` that 
				satisfy the predicate function `f`. The function iterates over 
				each element in `src` and applies `f` to determine inclusion in 
				the new vector.
				
	Parameters:
				dst (OUT) -- Pointer to the destination vector to be filled.
				src (IN) -- Pointer to the source vector from which to filter.
				f (IN) -- Predicate function to test each element. Must return 
				true for elements to include.

	Returns:	VECTOR_SUCCESS (1) on success, or VECTOR_ERROR (-1) on failure.

	Notes:		The destination vector `dst` must be initialized prior to 
				calling this function. The predicate function `f` should 
				handle its own input validation.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_filter(t_vector *dst, t_vector *src, bool (*f) (void *))
{
	void	*ptr;
	void	*res;
	size_t	i;

	if (!dst || !src || !src->memory || !f)
		return (VECTOR_ERROR);
	else if (!dst->memory)
	{
		if (vector_new(dst, src->len, src->elem_size) == VECTOR_ERROR)
			return (VECTOR_ERROR);
	}
	res = malloc(src->elem_size);
	if (!res)
		return (VECTOR_ERROR);
	i = 0;
	while (i < src->len)
	{
		ptr = vector_get(src, i);
		ft_memcpy(res, ptr, dst->elem_size);
		if (f(res) == true)
			vector_push_last(dst, res);
		i++;
	}
	free(res);
	return (VECTOR_SUCCESS);
}
