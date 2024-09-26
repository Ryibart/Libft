/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:51:36 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:51 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_striteri|═════════════════════════════════════════════════════════════*

	Purpose:	Applies a given function `f` to each character of a string `s`, 
				where the function receives the current index and a pointer 
				to the character. This function is typically used to apply 
				an operation to every character in a string with index-specific 
				information.
				
	Parameters:
				s (IN/OUT) -- The null-terminated string on which the function 
				              `f` is applied. This parameter can be modified 
				              depending on what `f` does.
				f (IN) -- A function that takes an index and a pointer to 
				          a character. It is applied to each character in `s`.

	Returns:	None (void).

	Notes:		The function does nothing if `s` or `f` is `NULL`. The caller 
				should ensure the string `s` is not `NULL` and that `f` is a 
				valid function pointer. This function allows for flexible 
				operations on a string based on the index.

*════════════════════════════════════════════════════════════════════════════*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
