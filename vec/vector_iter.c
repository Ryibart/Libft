/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 05:28:23 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_iter|══════════════════════════════════════════════════════════════*

	Purpose:	Applies a function `f` to each element in the vector 
				`src`, allowing for operations such as modification or 
				processing of each element.
				
	Parameters:
				src (IN) -- Pointer to the vector to iterate over.
				f (IN) -- Function to apply to each element.

	Returns:	None (void).

	Notes:		The function `f` should not modify the vector's structure 
				or invalidate iterators.

*════════════════════════════════════════════════════════════════════════════*/

void	vector_iter(t_vector *src, void (*f) (void *))
{
	void	*ptr;
	size_t	i;

	if (!src || !src->memory || !f)
		return ;
	i = 0;
	while (i < src->len)
	{
		ptr = vector_get(src, i);
		f(ptr);
		i++;
	}
}
	