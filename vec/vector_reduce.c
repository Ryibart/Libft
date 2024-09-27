/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reduce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 06:10:47 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_reduce|════════════════════════════════════════════════════════════*

	Purpose:	Reduces the elements of the source vector `src` to a 
				single value by applying a reduction function `f`, 
				which combines each element with an accumulator.
				
	Parameters:
				dst (IN/OUT) -- Pointer to store the resulting reduced 
				value.
				src (IN) -- Pointer to the source vector to reduce.
				f (IN) -- Function to apply for reduction.

	Returns:	VECTOR_ERROR if any pointer is NULL. Returns 
				VECTOR_SUCCESS on success.

	Notes:		The initial value in `dst` must be set before calling 
				this function.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_reduce(void *dst, t_vector *src, void (*f) (void *, void *))
{
	void	*ptr;
	size_t	i;

	if (!dst || !src || !src->memory || !f)
		return (VECTOR_ERROR);
	i = 0;
	while (i < src->len)
	{
		ptr = vector_get(src, i);
		f(dst, ptr);
		i++;
	}
	return (VECTOR_SUCCESS);
}
