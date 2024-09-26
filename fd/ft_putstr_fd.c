/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:52:58 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:57:02 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_putstr_fd|═══════════════════════════════════════════════════════════*

	Purpose:	Writes a null-terminated string `s` to the specified file 
				descriptor `fd`. This function is commonly used to output 
				strings to various destinations such as files, consoles, 
				or sockets.
				
	Parameters:
				s (IN) -- The null-terminated string to be written.
				fd (IN) -- The file descriptor to which the string is written.
				This can be a standard file descriptor like `STDOUT_FILENO`, 
				`STDERR_FILENO`, or a custom descriptor for specific outputs.

	Returns:	None (void).

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}
