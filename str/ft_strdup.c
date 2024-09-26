/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:39:50 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:55:29 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_strdup|═══════════════════════════════════════════════════════════════*

	Purpose:	Creates a duplicate of a given null-terminated string `s1`. 
				This function allocates memory for the duplicate and copies 
				the contents from the original string to the new one.
				
	Parameters:
				s1 (IN) -- The null-terminated string to be duplicated.

	Returns:	A pointer to a newly allocated duplicate of the string `s1`. 
				If memory allocation fails, the function returns `NULL`.

	Notes:		The caller is responsible for freeing the allocated memory 
				when it's no longer needed to avoid memory leaks.

*═══════════════════════════════════════════════════════════════════\════════*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	i = 0;
	while (s1[i] != '\0')
		i++;
	ret = malloc(i + 1);
	if (!ret)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
