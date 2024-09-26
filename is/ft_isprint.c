/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:45:28 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:56:07 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_isprint|═══════════════════════════════════════════════════════════════*

	Purpose:	Checks whether a given ASCII character is printable. 
				Printable characters are those that can be displayed, 
				including letters, digits, symbols, and space, but not 
				control characters.
				
	Parameters:
				c (IN) -- The ASCII character to check.

	Returns:	Returns `1` (true) if `c` is a printable character, and `0` 
				(false) otherwise.

	Notes:		ASCII printable characters range from 32 (space) to 126 
				(tilde '~'). Characters outside this range are not considered 
				printable and typically include control characters.

*════════════════════════════════════════════════════════════════════════════*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
