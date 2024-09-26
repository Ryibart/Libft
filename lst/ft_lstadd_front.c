/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:16:09 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:55:39 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_lstadd_front|═════════════════════════════════════════════════════════*

	Purpose:	Adds a new node to the front of a linked list. This function 
				inserts the new node before the current head, making it the 
				new head of the list.
				
	Parameters:
				lst (IN/OUT) -- Pointer to the current head of the list. After 
				                the operation, it points to the new head.
				new (IN) -- The new node to be added to the front of the list.

	Returns:	None (void).

	Notes:		The caller should ensure `lst` and `new` are valid pointers. 
				If `lst` is `NULL`, this function does nothing. After the 
				operation, `new->next` points to the former head of the list.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
