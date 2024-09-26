/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:31:09 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:56:05 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_isdigit|═══════════════════════════════════════════════════════════════*

	Purpose:	Checks whether a given ASCII character represents a digit 
				(from '0' to '9'). Returns true if the character is a digit, 
				and false otherwise.
				
	Parameters:
				c (IN) -- The ASCII character to check.

	Returns:	Returns `1` (true) if `c` is a digit, and `0` (false) otherwise.

*════════════════════════════════════════════════════════════════════════════*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
