/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:41:21 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:45 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_toupper|═══════════════════════════════════════════════════════════════*

	Purpose:	Converts a lowercase ASCII character to its uppercase 
				equivalent. If the character is not a lowercase letter, 
				it is returned unchanged.
				
	Parameters:
				c (IN) -- The ASCII character to be converted.

	Returns:	The uppercase equivalent if the character is a lowercase 
				letter (from 'a' to 'z'). Otherwise, the function returns 
				the original character.

*════════════════════════════════════════════════════════════════════════════*/

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
