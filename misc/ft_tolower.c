/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:46:37 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:43 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_tolower|═══════════════════════════════════════════════════════════════*

	Purpose:	Converts an uppercase ASCII character to its lowercase 
				equivalent. If the character is not an uppercase letter, 
				it is returned unchanged.
				
	Parameters:
				c (IN) -- The ASCII character to be converted.

	Returns:	The lowercase equivalent if the character is an uppercase 
				letter (from 'A' to 'Z'). Otherwise, the function returns 
				the original character.
				
*════════════════════════════════════════════════════════════════════════════*/

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
