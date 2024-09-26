/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:30:30 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:56:03 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_isascii|═══════════════════════════════════════════════════════════════*

	Purpose:	Checks whether a given integer represents a valid ASCII 
				character. ASCII characters range from 0 to 127.
				
	Parameters:
				c (IN) -- The integer to check.

	Returns:	Returns `1` (true) if the integer `c` is a valid ASCII 
				character, and `0` (false) otherwise.

*════════════════════════════════════════════════════════════════════════════*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
