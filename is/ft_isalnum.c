/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:47:35 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:56:00 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_isalnum|═══════════════════════════════════════════════════════════════*

	Purpose:	Checks whether a given ASCII character is alphanumeric; 
				a letter (uppercase or lowercase) or a digit (0-9).
				
	Parameters:
				c (IN) -- The ASCII character to check.

	Returns:	Returns `1` (true) if the character is alphanumeric, and `0` 
				(false) otherwise.

*════════════════════════════════════════════════════════════════════════════*/
int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
