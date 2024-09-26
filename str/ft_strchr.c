/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:51:02 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:47 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_strchr|═══════════════════════════════════════════════════════════════*

	Purpose:	Searches for the first occurrence of a character `c` in a 
				null-terminated string `s`. If the character is found, the 
				function returns a pointer to its position in the string. 
				If the character is not found, it returns `NULL`.
				
	Parameters:
				s (IN) -- The null-terminated string to search through.
				c (IN) -- The character to search for.

	Returns:	A pointer to the first occurrence of the character `c` in the 
				string `s`. Returns `NULL` if the character is not found 
				in the string.

	Notes:		If `c` is `0`, the function returns a pointer
				to the null-terminator at the end of the string.

*════════════════════════════════════════════════════════════════════════════*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	u_c;

	i = 0;
	u_c = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == u_c)
			return ((char *)&s[i]);
		i++;
	}
	if (u_c == '\0')
		return ((char *)&s[i]);
	return (0);
}
