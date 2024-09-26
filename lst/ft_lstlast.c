/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:21:02 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:55:46 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_lstlast|═══════════════════════════════════════════════════════════════*

	Purpose:	Returns a pointer to the last node in a linked list. This 
				function traverses the list from the given head until it 
				reaches the node with a `NULL` `next` pointer.
				
	Parameters:
				lst (IN) -- Pointer to the head of the linked list.

	Returns:	A pointer to the last node in the list. If the list is empty 
				(`lst` is `NULL`), the function returns `NULL`.

	Notes:		The function traverses the list to find the last node. If 
				`lst` is already `NULL`, indicating an empty list, it 
				immediately returns `NULL`.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
