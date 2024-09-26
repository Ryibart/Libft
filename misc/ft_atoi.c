/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:18:16 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:53:34 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_atoi|═════════════════════════════════════════════════════════════════*
	
	Purpose:	Converts a string of numeric characters into an integer. The 
				function ignores leading whitespace, recognizes optional sign 
				characters (+ or -), and continues parsing until a non-digit 
				character is encountered.
				
	Parameters:
				str (IN) -- The null-terminated string to
							convert into an integer.

	Returns:	An integer value representing the numerical interpretation of 
				the input string.

	Note:		If the resulting number exceeds the range of a 32-bit signed 
				integer, the function mimics the overflow behavior of `atoi` 
				from the C standard library.
				If the input string represents a number outside this range, the
				function returns the closest possible value within the range.
				If an overflow in range of long occurs, it returns `-1` for
				positive overflow and `0` for negative overflow.

*════════════════════════════════════════════════════════════════════════════*/

#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	long	temp;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		temp = result;
		result = (result * 10) + (*str++ - '0');
		if (temp > result && sign == 1)
			return (-1);
		else if (temp > result && sign == -1)
			return (0);
	}
	return ((int)result * sign);
}
