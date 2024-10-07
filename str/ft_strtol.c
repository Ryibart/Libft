/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:47:27 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/07 14:06:31 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_base(const char *str, int base)
{
	if (base == 0)
	{
		if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
			return (16);
		if (*str == '0')
			return (8);
		return (10);
	}
	return (base);
}

static int		ft_get_digit(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (ft_isalpha(c))
		return (ft_tolower(c) - 'a' + 10);
	return (-1);
}

static int	process_digit(const char **str, int base, long *result, int *valid)
{
	int digit;
	
	while ((digit = ft_get_digit(**str)) >= 0 && digit < base)
	{
		if (*result > (LONG_MAX - digit) / base)
		{
			*valid = 0;
			return (0);
		}
		*result = *result * base + digit;
		(*str)++;
	}
	return (1);
}

long	ft_strtol(const char *str, char **endptr, int base, int *valid)
{
	long	result;
	int		sign;

	*valid = 1;
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	base = ft_get_base(str, base);
	if (base == 16 && *str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str += 2;
	result = 0;
	if (process_digit(&str, base, &result, valid) < 0)
		return (0);
	if (endptr)
		*endptr = (char *)str;
	return (result * sign);
}
