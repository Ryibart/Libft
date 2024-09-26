/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:20:03 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:56:01 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_isalpha|═══════════════════════════════════════════════════════════════*

	Purpose:	Checks whether a given ASCII character is an alphabetic letter. 
				The function returns true if the character is an uppercase 
				or lowercase letter (A-Z or a-z), and false otherwise.
				
	Parameters:
				c (IN) -- The ASCII character to check.

	Returns:	Returns `1` (true) if the character is an alphabetic letter, 
				and `0` (false) otherwise.

*════════════════════════════════════════════════════════════════════════════*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
