/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 16:10:41 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_map|══════════════════════════════════════════════════════════════*

	Purpose:	Transforms the elements of the source vector `src` using 
				a mapping function `f` and stores the results in the 
				destination vector `dst`.
				
	Parameters:
				dst (IN/OUT) -- Pointer to the destination vector to hold 
				the mapped results.
				src (IN) -- Pointer to the source vector to map from.
				f (IN) -- Function to apply to each element.

	Returns:	VECTOR_ERROR if either vector is NULL or if memory 
				operations fail. Returns VECTOR_SUCCESS on success.

	Notes:		Ensure `dst` is properly initialized to hold the output 
				elements.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_map(t_vector *dst, t_vector *src, void (*f) (void *))
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
		f(res);
		vector_push_last(dst, res);
		i++;
	}
	free(res);
	return (VECTOR_SUCCESS);
}
