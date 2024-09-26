/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:57:58 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/27 01:55:41 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*══|ft_lstclear|═══════════════════════════════════════════════════════════*

	Purpose:	Clears an entire linked list, applying a function `del` 
				to each node's content to free associated resources, then 
				deallocates the node itself. This function is typically 
				used to clean up a list and free all its nodes.
				
	Parameters:
				lst (IN/OUT) -- Double pointer to the head of the list. 
				               After the operation, `*lst` is `NULL`.
				del (IN) -- A function to apply to each node's content to 
				              free resources.

	Returns:	None (void).

	Notes:		If `lst` or `del` is `NULL`, the function does nothing.

*════════════════════════════════════════════════════════════════════════════*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
