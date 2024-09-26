/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:16 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/18 14:46:52 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uint(unsigned int nbr)
{
	char	*str;
	int		len;

	if (nbr == 0)
		return (write(1, "0", 1));
	str = util_uitoa(nbr);
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
