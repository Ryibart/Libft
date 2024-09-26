/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:52:53 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:56:51 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_putchar_fd|═══════════════════════════════════════════════════════════*

	Purpose:	Writes the character `c` to the file descriptor `fd`. This 
				function is commonly used to output characters to a specific 
				file, device, or socket.
				
	Parameters:
				c (IN) -- The character to be written to the file descriptor.
				fd (IN) -- The file descriptor to which the character
				is written. This can be a standard file descriptor
				(like STDOUT_FILENO or STDERR_FILENO) or a custom 
				descriptor for a specific file or socket.

	Returns:	None (void).

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
