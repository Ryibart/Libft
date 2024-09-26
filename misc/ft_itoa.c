/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:03:58 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:55:06 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*══|ft_absolute_value|═══════════════════════════════════════════════════════*

	Purpose:	Returns the absolute value of an integer. This function 
            	handles edge cases like the minimum 32-bit signed integer 
            	value to avoid overflow.

	Parameters:
				n (IN) -- The integer whose absolute value is to be found.

	Returns:	The absolute value of the input integer.
*════════════════════════════════════════════════════════════════════════════*/

static int	ft_absolute_value(int n)
{
	if (n == -2147483648)
		return (-(n + 1) + 1);
	if (n < 0)
		return (-n);
	return (n);
}

/*══|ft_digit_count|══════════════════════════════════════════════════════════*

	Purpose:	Determines the number of digits in an integer, considering 
    			negative numbers as having an additional digit for the sign.

	Parameters:
				n (IN) -- The integer whose digit count is to be calculated.

	Returns:	The count of digits in the integer, including the sign 
				for negative numbers.
*════════════════════════════════════════════════════════════════════════════*/

static int	ft_digit_count(int n)
{
	int	count;
	int	temp;

	count = 1;
	temp = n;
	if (n < 0)
		count = 2;
	while (temp / 10 != 0)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

/*══|ft_itoa|═════════════════════════════════════════════════════════════════*

	Purpose:	Converts an integer into a null-terminated string 
        		representation. The function handles negative numbers 
            	and utilizes the `ft_absolute_value` function to ensure correct 
            	conversion without overflow.
				
	Parameters:
				n (IN) -- The integer to be converted to a string.

	Returns:	A dynamically allocated string representing the integer.
        		If memory allocation fails, returns NULL.
*════════════════════════════════════════════════════════════════════════════*/

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	abs_n;
	char			*str;

	len = ft_digit_count(n);
	abs_n = ft_absolute_value(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = (abs_n % 10) + '0';
		abs_n /= 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
