/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 05:26:10 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_clear|═════════════════════════════════════════════════════════════*

	Purpose:	Clears the contents of the vector `src` by setting its 
				length to zero, effectively removing all elements.
				
	Parameters:
				src (IN/OUT) -- Pointer to the vector to be cleared.

	Returns:	VECTOR_ERROR if `src` is NULL. Returns VECTOR_SUCCESS 
				on successful clearing.

	Notes:		The memory allocated for elements remains intact; use 
				`vector_free` to release memory if necessary.

*════════════════════════════════════════════════════════════════════════════*/

int	vector_clear(t_vector *src)
{
	if (!src)
		return (VECTOR_ERROR);
	src->len = 0;
	return (VECTOR_SUCCESS);
}
