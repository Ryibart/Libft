/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:49:09 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/18 14:46:44 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int long nbr)
{
	char	*str;
	int		len;

	if (nbr > INT_MAX || nbr < INT_MIN)
		return (-1);
	str = ft_itoa(nbr);
	if (!str)
	{
		free(str);
		return (-1);
	}
	len = print_str(str);
	if (len == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}
