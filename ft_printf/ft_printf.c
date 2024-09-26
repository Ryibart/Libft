/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:13:56 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:56:43 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══| ft_printf |══════════════════════════════════════════════════════════════*
	
	Purpose:	Prints data to the standard output according
				to the given format string and/or arguments
				according to the format specifiers.
				
	Parameters:
				str (IN) -- A string containing the format string and optional
							arguments.
				... (IN) -- A variable number of arguments to be formatted
							and printed according to the format string.

	Returns:	
				The number of characters printed, or `-1` if an error occurs.

	Helpers:	
				`format_flags` -- Formats and prints the argument according to
								  the format specifier by calling the appropriate
								  function.
				`print_and_parse` -- Iterates through the format string and
									prints the characters and arguments.

*════════════════════════════════════════════════════════════════════════════*/

#include "ft_printf.h"

static int	format_flags(va_list *args, const char format)
{
	int	print_count;

	print_count = 0;
	if (format == 'c')
		print_count += print_char(va_arg(*args, int));
	else if (format == 's')
		print_count += print_str(va_arg(*args, char *));
	else if (format == 'p')
		print_count += print_ptr(va_arg(*args, void *), format);
	else if (format == 'd' || format == 'i')
		print_count += print_nbr(va_arg(*args, int));
	else if (format == 'u')
		print_count += print_uint(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_count += print_hex(va_arg(*args, unsigned int), format);
	else if (format == '%')
	{
		print_count += 1;
		if (print_char('%') == -1)
			return (-1);
	}
	return (print_count);
}

static int	print_and_parse(const char *str, va_list *args,
							unsigned int print_count)
{
	int				temp;

	print_count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == '\0')
				break ;
			if (ft_strchr("cspdiuxX%", *str))
				temp = format_flags(args, *str);
			else
				return (-1);
		}
		else
			temp = print_char(*str);
		if (temp == -1)
			return (-1);
		print_count += temp;
		str++;
	}
	return (print_count);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	print_count;

	print_count = 0;
	va_start(args, str);
	print_count = print_and_parse(str, &args, print_count);
	va_end(args);
	return (print_count);
}
