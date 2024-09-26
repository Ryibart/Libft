/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:18:37 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:55:52 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_lstsize|═══════════════════════════════════════════════════════════════*

	Purpose:	Returns the number of nodes in a linked list. This function 
				traverses the list, counting each node, and returns the total 
				count.
				
	Parameters:
				lst (IN) -- Pointer to the head of the list whose size 
				              is to be determined.

	Returns:	The total number of nodes in the list.

	Notes:		The function traverses the list from the given head to the 
				end, incrementing the count for each node. If `lst` is `NULL`, 
				the function returns `0`.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
