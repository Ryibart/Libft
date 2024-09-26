/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:53:03 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:54:02 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_strnew|═══════════════════════════════════════════════════════════════*

	Purpose:	Allocates a new string with the given `size` and initializes 
				all its bytes to zero. 
				
	Parameters:
				size (IN) -- The size of the new string to be allocated.

	Returns:	A pointer to the newly allocated string with all bytes set 
				to zero. If memory allocation fails, the function returns `NULL`.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

static char	*ft_strnew(size_t size)
{
	char	*str;

	str = malloc(size + 1);
	if (!str)
		return (0);
	ft_bzero(str, size + 1);
	return (str);
}

/*══|ft_strmapi|═══════════════════════════════════════════════════════════════*

	Purpose:	Creates a new string by applying a given function `f` to 
				each character of a string `s`. The function passes the 
				character and its index to `f` to generate the new string.
				
	Parameters:
				s (IN) -- The original null-terminated string to process.
				f (IN) -- A function that takes an index and a character, 
				          returning the transformed character.

	Returns:	A pointer to the newly created string after applying the 
				function `f` to each character. Returns `NULL` if memory 
				allocation fails or if `s` or `f` is `NULL`.

	Notes:		If either `s` or `f` is `NULL`, the function returns `NULL` 
				without doing anything. The returned string must be freed 
				to avoid memory leaks.

*════════════════════════════════════════════════════════════════════════════*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	if (!s || !f)
		return (0);
	new = ft_strnew(ft_strlen(s));
	if (!new)
		return (0);
	i = -1;
	while (s[++i])
		new[i] = f(i, s[i]);
	return (new);
}
