/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:24:59 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:55:36 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_lstadd_back|═════════════════════════════════════════════════════════*

	Purpose:	Adds a new node to the end of a linked list. This function 
				inserts the new node at the end of the list, updating the 
				`next` pointer of the previous last node to point to `new`.
				
	Parameters:
				lst (IN/OUT) -- Double pointer to the head of the list. If the 
				               list is empty, the new node becomes the head.
				new (IN) -- The new node to be added to the end of the list.

	Returns:	None (void).

	Notes:		If `lst` or `new` is `NULL`, the function does nothing. If the 
				list is empty (`*lst` is `NULL`), `new` becomes the first node 
				of the list. Ensure `lst` and `new` are valid pointers before 
				calling this function to avoid undefined behavior.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
