/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:45:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/07 13:43:42 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

/*══|vector_sort|══════════════════════════════════════════════════════════════*

	Purpose:	Sorts the elements of the vector `src` using a provided 
				comparison function `f`. The sorting algorithm used is 
				a recursive quicksort.
				
	Parameters:
				src (IN/OUT) -- Pointer to the vector to sort.
				f (IN) -- Comparison function that defines the sorting order.

	Returns:	None (void).

	Notes:		Ensure that the vector is not empty before sorting, as 
				an empty vector will have no effect.

*════════════════════════════════════════════════════════════════════════════*/

static void	memswap_bits(unsigned char *a, unsigned char *b)
{
	if (a == b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

static void	memswap_bytes(unsigned char *a, unsigned char *b, size_t bytes)
{
	size_t			i;
	unsigned char	tmp;

	i = 0;
	while (i < bytes)
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
		i++;
	}
}

static void	memswap(void *a, void *b, size_t bytes)
{
	if (!a || !b || bytes == 0)
		return ;
	if (bytes == 1)
		memswap_bits((unsigned char *)a, (unsigned char *)b);
	else
		memswap_bytes(a, b, bytes);
}

static void	vector_sort_recurse(t_vector *src, long int low, long int high,
	int (*f) (void *, void *))
{
	long int	pivot;
	long int	i;
	long int	j;

	if (low >= high)
		return ;
	pivot = low;
	i = low;
	j = high;
	while (i < j)
	{
		while (i <= high && f(vector_get(src, i), vector_get(src, pivot)) <= 0)
			i++;
		while (j >= low && f(vector_get(src, j), vector_get(src, pivot)) > 0)
			j--;
		if (i < j)
			memswap(vector_get(src, i), vector_get(src, j), src->elem_size);
	}
	memswap(vector_get(src, pivot), vector_get(src, j), src->elem_size);
	vector_sort_recurse(src, low, j - 1, f);
	vector_sort_recurse(src, j + 1, high, f);
}

void	vector_sort(t_vector *src, int (*f) (void *, void *))
{
	if (!src || !src->memory || !f)
		return ;
	vector_sort_recurse(src, 0, src->len - 1, f);
}
