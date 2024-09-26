/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:52:22 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:56:54 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_putendl_fd|═══════════════════════════════════════════════════════════*

	Purpose:	Writes the string `s` followed by a newline character to the 
				specified file descriptor `fd`. This function can be used to 
				write a line of text to various outputs such as a file, 
				console, or socket.
				
	Parameters:
				s (IN) -- The null-terminated string to be written.
				fd (IN) -- The file descriptor to which the string and 
				newline are written. This can be a standard 
				file descriptor like `STDOUT_FILENO` or `STDERR_FILENO`, 
				or a custom descriptor for other outputs.

	Returns:	None (void).

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
