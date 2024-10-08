/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_typecast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:05:03 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/07 16:13:04 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

void	*cast_to_int(void *element)
{
	return ((void *)(intptr_t)(*(int *)element));
}

void	*cast_to_long(void *element)
{
	return ((void *)(intptr_t)(*(long *)element));
}

void	*cast_to_char(void *element)
{
	return ((void *)(intptr_t)(*(char *)element));
}

void	*cast_to_size_t(void *element)
{
	return ((void *)(uintptr_t)(*(size_t *)element));
}

void	*vector_typecast(t_vector *src, size_t index, t_typecast_fn cast_fn)
{
	if (src == NULL || src->memory == NULL)
		return (NULL);
	return (cast_fn(vector_get(src, index)));
}
