/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:05:43 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:53 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_strjoin|═══════════════════════════════════════════════════════════════*

	Purpose:	Joins two null-terminated strings `s1` and `s2` into a single 
				string. The function allocates memory for the resulting string 
				and concatenates the contents of `s1` and `s2`.
				
	Parameters:
				s1 (IN) -- The first null-terminated string to be joined.
				s2 (IN) -- The second null-terminated string to be joined.

	Returns:	A pointer to the newly allocated string that contains the 
				concatenated contents of `s1` and `s2`. Returns `NULL` if 
				memory allocation fails or if `s1` or `s2` is `NULL`.

	Notes:		The caller is responsible for freeing the returned string 
				to avoid memory leaks. Ensure both `s1` and `s2` are valid 
				null-terminated strings before calling this function.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (0);
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}
