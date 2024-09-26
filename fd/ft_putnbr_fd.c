/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:52:38 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:56:58 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_putnbr_fd|═══════════════════════════════════════════════════════════*

	Purpose:	Writes an integer `n` to the specified file descriptor `fd`. 
				Handles negative numbers and the minimum 32-bit integer value. 
				The function recursively breaks down the number into individual 
				digits for writing.
				
	Parameters:
				n (IN) -- The integer to be written to the file descriptor.
				fd (IN) -- The file descriptor to which the integer
				is written. This can be a standard file descriptor like 
				`STDOUT_FILENO`, `STDERR_FILENO`, or a custom descriptor 
				for writing to files or sockets.

	Returns:	None (void).

	Notes:		If `n` is `-2147483648` (minimum 32-bit integer), the function 
				specially handles this case by directly writing the 
				string "-2147483648" to avoid overflow. In other cases, it 
				manages negative numbers by converting them to positive 
				before processing.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
